using System;
using System.Linq;

class prog{
  static void Main(){
    
    string O = Console.ReadLine();
    string E = Console.ReadLine();
    
    if(O.Length > E.Length) E += " ";
    
    string ans = "";
    for(int i = 0; i < O.Length; i++){
      ans += "" + O[i] + E[i];
    }
    
    Console.WriteLine(ans);
    
  }
}