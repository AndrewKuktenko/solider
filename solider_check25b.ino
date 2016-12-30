int port = 0;
int aSize = 100;
int PWMpin = 3;
int n = 0;
//int temp = 0;
int arr[100];
int analogPort=A0;


void setup() {
  Serial.begin(9600);
  pinMode(PWMpin, OUTPUT);
  Serial.println("Enter value between 0 and 255");
}


float average(int arr[], int arrSize)
{
  float res;
  for (int i = 0; i <=arrSize; i++) {
    res = res + arr[i];
  }
  return res/arrSize;
}





void loop() {
  arr[n] = analogRead(analogPort);  
  n++;

  if(n==100)
  {
    n=0;
    float res = average(arr,100);
    delay(500);
    Serial.println(String(res));
    pwmFunction(PWMpin); 
  }

}

void pwmFunction(int pin) {
  if  (Serial.available() > 0) {
    int val = Serial.parseInt();
    if(val >= 0 && val <= 255) {
      analogWrite(pin, val);
      Serial.print("Value is: ");
      Serial.println(val);     
    }
  }
}



