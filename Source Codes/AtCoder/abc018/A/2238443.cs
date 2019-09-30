using System;
class Program
{
  static void Main()
  {
    int[] input = new int[3];
    for(int i = 0; i < 3; i++)
    {
      input[i] = int.Parse(Console.ReadLine());
    }
    int[] score = new int[3];
    for(int i = 0; i < 3; i++)
    {
      score[i] = input[i];
    }
    Array.Sort(score);
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(input[i] == score[j])
        {
          Console.WriteLine(3 - j);
        }
      }
    }
  }
}