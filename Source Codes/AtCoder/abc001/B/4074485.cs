using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
class Program
{
    static void Main(string[] args)
    {
		var m = ReadLine().Int();
      	if(m>70000){
        	WriteLine(89);
        }
      	else if(m>=35000){
        	WriteLine((m/1000-30)/5+80);
        }
      	else if(m>=6000){
          	WriteLine(m/1000+50);
        }
      	else if(m>=1000){
         	WriteLine(m/100); 
        }
      	else if(m>=100){
         	WriteLine($"0{m/100}"); 
        }
      	else{
        	WriteLine("00");
        }
    }
}

static class StringExtensions
{
    public static int Int(this string str)
    {
        return int.Parse(str);
    }
}