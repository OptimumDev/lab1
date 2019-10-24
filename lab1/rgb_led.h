#pragma once

class rgb_led {
  public:
    rgb_led() { }
  
    rgb_led(int red_pin, int green_pin, int blue_pin) {
      red_pin = red_pin;
      green_pin = green_pin;
      blue_pin = blue_pin;

      pinMode(red_pin, OUTPUT);
      pinMode(green_pin, OUTPUT);
      pinMode(blue_pin, OUTPUT);

      set_light(0);
    }

    void set_rgb(int r, int g, int b) {
      analogWrite(red_pin, 255 - r);
      analogWrite(green_pin, 255 - g);
      analogWrite(blue_pin, 255 - b);
    }

    void set_light(int power) {
      set_rgb(power, power, power);
    }

  private:
    int red_pin;
    int green_pin;
    int blue_pin;
};
