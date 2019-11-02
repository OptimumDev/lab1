#include "rgb_led.h"

#define FIRST_LED_PIN 2
#define LEDS_COUNT 6

#define LIGHT_STEP_DELAY_TIME 15
#define FLASHING_PAUSE_TIME 250

void set_light_for_opposite_leds(int led_number, int light_power);
void flash_lights(int current_number);

const int LEDS_ARRAY_MIDDLE = LEDS_COUNT / 2;

const rgb_led leds[LEDS_COUNT];

void setup() {
  for (int i = 0; i < LEDS_COUNT; i++) {
    leds[i] = rgb_led(FIRST_LED_PIN + i);
  }
}

void loop() {
  for (int i = 0; i < LEDS_ARRAY_MIDDLE; i++) {
    flash_lights(i);
    delay(FLASHING_PAUSE_TIME);
  }
}

void flash_lights(int current_number) {
  for (int i = 0; i < 255; i += 8) {
    set_light_for_opposite_leds(current_number, i);
    delay(LIGHT_STEP_DELAY_TIME);
  }
  
  for (int i = 255; i >= 0; i -= 8) {
    set_light_for_opposite_leds(current_number, i);
    delay(LIGHT_STEP_DELAY_TIME);
  }
}

void set_light_for_opposite_leds(int led_number, int light_power) {
  leds[led_number].set_light(light_power);
  leds[(led_number + LEDS_ARRAY_MIDDLE) % LEDS_COUNT].set_light(light_power);
}
