int led1 = D7; // The on-board LED
int led2 = A5; // The Red LED
int led3 = A4; // The Yellow LED

void waveHandler(const char *event, const char *data);

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", waveHandler);
}

// Procedure to Flash two of the three lights in the lights
void flash_lights(char led_x, char led_y)
{
    digitalWrite(led_x, HIGH);
    digitalWrite(led_y, HIGH);
    delay(1000);

    digitalWrite(led_x, LOW);
    digitalWrite(led_y, LOW);
    delay(1000);

    digitalWrite(led_x, HIGH);
    digitalWrite(led_y, HIGH);
    delay(1000);

    digitalWrite(led_x, LOW);
    digitalWrite(led_y, LOW);
    delay(1000);

    digitalWrite(led_x, HIGH);
    digitalWrite(led_y, HIGH);
    delay(1000);

    digitalWrite(led_x, LOW);
    digitalWrite(led_y, LOW);
    delay(1000);
}

void waveHandler(const char *event, const char *data)
{
    // Flash if 'wave' is received
    if (strcmp(data, "wave") == 0)
    {
        flash_lights(led1,led2);
    }
    // Flash if 'pat' is received
    else if (strcmp(data, "pat") == 0)
    {
        flash_lights(led1,led3);
    }
    else
    {
        // Any other publish events will result in nothing happening
    }
    
}
