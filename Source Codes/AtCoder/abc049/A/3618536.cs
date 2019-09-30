using System;
using System.Linq;

class p{
  static void Main(){
    string s = Console.ReadLine();
    Console.WriteLine(s == "a"||s == "i"||s == "u"||s == "e"||s == "o" ? "vowel" : "consonant");
  }
}