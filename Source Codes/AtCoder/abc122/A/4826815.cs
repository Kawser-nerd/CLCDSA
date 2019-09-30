using System;
class Pg{
  static void Main(string[] args){
    string b = Console.ReadLine();
    string c = b == "A" ? "T" : b == "T" ? "A" : b == "G" ? "C" : "G";
    Console.WriteLine(c);
  }
}