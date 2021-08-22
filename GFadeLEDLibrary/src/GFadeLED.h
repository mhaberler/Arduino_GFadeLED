#ifndef FadeLED_h
#define FadeLED_h

#include <FastLED.h>

struct FadeQueue {
  CRGB startRGB;
  CRGB targetRGB;
  bool useStartColor;
  uint16_t fadeTransitionSteps;
  uint16_t fadeCountdown;
  uint16_t fadeCountup;
};

struct FadeLEDs {
  CRGB currentRGB;
  CRGB targetRGB;
  CRGB stepRGB;
  uint8_t queueTail;
  uint8_t queueHead;
  uint8_t freeQueueElements;
  uint16_t fadeStep;
  uint16_t fadeCountdown;
  uint16_t fadeCountup;
  uint16_t fadeTransitionSteps;
  bool fadeCompleted;
  FadeQueue *fadeQueue;
};

class FadeLED {
  public:
    FadeLED();
    int numLeds;
    int queueLength;
    CRGB *_leds;
    FadeLEDs *fadeLEDs;
    void addLeds(CRGB _leds[], int _numLeds, int queueLength);
    void update(void);
    void clearLed(uint8_t led);
    void clearLeds(void);
    void setBrightness(uint8_t brightness);
    void addFadeToQueue(FadeQueue d, uint8_t led) ;
    bool allQueuesEmpty();
    bool queueEmpty(uint8_t led);

  private:
    void applyNextQueueItem(uint8_t number);
    void updateLEDFade(uint8_t number);
    void setPhysicalLED(uint8_t number);
    void updateLED(uint8_t number);
    void initialiseLED(uint8_t led);
    void initialiseLEDs(void);

};

extern FadeLED fade;

#endif
