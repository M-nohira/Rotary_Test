//pin assign
#define TERMINAL_A 2
#define TERMINAL_B 3
#define LED 4
//Delay Time
#define DELAY_SEC 50

int lastTerA = 1;
int posEdgeA_B;
int negEdgeA_B;

int cnt = 500;
int oldcnt = 500;




void setup()
{
    Serial.begin(9600);
    Serial.println("Start Rotary Test");
    pinMode(TERMINAL_A,INPUT);
    pinMode(TERMINAL_B,INPUT);

    pinMode(LED,OUTPUT);

}

//LOW IS 1
//HIGH IS 0
//
void loop()
{
    int terA = digitalRead(TERMINAL_A);
    if( (lastTerA == terA)) return;
    lastTerA = terA;
    if( terA == 0 ) 
    {
        posEdgeA_B = digitalRead(TERMINAL_B);
        negEdgeA_B = posEdgeA_B;
    }
    if( terA == 1 )
    {
        negEdgeA_B = digitalRead(TERMINAL_B);
    }
    if(negEdgeA_B == posEdgeA_B) return;
    if(posEdgeA_B == 0) 
    {
        Serial.println("CCW");
        digitalWrite(LED,0);
    }
    if(posEdgeA_B == 1) 
    {
        Serial.println("CW");
        digitalWrite(LED,1);
    }
        
}
