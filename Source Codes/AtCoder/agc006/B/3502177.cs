using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//?????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long n = long.Parse(input[0]);
		long x = long.Parse(input[1]);
    long[] answers = new long[2*n-1];

    if(x == 1 || x == 2*n-1) Console.WriteLine("No");
    else
    {
      Console.WriteLine("Yes");
      if(x == n)//???
      {
        for(long i = 0; i < 2*n-1; i++) answers[i] = i+1;
      }
      else if(x < n)
      {
        for(long i = 0; i < n; i++) answers[i] = n-i;//543219876???????
        for(long i = 0; i < n-1; i++) answers[2*n-2-i] = n+1+i;
        answers[n-1] = x;
        answers[n-x] = 1;
      }else
      {
        for(long i = 0; i < n; i++) answers[i] = n+i;//567891234???????
        for(long i = 0; i < n-1; i++) answers[2*n-2-i] = n-1-i;
        answers[n-1] = x;
        answers[n-(2*n-1-x)-1] = 2*n-1;      
      }

      var sb = new StringBuilder();
      for(long i = 0; i < answers.Length; i++)
      {
        sb.AppendLine(answers[i].ToString());
      }
      Console.Write(sb);
    }
	}
}