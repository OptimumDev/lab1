#include "rgb_led.h"

#define FIRST_LED_PIN 2
#define LEDS_COUNT 6

#define LIGHT_STEP_DELAY_TIME 2

void set_light_for_opposite_leds(int led_number, int light_power);
void flash_lights(int current_number);

const int LEDS_ARRAY_MIDDLE = LEDS_COUNT / 2;

const rgb_led leds[LEDS_COUNT];
int current_powers[LEDS_COUNT];

void setup() {
  for (int i = 0; i < LEDS_COUNT; i++) {
    leds[i] = rgb_led(FIRST_LED_PIN + i);
  }

  for (int i = 0; i < LEDS_COUNT / 2; i++) {
    int current_power = i * 320 / (LEDS_COUNT / 2);
    current_powers[i] = current_power;
    current_powers[i + LEDS_COUNT / 2] = current_power;
  }

  Serial.begin(115200);
}

void loop() {
  update_lights();
  update_powers();
  delay(LIGHT_STEP_DELAY_TIME);
}

void update_lights() {
  for (int i = 0; i < LEDS_COUNT; i++) {
    int power = long(current_powers[i] - 160) * (current_powers[i] - 160) / 100;
    power = power < 256 ? power : 255;
    leds[i].set_light(power);
    Serial.print(power);
    Serial.print(" ");
  }
  Serial.println("");
}

void update_powers() {
    for (int i = 0; i < LEDS_COUNT / 2; i++) {
      int current_power = (current_powers[i] + 1) % 320;
      current_powers[i] = current_power;
      current_powers[i + LEDS_COUNT / 2] = current_power;
  }
}
