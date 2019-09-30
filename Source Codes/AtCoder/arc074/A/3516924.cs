using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long h = long.Parse(input[0]);
		long w = long.Parse(input[1]);
		long answer = long.MaxValue;

    if(h % 3 == 0) answer = 0;
    else answer = Math.Min(answer, w);

    if(w % 3 == 0) answer = 0;
    else answer = Math.Min(answer, h);

    for(long i = 1; i < w; i++)
    {
      if(h % 2 == 0)
      {
        answer = Math.Min(answer, Math.Abs(h*i - (h/2)*(w-i)));
      }else
      {
        answer = Math.Min(answer, 
        Math.Max(Math.Abs(h*i - (h/2)*(w-i)), Math.Abs(h*i - (h/2+1)*(w-i))));
      }
    }

    for(long i = 1; i < h; i++)
    {
      if(w % 2 == 0)
      {
        answer = Math.Min(answer, Math.Abs(w*i - (w/2)*(h-i)));
      }else
      {
        answer = Math.Min(answer, 
        Math.Max(Math.Abs(w*i - (w/2)*(h-i)), Math.Abs(w*i - (w/2+1)*(h-i))));
      }
    }
    
		Console.WriteLine(answer);
	}
}