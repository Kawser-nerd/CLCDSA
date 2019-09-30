using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
    class Program
    {
      static void Main(string[] args){
        int s = Int32.Parse(Console.ReadLine());
        var ret = new List<int>();
        ret.Add(s);
        int x=s;
        int result = 2;
        for(int i=result; i<100000 ;i++){
          x=f(x);
          if(ret.Contains(x)) {
            result = i;
            break;
          }
          ret.Add(x);
        }
        Console.Write(result);
      }
      static int f(int n){
        if(n%2==0) return n /2;
        return 3 * n +1;
      }
    }