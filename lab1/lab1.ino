#include "rgb_led.h"

#define FIRST_LED_PIN 1
#define LEDS_COUNT 6

void set_light_for_opposite_leds(int led_number, int light_power);
void flash_lights(int current_number);

const int LEDS_ARRAY_MIDDLE = LEDS_COUNT / 2;

const rgb_led leds[LEDS_COUNT];

void setup() {
  for (int i = 0; i < LEDS_COUNT; i++) {
    int current_red_pin = FIRST_LED_PIN + i * 3;
    leds[i] = rgb_led(current_red_pin, current_red_pin + 1, current_red_pin + 2);
  }
}

void loop() {
  for (int i = 0; i < LEDS_ARRAY_MIDDLE; i++) {
    flash_lights(i);
  }
}

void flash_lights(int current_number) {
  for (int i = 0; i < 255; i++)
    set_light_for_opposite_leds(current_number, i);
  
  for (int i = 255; i >= 0; i--)
    set_light_for_opposite_leds(current_number, i);
}

void set_light_for_opposite_leds(int led_number, int light_power) {
  leds[led_number].set_light(light_power);
  leds[led_number + LEDS_ARRAY_MIDDLE].set_light(light_power);
}
