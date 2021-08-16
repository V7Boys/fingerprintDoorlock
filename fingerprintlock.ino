String readString;
#define relay1 3    //Connect relay1 to pin D3


void setup()
{
  Serial.begin(9600);           //Set rate for communicating with phone
  pinMode(relay1, OUTPUT);      //Set relay1 as an output
  digitalWrite(relay1, LOW);     //Switch relay1 off
}
void loop()
{
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
                  
     if(readString == "f success"){
        digitalWrite(relay1, HIGH);
        delay(3000);
        digitalWrite(relay1, LOW);
      }
      readString="";
    }
