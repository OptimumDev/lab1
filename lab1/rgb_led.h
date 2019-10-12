#pragma once

class rgb_led {
  public:
    rgb_led(int red_pin, int green_pin, int blue_pin) {
      this.red_pin = red_pin;
      this.green_pin = green_pin;
      this.blue_pin = blue_pin;

      pinMode(red_pin, OUTPUT);
      pinMode(green_pin, OUTPUT);
      pinMode(blue_pin, OUTPUT);

      turn_off();
    }

    void set_rgb(int r, int g, int b) {
      analogWrite(red_pin, 255 - r);
      analogWrite(green_pin, 255 - g);
      analogWrite(blue_pin, 255 - b);
    }

    void turn_on() {
      set_rgb(255, 255, 255);
    }

    void turn_off() {
      set_rgb(0, 0, 0);
    }

    void flash(int duration) {
      turn_on();
      delay(duration);
      turn_off();
    }

  private:
    int red_pin;
    int green_pin;
    int blue_pin;
}
