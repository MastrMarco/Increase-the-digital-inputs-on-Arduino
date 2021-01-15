#define SH_LO 6
#define CL_OK 4
#define QH    5

long t [3]=                       {0, 0};
long delay_loop [2]=              {300};
int  key[3] =                     {0, 0};

byte data;
char note2sing[9] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H'};

int led = 9;
int led1 = 10;
 
void setup() {
  Serial.begin(9600);
  pinMode(led,  OUTPUT);
  pinMode(led1,  OUTPUT);
  
  pinMode(SH_LO ,OUTPUT);
  pinMode(CL_OK, OUTPUT);
  pinMode(QH  ,INPUT);
}


void loop() {
  
 digitalWrite(SH_LO, LOW);  
 digitalWrite(CL_OK, LOW);  
 digitalWrite(CL_OK, HIGH);  
 digitalWrite(SH_LO, HIGH);
  
 data = shiftIn(QH, CL_OK, MSBFIRST);
  
  for (int n=0; n<=7; n++){ 
      
   if (data & (1 << n) ){
    Serial.println(note2sing[n]);

   if ( n == 0 ){
    if ((millis() - t[0])> delay_loop[0]) {
    key[0] = !key[0];
    t[0] = millis();
    } 
   }
    if ( n == 1 ){
     if ((millis() - t[1])> delay_loop[0]) {
     key[1] = !key[1];
     t[1] = millis();
     } 
    }
   }
  }    
 if (key[0] == HIGH){digitalWrite(led,HIGH);} else {digitalWrite(led,LOW);}
 if (key[1] == HIGH){digitalWrite(led1,HIGH);} else {digitalWrite(led1,LOW);}
}
