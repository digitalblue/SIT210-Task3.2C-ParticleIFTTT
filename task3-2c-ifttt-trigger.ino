
// Use blue D7 LED next to the USB connector on the Argon 
const pin_t MY_LED = D7;
const int PAUSE = 500;
int sunlightValue;

// The following line is optional, but recommended in most firmware. It
// allows your code to run before the cloud is connected. In this case,
// it will begin blinking almost immediately instead of waiting until
// breathing cyan,
SYSTEM_THREAD(ENABLED);


void setup()
{
	pinMode(MY_LED, OUTPUT);
	sunlightValue = 20;
}

void blink(int delayTime) {
    // Blink LED on and off
    digitalWrite(MY_LED, HIGH);
    delay(delayTime);
    digitalWrite(MY_LED, LOW);
	
    // Pause after blinking LED
    delay(PAUSE);
}

int mockSunlightRiseFall(int value) {
    // set to restart on value of 40 else continue to rise
    if (value == 40) {
        return 0;
    } else {
        return value + 1;
    }
}

void loop()
{
    sunlightValue = mockSunlightRiseFall(sunlightValue);
    Particle.publish("sunlight", String(sunlightValue));
    
    blink(PAUSE);
    delay(10000);
}