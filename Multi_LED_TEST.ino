#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define PIN 8
#define LED_PORT 13
#define BT_RX 11
#define BT_TX 3
// TX(RBT-001) <-> 11(Arduino)
// RX(RBT-001) <-> 12(Arduino)

#define LED_WIDTH 32
#define LED_HEIGHT 12

SoftwareSerial btSerial(BT_RX, BT_TX);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(384, PIN, NEO_GRB + NEO_KHZ800);

int index = 0;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  // Initialize LED port 
  pinMode(LED_PORT, OUTPUT);
  digitalWrite(LED_PORT, LOW);
  // Initialize internal serial port (with PC)
  Serial.begin(9600);
  // Initialize software serial port (with Bluetooth)
  btSerial.begin(9600);
//  logo();
  rainbow(2);
  reset();
}
/*
void logo() {
  int logo_int_0[77] = {0, 0, 38, 86, 79, 14, 0, 0, 2, 4, 5, 1, 0, 15, 40, 40, 40, 0, 0, 0, 0, 38, 40, 40, 22, 1, 54, 35, 37, 38, 55, 8, 21, 40, 39, 3, 0, 0, 0, 0, 0, 0, 0, 39, 40, 4, 0, 0, 8, 40, 40, 40, 40, 40, 40, 35, 0, 0, 0, 15, 72, 92, 62, 3, 0, 0, 0, 6, 40, 40, 40, 40, 25, 0, 0, 40, 0};
  int logo_int_1[77] = {0, 141, 255, 255, 255, 235, 75, 0, 57, 229, 231, 115, 0, 101, 255, 255, 255, 95, 0, 0, 40, 255, 255, 255, 142, 1, 249, 94, 216, 133, 239, 7, 109, 255, 254, 21, 0, 0, 0, 0, 0, 0, 55, 255, 255, 159, 0, 0, 49, 255, 255, 255, 255, 255, 255, 237, 0, 0, 131, 238, 255, 255, 255, 225, 95, 0, 0, 44, 255, 255, 255, 255, 252, 209, 86, 0, 0};
  int logo_int_2[77] = {132, 255, 255, 241, 255, 255, 255, 15, 35, 255, 255, 140, 0, 103, 255, 255, 255, 181, 0, 0, 120, 255, 255, 255, 145, 0, 251, 90, 232, 148, 243, 6, 98, 255, 255, 21, 0, 0, 0, 0, 0, 0, 158, 255, 255, 255, 19, 0, 54, 255, 255, 255, 255, 255, 255, 239, 0, 180, 255, 255, 255, 255, 255, 255, 255, 146, 0, 39, 255, 255, 255, 255, 255, 255, 255, 26, 0};
  int logo_int_3[77] = {233, 255, 231, 0, 73, 221, 234, 52, 19, 255, 255, 128, 0, 98, 255, 255, 255, 235, 0, 0, 200, 255, 255, 255, 138, 1, 249, 101, 235, 143, 240, 6, 100, 255, 247, 20, 0, 0, 0, 0, 0, 1, 236, 255, 255, 255, 97, 0, 12, 67, 73, 240, 255, 210, 67, 43, 119, 255, 255, 205, 62, 28, 87, 237, 255, 255, 26, 2, 255, 255, 158, 67, 147, 254, 255, 172, 0};
  int logo_int_4[77] = {222, 255, 245, 130, 9, 0, 0, 5, 61, 255, 255, 128, 0, 98, 255, 217, 224, 255, 25, 0, 255, 230, 202, 255, 138, 4, 247, 106, 233, 144, 240, 7, 111, 255, 247, 20, 0, 0, 0, 0, 0, 93, 255, 227, 214, 255, 194, 0, 0, 0, 0, 232, 255, 185, 0, 0, 223, 255, 229, 0, 0, 0, 0, 44, 253, 255, 140, 1, 255, 255, 106, 0, 0, 202, 255, 228, 0};
  int logo_int_5[77] = {83, 255, 255, 255, 244, 130, 0, 0, 69, 255, 255, 128, 0, 98, 255, 184, 135, 255, 85, 11, 255, 160, 165, 255, 138, 11, 247, 106, 235, 142, 237, 11, 128, 255, 247, 20, 0, 0, 0, 0, 0, 208, 255, 126, 86, 255, 255, 33, 0, 0, 8, 235, 255, 194, 0, 19, 255, 255, 137, 0, 0, 0, 0, 0, 208, 255, 194, 33, 251, 255, 114, 0, 27, 229, 255, 183, 0};
  int logo_int_6[77] = {0, 30, 177, 255, 255, 255, 219, 0, 43, 255, 255, 128, 0, 98, 255, 201, 56, 255, 178, 128, 255, 96, 158, 255, 138, 14, 247, 101, 237, 142, 237, 17, 135, 255, 247, 20, 0, 0, 0, 0, 55, 255, 255, 12, 0, 248, 255, 147, 0, 0, 8, 235, 255, 194, 0, 28, 255, 255, 125, 0, 0, 0, 0, 0, 199, 255, 199, 39, 249, 255, 222, 194, 249, 255, 246, 42, 0};
  int logo_int_7[77] = {43, 16, 4, 59, 187, 255, 255, 73, 10, 255, 255, 128, 0, 98, 255, 229, 2, 215, 255, 252, 255, 22, 178, 255, 138, 14, 247, 100, 238, 145, 236, 32, 136, 255, 246, 0, 0, 0, 0, 0, 152, 255, 252, 81, 64, 228, 255, 242, 7, 0, 8, 235, 255, 194, 0, 2, 236, 255, 211, 0, 0, 0, 0, 14, 245, 255, 156, 8, 255, 255, 255, 255, 255, 252, 44, 0, 0};
  int logo_int_8[77] = {255, 255, 203, 0, 46, 255, 255, 101, 8, 255, 255, 128, 0, 98, 255, 241, 0, 124, 255, 255, 195, 0, 209, 255, 138, 17, 249, 102, 236, 145, 239, 54, 136, 255, 248, 39, 19, 21, 2, 0, 238, 255, 255, 255, 255, 255, 255, 255, 81, 0, 9, 235, 255, 194, 0, 0, 150, 255, 255, 171, 18, 0, 37, 208, 255, 255, 44, 0, 255, 255, 187, 142, 255, 254, 88, 0, 0};
  int logo_int_9[77] = {215, 255, 255, 197, 223, 255, 255, 33, 22, 255, 255, 128, 0, 99, 255, 248, 0, 50, 255, 255, 118, 0, 218, 255, 140, 21, 252, 100, 235, 144, 240, 62, 138, 255, 255, 251, 249, 251, 12, 52, 255, 255, 230, 210, 210, 208, 255, 255, 173, 0, 5, 238, 255, 196, 0, 0, 19, 226, 255, 255, 241, 210, 255, 255, 255, 185, 0, 31, 255, 255, 97, 0, 196, 255, 254, 16, 0};
  int logo_int_10[77] = {35, 227, 255, 255, 255, 255, 143, 0, 69, 255, 255, 151, 0, 112, 255, 255, 0, 0, 255, 255, 33, 0, 250, 255, 157, 27, 252, 95, 235, 148, 241, 64, 155, 255, 255, 255, 255, 255, 55, 199, 255, 255, 34, 0, 0, 0, 215, 255, 255, 29, 0, 255, 255, 221, 0, 0, 0, 15, 183, 255, 255, 255, 255, 255, 143, 0, 0, 50, 255, 255, 148, 0, 40, 255, 255, 208, 0};
  int logo_int_11[77] = {0, 10, 104, 141, 133, 71, 0, 0, 38, 144, 146, 72, 0, 35, 95, 86, 0, 0, 84, 91, 0, 0, 79, 96, 48, 53, 247, 98, 233, 145, 237, 62, 47, 94, 90, 90, 90, 89, 36, 87, 94, 80, 0, 0, 0, 0, 46, 94, 100, 30, 0, 83, 95, 68, 0, 0, 0, 0, 0, 63, 126, 142};

  for(int j=0; j < 77 - 32; j++) {
    for(int h = 0; h < 12; h++) {
      for(int w = 0; w < 32; w++) {
        int color = 0;
        switch(w) {
          case 0:
            color = logo_int_0[w + j];
            break;
          case 1:
            color = logo_int_1[w + j];
            break;
          case 2:
            color = logo_int_2[w + j];
            break;
          case 3:
            color = logo_int_3[w + j];
            break;
          case 4:
            color = logo_int_4[w + j];
            break;
          case 5:
            color = logo_int_5[w + j];
            break;
          case 6:
            color = logo_int_6[w + j];
            break;
          case 7:
            color = logo_int_7[w + j];
            break;
          case 8:
            color = logo_int_8[w + j];
            break;
          case 9:
            color = logo_int_9[w + j];
            break;
          case 10:
            color = logo_int_10[w + j];
            break;
          case 11:
            color = logo_int_11[w + j];
            break;
        }
        strip.setPixelColor(w + h * 32, strip.Color(color,0,0));
      }
    }
    strip.show();
    delay(100);
  }
}
*/
void loop() {
  char c;
  char str[LED_WIDTH * LED_HEIGHT]; // 数字（文字列）の受信用配列
  strip.show();
  btSerial.write("Start Client\n");
  recvStr(str);
  strip.show();
  int r = 0;
  int g = 0;
  int b = 0;  

  int counter = 0;
  boolean reset_flag = 0;
  btSerial.write(index);
  for(int j=0; j<LED_WIDTH * LED_HEIGHT * 3; j++) {
    if(str[j] == '\0' || str[j] == '\n') {
      btSerial.write("break\n");      
      break;
    } else if(str[j] == 'z') {
      btSerial.write("reset index\n");
      reset_flag = 1;
      break;
    } else {
      if(j % 3 == 0) {
        r = str[j] - 48;
        btSerial.write(str[j]);
      } else if (j % 3 == 1) {
        g = str[j] - 48;
        btSerial.write(str[j]);
      } else {
        b = str[j] - 48;
        btSerial.write(str[j]);
        strip.setPixelColor((j-2) / 3 + index , strip.Color(r,g,b));
        counter++;
      }
    }
  }
  
  index += counter;
  if (index > LED_WIDTH * LED_HEIGHT) index -= LED_WIDTH * LED_HEIGHT;
  if (reset_flag == 1) {
    index = 0;
    reset();
  } else {
    strip.show();
  }
  delay(2);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<16; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel8((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void reset() {
  for(int j=0; j<strip.numPixels(); j++) {
        strip.setPixelColor(j, strip.Color(0,0,0));
  }
  strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel8(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3 / 8, (255 - WheelPos * 3) / 8, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color((255 - WheelPos * 3) / 8, 0, WheelPos * 3 / 8);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3 / 8, (255 - WheelPos * 3) / 8);
  }
}

void recvStr(char *buf)
{
  int i = 0;
  char c;
  while (1) {
    if (btSerial.available()) {
      c = btSerial.read();
      buf[i] = c;
      if (c == '\0' || c == '\n') break;
      i++;
    }
  }
  buf[i] = '\0';
}

