

//com3

String veri = "";
boolean durum = false;
int sayac=0;
int ortsicaklik=0;
int sensitivity = 66;
String keke="";
int atoplam=0;
int dizi[]={};
int enkucuk;
void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
}
void loop()
{

  Serial.println(Serial3.read());
 
  if (durum)
  {

    Serial.print(veri); 
    Serial3.write(enkucuk);
    sayac=sayac+1;
    veri = "";
    keke="";
  if(sayac==17)
  {
    Serial.println("------------------------------------");
    akim(); 
    Serial.println("------------------------------------");
    Serial.print(atoplam);
    //Serial3.write(atoplam);
    Serial.println("------------------------------------");
    sicaklik1();
    Serial.print("ortalama sicaklik = "); // shows the voltage measured 
    Serial.println(ortsicaklik/4); 
   ortsicaklik=0;
   sayac=0;
   atoplam=0;
  }
    durum = false;
  }  
}
void serialEvent()
{
    
  while (Serial1.available())
  {
    char gelen = char(Serial1.read());
    veri += gelen;
    if (gelen == '\n')
    { 
      durum = true;  
      while(Serial2.available())
  {
    char gelen = char(Serial2.read());
    keke += gelen;
    if (gelen == '\n')
    { 
     int  toplam = keke.toInt();
   
     atoplam+=toplam;  
    
    }
  }
    }
  }
 
}
void akim(){
 for(int i=0;i<4;i++){
const int analogchannel = i; //Connect current sensor with A0 of Arduino
int sensitivity = 66; // use 100 for 20A Module and 66 for 30A Module
int adcvalue1= 0;
int offsetvoltage = 2400; 
double Voltage = 0; //voltage measuring
double akim = 0;// Current measuring
 adcvalue1 = analogRead(analogchannel);//reading the value from the analog pin
 Voltage = (adcvalue1 / 1024.0) * 5000; // Gets you mV
 akim = ((Voltage - offsetvoltage) / sensitivity);
 Serial.print("akim");
 Serial.print(i+17); 
 Serial.print("=  ");// shows the voltage measured 
 Serial.println(akim,3);// the '3' after voltage allows you to display 3 digits after decimal point
 atoplam=atoplam+akim;

 /* toplam =toplam+akim;
  int yuzde;
   Serial1.print("toplam akım");
    Serial1.println(toplam);
  yuzde=(3000-(toplam))/30;
  Serial1.print("yüzde");
    Serial1.println(yuzde);
 */
  }
}
    
void sicaklik1()
{
  for(int i=4; i<=7; i++)
  {
const int analogPin = i;
float gerilimDeger = 0;
float sensorDeger = 0;
float sicaklikDeger = 0;
 sensorDeger = analogRead(analogPin); 
 gerilimDeger = (sensorDeger/1023)*5000;
 sicaklikDeger = gerilimDeger / 10.0;
 Serial.print("Sıcaklık:");
 Serial.print(i-3);
 Serial.print("         ");
 Serial.println(sicaklikDeger);
 //kjhkjortsicaklik+=sicaklikDeger;
 dizi[i-4]=sicaklikDeger;
 if(i==7)
 {
  enkucuk=dizi[0];
  for(int i=0; i<4; i++)
  {
    if(enkucuk<dizi[i])
    {
      enkucuk=dizi[i];
    }
  }
  Serial.print("en buyuk sayi");
  Serial.println(enkucuk);
 // Serial3.println(enkucuk);
 }
}}

