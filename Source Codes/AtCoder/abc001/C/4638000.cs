using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    double[] x=Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
    string[] dir={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
    string ans_1=dir[(int)((x[0]*10+1125)/2250)%16];
    x[1]=Math.Round(x[1]/60, 1, MidpointRounding.AwayFromZero);
    string ans_2="";
    if(x[1]<=0.2){ans_1="C";ans_2="0";}
    else if(x[1]<=1.5)ans_2="1";
    else if(x[1]<=3.3)ans_2="2";
    else if(x[1]<=5.4)ans_2="3";
    else if(x[1]<=7.9)ans_2="4";
    else if(x[1]<=10.7)ans_2="5";
    else if(x[1]<=13.8)ans_2="6";
    else if(x[1]<=17.1)ans_2="7";
    else if(x[1]<=20.7)ans_2="8";
    else if(x[1]<=24.4)ans_2="9";
    else if(x[1]<=28.4)ans_2="10";
    else if(x[1]<=32.6)ans_2="11";
    else if(x[1]>=32.7)ans_2="12";  
    Console.WriteLine(ans_1+" "+ans_2);
  }
}