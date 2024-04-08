#pragma once

#include "Utilities/Typedefs.h"
#include "Arduino.h"
#include <vector>

/**
 * Configuration constants for used for setup.
 */

// Include bluetooth gamepad support 
#define BT_CONTROLLER
// Include mouth animation (experimental)
//#define ENABLE_ANIMATED_MOUTH

namespace Config {
    // Pin numbers for components
    namespace Pins {
        const u8 
        // Built-in LED
        LED_BUILTIN = 2,
        // Main outer display
        MATRIX_DIN = 23,
        MATRIX_CS = 5,
        MATRIX_CLK = 18,
        // Infrared (boop) sensor
        BOOP_DIGITAL = 19,
        BOOP_ANALOG = 39,
        // Heads up display
        HUD_SCL = 22,
        HUD_SDA = 21,
        // Microphone
        MIC = 26,
        // Fan PWM control
        FAN_PWM = 16;
    }

    namespace Displays {
        // Positions of LED matrixes, used as unique identifier
        const u8 
        POS_EYE_L =     96,    // eye left
        POS_EYE_R =     0,     // eye right
        POS_MOUTH_L =   64,    // mouth left
        POS_MOUTH_R =   16,    // mouth right
        POS_NOSE_L =    56,    // nose left
        POS_NOSE_R =    48;    // nose left

        // Display Bitmasks (identifier)
        // Leave these unless you want to remap displays
        const DisplayBitmask
        EYE_L =         1,        // eye left
        EYE_R =         1 << 1,   // eye right
        MOUTH_L =       1 << 2,   // mouth left
        MOUTH_R =       1 << 3,   // mouth right
        NOSE_L =        1 << 4,   // nose left
        NOSE_R =        1 << 5,   // nose right
        BITMAPBUFFER =  1 << ((sizeof(DisplayBitmask) * 8) - 1),  // bitmap buffer, reserves the leftmost bit
        // Display Bitmask groups
        DEFAULT_DISPLAY = EYE_L,    // default display, set this to any SINGLE display that's in use as some effects depend on it
        EYES = EYE_L | EYE_R,
        NOSE = NOSE_L | NOSE_R,
        MOUTH = MOUTH_L | MOUTH_R,
        LEFT_SIDE = EYE_L | NOSE_L | MOUTH_L,
        RIGHT_SIDE = EYE_R | NOSE_R | MOUTH_R,
        ALL = EYE_L | EYE_R | NOSE_L | NOSE_R | MOUTH_L | MOUTH_R;
    }

    namespace Bluetooth {
        // Bluetooth gamepad name 
        // static const char* DEVICE_NAME = "Game-Pad";
        //static const char* DEVICE_NAME = "MOCUTE-052Fe-AUTO";
        //static const char* DEVICE_NAME = "MOGA XP5-X Plus  ";
        static const char* DEVICE_NAME = "ESP32 Keyboard";
    }

    // EEPROM addresses for saving certain settings, changing this will likely mess up your settings
    namespace EEPROM {
        const u8
        SIZE = 16,
        MATRIX_BRIGHTNESS = 0,
        BOOP_SENSOR = 1,
        AUTO_BLINK = 2,
        FAN_PWM_SPEED = 3,
        MATRIX = 4,
        LEDSTRIP = 5, //ws2812 led pin   MH-ET GPIO5 is SPI-CS pin
        BOOP_TRIGGER_MULTIPLIER = 6,
        RARE_TRANSITION_CHANCE = 7,
        ANIMATED_MOUTH = 8,
        ANIMATED_MOUTH_NOISE_FLOOR = 9,
        ANIMATED_MOUTH_PEAK_MIN = 10;
    }

    // Miscellaneous settings, best to leave these as is
    const u16 FPS_LIMIT = 120;
    const Timestamp FRAMETIME = 1000000 / FPS_LIMIT;

    // default duration for keyframes
    const Timestamp 
    DEFAULT_KEYFRAME_DURATION = 500 MILLIS,
    DEFAULT_OVERLAY_KEYFRAME_DURATION = 0;

    const u8 
    BOOP_TRIGGER_COUNT = 4,             // how many updates to wait until boop animation triggers
    BOOP_TRIGGERS_MAX = 6,              // maximum value for boop activation (must be higher than activation threshold)
    FAN_INITIAL_SPEED = 127,    // Changed from 255 for testing pwm
    FAN_PWM_CHANNEL = 0,
    FAN_PWM_RESOLUTION = 8;
    const u32 FAN_PWM_FREQUENCY = 25000;
    const i32 DEFAULT_PARTICLE_LIFESPAN = 3 SECONDS;

    const u8 DISPLAY_HEIGHT = 8;        // do NOT touch this >:(
    static const char* VERSION_NUMBER = "v0.3";
}