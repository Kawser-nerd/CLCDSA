using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long k = long.Parse(Console.ReadLine());
		long[] answers = new long[50];
    Console.WriteLine(50);
    long quotient = k / 50;
    int remainder = (int)(k % 50);

    if(k <= 50)
    {
      for(int i = 0; i < k; i++) answers[i] = 50;
    }else
    {
      for(int i = 0; i < remainder; i++)
      {
        answers[i] = 50+quotient-i;
      }
      for(int i = remainder; i < 50; i++)
      {
        answers[i] = 50+quotient-i-1;
      }
    }
    
    Console.WriteLine(string.Join(" ", answers));
	}
}