#pragma once
// HX711
#define HX711_LOADCELL_DOUT_PIN     2
#define HX711_LOADCELL_SCK_PIN      3
#define HX711_LOADCELL_OFFSET       50682624
#define HX711_LOADCELL_DIVIDER      5895655
#define HX711_AVERAGE_SAMPLE_DATA   10
// SD Card
#define SDCARD_CS_PIN               10
// Serial
#define SERIAL_BAUDRATE             115200
// Led Notification
#define PIN_LED_NOTIFICATION        7
// RTC
#define INTERVAL_ALARM              10 // in minute
#define ALARM_TO_SECOND             60 * INTERVAL_ALARM
#define ALARM_INTERUPT_PIN          5
// INTERUPT PIN
#define RTC_ALARM_PIN               2
// RELAY
#define RELAY_PIN                   4
