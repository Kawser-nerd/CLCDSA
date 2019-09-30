using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    long n = s.Length;
		long answer = 0;

    for(long i = 0; i < n; i++)
    {
      if(s[(int)i] == 'U') answer += 2*i + n-1-i;
      else answer += i + 2*(n-1-i);
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}