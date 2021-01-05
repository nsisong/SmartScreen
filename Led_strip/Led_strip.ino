#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5
String state;
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(36, 8, PIN,
//  NEO_MATRIX_BOTTOM    +
//  NEO_MATRIX_RIGHT +
//  NEO_MATRIX_ROWS+
//  NEO_MATRIX_COLUMNS +
//  NEO_MATRIX_LEFT+
  NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(255, 255, 0),matrix.Color(0, 0, 255), matrix.Color(255, 0, 255), matrix.Color(0, 255, 255), matrix.Color(255, 255, 255)};

void setup() {
  Serial.begin(9600);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(255);
  matrix.setTextColor(colors[0]);
}

int y    = matrix.width();
int pass = 0;

void loop() {
  while(Serial.available() >0){ // Checks whether data is comming from the serial port
    state = Serial.readString(); // Reads the data from the serial port
    Serial.println(state);  
  }
  matrix.fillScreen(0);
  matrix.setCursor(y, 0);
  matrix.print(state);
 
 
  if(--y < -400
  ) {
    y = matrix.width();

    if(++pass >= 8) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}
//}
