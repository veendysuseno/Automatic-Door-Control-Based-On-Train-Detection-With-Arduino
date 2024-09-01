#include <Servo.h>      //Library servo
Servo myservo1;         //Deklarasi nama servo
Servo myservo2;         //Deklarasi nama servo

#define in 2            //Sensor IR masuk pada pin D2
#define out 3           //Sensor IR keluar pada pin D3

bool buka = true;
bool sensorIn = false;

void setup() {
  myservo1.attach(10);    //Servo pada pin D10
  myservo2.attach(11);    //Servo pada pin D11
  pinMode(in, INPUT);     //Setting I/O
  pinMode(out, INPUT);
  myservo1.write(90);
  myservo2.write(90);
}

void loop() {
  int nilai_in = digitalRead(in);     //Baca sensor
  int nilai_out = digitalRead(out);

  if(nilai_in == LOW && buka){          //Jika sensor IN bernilai LOW dan Servo terbuka, maka
    myservo1.write(0);
    myservo2.write(0);
    sensorIn = true;
    buka = false;
  }
  else if (nilai_out == LOW && buka){   //Jika sensor OUT bernilai LOW dan Servo terbuka, maka
    myservo1.write(0);
    myservo2.write(0);
    sensorIn = false;
    buka = false;
  }

  if(!buka && nilai_out == LOW && sensorIn){
    myservo1.write(90);
    myservo2.write(90);
    buka = true;
    delay(3000);
  }
  else if(!buka && nilai_in == LOW && !sensorIn){
    myservo1.write(90);
    myservo2.write(90);
    buka = true;
    delay(3000);
  }
}
