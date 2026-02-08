#pragma once

class Pin
{
  private:
    const unsigned long int number;
    const unsigned long int mode;
    int state;
    const char * name;
  public:
    /**
     * @brief Construct a new Pin object
     * @param number The pin number
     * @param mode The pin mode (INPUT, OUTPUT, etc.)
     * @param name Optional human readable name for logging
     */
    Pin(const unsigned long int number, const unsigned long int mode, const char * name = nullptr);
    void turnOn() const;
    void turnOff() const;
};