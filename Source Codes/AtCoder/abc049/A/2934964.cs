using System;
 
class Program
{
  static void Main(string[] args)
  {
    string c = Console.ReadLine();
    
    if(c == "a" || c == "i" || c == "u" || c == "e" || c == "o")
    {
      Console.WriteLine("vowel");
    }
    else
    {
      Console.WriteLine("consonant");
    }
  }
}