using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());
    long[] answer = new long[n];
    long sumMemo = 0;
    string answerMemo = "";
    
    if(n == 3) Console.WriteLine("2 5 63");
    else if(n == 4) Console.WriteLine("2 5 20 63");
    else if(n == 5) Console.WriteLine("2 5 20 30 63");
    else
    {
      for(long i = 0; i < n; i++)
      {
      long memo = i/4;
        if(i%4 == 0) answer[i] = 6*memo+2;
        if(i%4 == 1) answer[i] = 6*memo+3;
        if(i%4 == 2) answer[i] = 6*memo+4;
        if(i%4 == 3) answer[i] = 6*memo+6;
      sumMemo += answer[i];
      }
      if(sumMemo%6 == 2) answer[4] = 30000;
      if(sumMemo%6 == 3) answer[5] = 30000;
      if(sumMemo%6 == 5) answer[5] = 29998;

      answerMemo = answer[0].ToString();
      for(long i = 1; i < n; i++)
      {
        answerMemo += " "+answer[i].ToString();
      }
      Console.WriteLine(answerMemo);
    }
	}
}