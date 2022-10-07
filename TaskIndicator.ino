//设置控制各段的数字IO 脚
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int timeToWait = 9;    //Task灯闪烁多久
int myTask = 2;  //人为设定Task种类，此后需要变成温湿度控制


/*void taskIndicator(int myTask){
  for (int i = 1; i <= timeToWait; i++){
    number();
    delay(1000);
    dark();
    delay(1000);
    
  }
}*/

void zero()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  
}
void one()
{
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  
}
void two()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);
  
}
void three()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,0);
  
}
void four()
{
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  
}
void five()
{
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  
}
void six()
{
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  
}
void seven()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  
}
void eight()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  
}
void nine()
{
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

}
void dark()
{
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
}






void setup()
{
  Serial.begin(9600);
  int i;//定义变量
  for(i = 2;i <= 8;i++)
  pinMode(i,OUTPUT);//设置2～8 引脚为输出模式

  switch (myTask) {
    case 1:
    for (int i = 1; i <= timeToWait; i++){
    one();
    delay(1000);
    dark();
    delay(1000);
    
  }
    break;
    case 2:
    for (int i = 1; i <= timeToWait; i++){
    two();
    delay(1000);
    dark();
    delay(1000);
    
  }
    break;
    case 3:
    for (int i = 1; i <= timeToWait; i++){
    three();
    delay(1000);
    dark();
    delay(1000);
    
  }
    break;
    
  }

  
}




void loop()
{
  
  
}
/*zero();//显示数字1
delay(2000);//延时2s
one();//显示数字2
delay(1000); //延时1s
two();//显示数字3
delay(1000); //延时1s
three();//显示数字4
delay(1000); //延时1s
four();//显示数字5
delay(1000); //延时1s
five();//显示数字6
delay(1000); //延时1s
six();//显示数字7
delay(1000); //延时1s
seven();//显示数字8
delay(1000); //延时1s
eight();
delay(1000);
nine();
delay(1000);*/
