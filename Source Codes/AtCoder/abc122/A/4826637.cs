using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program{
    static void Main(string[] args){
      string s = Console.ReadLine();
      string ans;
      switch (s) {
        case "A":
          ans = "T";
          break;
        case "T":
          ans = "A";
          break;
        case "G":
          ans = "C";
          break;
        case "C":
          ans = "G";
          break;
        default:
          throw new ArgumentException();
      }
      Console.WriteLine(ans);
    }
}