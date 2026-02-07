#pragma once

class Pin
{
  private:
    const unsigned long int number;
    const unsigned long int mode;
    int state;
  public:
    /**
     * @brief Construct a new Pin object
     * @param number The pin number
     * @param mode The pin mode (INPUT, OUTPUT, etc.)
     */
    Pin(const unsigned long int number, const unsigned long int mode);
    void turnOn() const;
    void turnOff() const;
};