using System;

class Program
{
  static void Main(string[] args)
  {
    string str = Console.ReadLine();

    for (int i=0; i<str.Length; i++) {
      int num = int.Parse(str[i].ToString());
      if (num == 9) {
        Console.WriteLine("Yes");
        return;
      }
    }
    Console.WriteLine("No");
    return;
  }
}