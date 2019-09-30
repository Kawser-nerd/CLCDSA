using System;

class keisan
{
  static void Main()
  {
    
    string str = Console.ReadLine();

    long kaisuu = 0;
    long Bkazu = 0;
    for (int i = 0; i < str.Length; i++)
    {
      //????
      if (str[i] == 'B')
      {
        Bkazu++;
      }
      else if (str[i] == 'W')
      {
        kaisuu += Bkazu;
      }
    }
  	System.Console.WriteLine(kaisuu);
  }
}