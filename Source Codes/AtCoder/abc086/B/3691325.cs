using System;
using System.Collections.Generic;

class Program {
    static void Main(string[] args){
      string[] s = Console.ReadLine().Split(' ');
      int a = int.Parse(s[0]);
      int b = int.Parse(s[1]);
      int c = 0;
      if(b<10){
        c = 10*a+b;
      } else if(b<100){
        c = 100*a + b;
      } else {
        c = 1000*a+b;
      }
      bool f = false;
      for(int k = 0;k<100*100;k++){
        if(k*k==c) f = true;
      }
      if(f){
        Console.Write("Yes");
      } else {
        Console.Write("No");
      }
    }
  }