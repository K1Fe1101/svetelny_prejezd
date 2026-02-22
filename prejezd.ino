#include <FastLED.h>

#define LED_PIN     4
#define POCET_LED    8
#define JAS_LED  8
CRGB leds[POCET_LED];

int levy = 3;
int pravy = 2;

enum Stavy {
  BILA,
  CERVENA,
  CERNA,
};

Stavy stav = Stavy::BILA;

enum Smery {
  ZLEVA,
  ZPRAVA
};

Smery smer ;

void setup() {
  pinMode(levy, INPUT);
  pinMode(pravy, INPUT);
  Serial.begin(9600);
  delay(1000);
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, POCET_LED);
  FastLED.setBrightness(JAS_LED);
}

void blik(int cisloLed, int barva1, int barva2, int barva3) {
    leds[cisloLed] = CRGB(barva1, barva2, barva3);
    FastLED.show();
    delay(100);
    leds[cisloLed] = CRGB(0, 0, 0);
    FastLED.show();
    delay(100);
  
}

void stavyAutomat(){
    switch(stav) {
      case Stavy::BILA:
       blik(5, 255, 255, 255);
       blik(7, 255, 255, 255);
      case Stavy::CERVENA:
       blik(6, 255, 0, 0);
      case Stavy::CERNA:
       blik(5, 0, 0, 0);
       blik(6, 0, 0, 0);
       blik(7, 0, 0, 0);
    }
    }

void smerJizdy(){
  if ((digitalRead(levy) == 0) && (digitalRead(pravy) == 1)) {
    smer = Smery::ZLEVA;
  }
  else if ((digitalRead(levy) == 1) && (digitalRead(pravy) == 0)) {
    smer = Smery::ZPRAVA;
  }}

void dalsiStav(int left, int right) {
  int l = left;
  int p = right;
  if (digitalRead(left) == 0 && digitalRead(right) == 1 && stav == Stavy::BILA)
      {stav = Stavy::CERVENA; Serial.print("smer: ");}
  else if (digitalRead(left) == 1 && digitalRead(right) == 0 && stav == Stavy::CERVENA)
      {stav = Stavy::CERNA;}
  else if (digitalRead(left) == 1 && digitalRead(right) == 1 && stav == Stavy::CERNA)  
      {stav = Stavy::BILA;}
}

void smeryAutomat(){
  smerJizdy();
  switch(smer){
    case Smery::ZLEVA:
      stavyAutomat();
      dalsiStav(levy, pravy);
      break;
    case Smery::ZPRAVA:
      stavyAutomat();
      dalsiStav(pravy, levy);
      break;}
  }

void loop() {
  if (digitalRead(levy) == 1 && digitalRead(pravy) == 1){
    blik(5, 255, 255, 255);
    blik(7, 255, 255, 255);
  }
  else{
    smeryAutomat();
  }
}
