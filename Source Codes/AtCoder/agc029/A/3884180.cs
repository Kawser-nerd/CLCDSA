using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
  static void Main(string[] args)
  {
    var s = Console.ReadLine();
    long count = 0;
    long countB = 0;
    for(int i=0;i<s.Length;i++){
      if(s[i]=='W'){
        count+=countB;
      }else{
        countB++;
      }
    }
    
    Console.WriteLine(count);
  }  
}