using System;
class c
{
  static void Main()
  {
    float a = float.Parse(Console.ReadLine());
    float sum = 0;
    for(int i =1;i<=a;i++)
    {
      sum+=i*10000/a;
    }
    Console.WriteLine(sum);
  }
  
}