#include <SoftwareSerial.h>
#include <ModbusMaster.h>

#define RX_PIN 14 // D6
#define TX_PIN 12 // D5

SoftwareSerial swSerial(RX_PIN, TX_PIN);
ModbusMaster sensor;

unsigned long lasTime = 0;

void setup()
{
  Serial.begin(115200);
  swSerial.begin(9600, SWSERIAL_8N1, RX_PIN, TX_PIN);
  sensor.begin(1, swSerial);
}

void loop()
{
  if ((millis() - lasTime) > 2000)
  {
    readFlow();
    readFlowToday();
    readFlowMonth();
    readVelocity();
    lasTime = millis();
  }
}

void readFlow()
{
  uint8_t j, result;
  uint16_t buf[2];
  uint16_t temp;
  float flow;

  Serial.println("Reading registers");
  result = sensor.readHoldingRegisters(0x0001, 2);

  if (result == sensor.ku8MBSuccess)
  {
    Serial.println("Success! Processing...");
    for (j = 0; j < 2; j++)
    {
      buf[j] = sensor.getResponseBuffer(j);
      Serial.print(buf[j]);
      Serial.print(" ");
    }

    Serial.println("<- done");
    temp = buf[1];
    buf[1] = buf[0];
    buf[0] = temp;
    memcpy(&flow, &buf, sizeof(float));
    Serial.print("Flow is ");
    Serial.println(flow, 6);
  }
  else
  {
    Serial.print("Failure. Code: ");
    Serial.println(result);
  }
}

void readFlowToday()
{
  uint8_t j, result;
  uint16_t buf[2];
  uint16_t temp;
  float flowToday;

  Serial.println("Reading registers");
  result = sensor.readHoldingRegisters(0x007D, 2);

  if (result == sensor.ku8MBSuccess)
  {
    Serial.println("Success! Processing...");
    for (j = 0; j < 2; j++)
    {
      buf[j] = sensor.getResponseBuffer(j);
      Serial.print(buf[j]);
      Serial.print(" ");
    }

    Serial.println("<- done");
    temp = buf[1];
    buf[1] = buf[0];
    buf[0] = temp;
    memcpy(&flowToday, &buf, sizeof(float));
    Serial.print("Flow Today is ");
    Serial.println(flowToday, 6);
  }
  else
  {
    Serial.print("Failure. Code: ");
    Serial.println(result);
  }
}

void readFlowMonth()
{
  uint8_t j, result;
  uint16_t buf[2];
  uint16_t temp;
  float flowMonth;

  Serial.println("Reading registers");
  result = sensor.readHoldingRegisters(0x007F, 2);

  if (result == sensor.ku8MBSuccess)
  {
    Serial.println("Success! Processing...");
    for (j = 0; j < 2; j++)
    {
      buf[j] = sensor.getResponseBuffer(j);
      Serial.print(buf[j]);
      Serial.print(" ");
    }

    Serial.println("<- done");
    temp = buf[1];
    buf[1] = buf[0];
    buf[0] = temp;
    memcpy(&flowMonth, &buf, sizeof(float));
    Serial.print("Flow Month is ");
    Serial.println(flowMonth, 6);
  }
  else
  {
    Serial.print("Failure. Code: ");
    Serial.println(result);
  }
}

void readVelocity()
{
  uint8_t j, result;
  uint16_t buf[2];
  uint16_t temp;
  float velocity;

  Serial.println("Reading registers");
  result = sensor.readHoldingRegisters(0x0005, 2);

  if (result == sensor.ku8MBSuccess)
  {
    Serial.println("Success! Processing...");
    for (j = 0; j < 2; j++)
    {
      buf[j] = sensor.getResponseBuffer(j);
      Serial.print(buf[j]);
      Serial.print(" ");
    }

    Serial.println("<- done");
    temp = buf[1];
    buf[1] = buf[0];
    buf[0] = temp;
    memcpy(&velocity, &buf, sizeof(float));
    Serial.print("Velocity is ");
    Serial.println(velocity, 6);
  }
  else
  {
    Serial.print("Failure. Code: ");
    Serial.println(result);
  }
}
