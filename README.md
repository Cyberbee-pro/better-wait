# better_wait

A lightweight, non-blocking `millis()` timer and periodic interval wrapper for Arduino and ESP32 projects.

## Index
- [Usage](#usage)
  - [Installation (`platformio.ini`)](#installation-platformioini)
  - [Quick Start Example](#quick-start-example)
- [What It Does](#what-it-does)
- [API Reference](#api-reference)

---

## Usage

### Installation (`platformio.ini`)
Add `better_wait` to your project's `lib_deps`:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps =
    Cyberbee-pro/better_wait

```
Quick Start Example

```C++
#include <Arduino.h>
#include <bwait.h>

// Create a non-blocking 500ms interval timer
b_wait blinkTimer(500);
bool ledState = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  blinkTimer.start();
}

void loop() {
  // Returns true every 500ms without blocking the main loop
  if (blinkTimer.is_Time_Enlapsed()) {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
}
```

What It Does

better_wait replaces blocking delay() calls with an object-oriented millis() state tracker. Once started, checking is_Time_Enlapsed() evaluates whether the target duration has passed—and automatically resets the timestamp upon firing so it works out of the box for repeating intervals, polling loops, and state-machine timeouts.API ReferenceMethodDescriptionb_wait(int wait_time)Initializes the timer with a target duration in milliseconds (starts inactive).void start()Activates the timer and snapshots the current millis() timestamp.void stop()Deactivates the timer (is_Time_Enlapsed() will return false).void reset_en_time()Resets the internal start timestamp to the current millis().bool GetIsActive()Returns true if the timer is currently running.bool is_Time_Enlapsed()Returns true once the wait duration has passed and automatically resets the start time for the next cycle.

