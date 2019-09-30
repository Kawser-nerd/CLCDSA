using System;
using System.Linq;

class prog{
  static void Main(){
    string N = Console.ReadLine();
    Console.WriteLine(N[0] == '9'||N[1] == '9' ? "Yes" : "No");
  }
}