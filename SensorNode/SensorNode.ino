#include <Bridge.h>
#include <Process.h>

#include <DHT.h>
#include <Pir.h>
#include <Photocell.h>
#include <LCDBackpack.h>
#include <SoftwareSerial.h>

#define DHT_PIN          4     // digital
#define DHT_TYPE         DHT22
#define PIR_PIN          2     // digital
#define PHOTOCELL_PIN    0     // analog
#define RX               0
#define TX               5

int timer;
bool motion;
float light;
float tempc;
float humidity;
String POSTUrl;
String POSTResult;

Pir pir(PIR_PIN);
DHT dht(DHT_PIN, DHT_TYPE);
Photocell photocell(PHOTOCELL_PIN);
LCDBackpack lcd(RX, TX);

String gerProcessResult(Process &p);
String getDateTime();
void dataPOST(float &humidity, float &light, float &tempc, bool &motion, String &url, String &result);
void dataPrint(float &humidity, float &light, float &tempc, bool &motion);
void lcdPrint(float &humidity, float &light, float &tempc, bool &motion, LCDBackpack &lcd);

void setup() {
  Serial.begin(9600);
  Bridge.begin();
  dht.begin();
  lcd.quickSetup();
  lcd.setGreen();
  timer = millis();
  POSTUrl = "http://10.0.1.203/SensorDataPost/";
}

void loop() {
  tempc = dht.readTemperature();
  humidity = dht.readHumidity();
  light = photocell.getIntensity();
  motion = pir.isMotion();
  
  dataPOST(humidity, light, tempc, motion, POSTUrl, POSTResult);
  Serial.println(POSTResult);
  dataPrint(humidity, light, tempc, motion);
  lcdPrint(humidity, light, tempc, motion, lcd);
  if (light <= 0.12) {
    lcd.backlightOff();
  }
  else {
    lcd.backlightOn();
  }
  for (int i = 0; (i < 4) && (pir.isMotion() == false) ; i++) {
    delay(1000); 
  }
}

String getProcessResult(Process &p) {
  String result = "";
  while (p.available() > 0) {
    char c = p.read();
    if (c != '\n')
      result += c;
  }
  return result;
}

String getDateTime() {
  String result;
  Process time;
  time.begin("date");
  time.run();
  return getProcessResult(time);
}

void dataPOST(float &humidity, float &light, float &tempc, bool &motion, String &url, String &result) {
  String post = "humidity=";
  post += String(humidity);
  post += "&light=";
  post += String(light);
  post += "&tempc=";
  post += String(tempc);
  post += "&motion=";
  post += (motion == true) ? "1" : "0";
  Process p;
  String cmd = "curl --data '" + post + "' " + url;
  p.runShellCommand(cmd);
  result = getProcessResult(p);
}

void dataPrint(float &humidity, float &light, float &tempc, bool &motion) {
  Serial.println("Time: " + getDateTime());
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Motion: ");
  Serial.println(motion == 1 ? "true" : "false");
  Serial.print("Light: ");
  Serial.println(light);
  Serial.print("Temperature: ");
  Serial.print(tempc);
  Serial.print(" c / ");
  Serial.print(dht.convertCtoF(tempc));
  Serial.println(" f\n");
}

void lcdPrint(float &humidity, float &light, float &tempc, bool &motion, LCDBackpack &lcd) {
  lcd.clearScreen();
  String data = "H:";
  data += String(humidity);
  data += "% L:";
  data += String(light);
  data += " T:";
  data += String(tempc);
  data += "C M:";
  data += motion == 1 ? "true" : "false";
  lcd.print(data);
}
