using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
		string sUp = Console.ReadLine();
    string sDown = Console.ReadLine();
		long answer = 1;
    long memo = 0;//??????0???1

    for(long i = 0; i < n; i++)
    {
      if(i == 0)
      {
        if(sUp[0] == sDown[0]) answer = 3;
        else
        {
          answer = 6;
          i++;
          memo = 1;
        }
      }else
      {
        if(sUp[(int)i] == sDown[(int)i])
        {
          if(memo == 0) answer *= 2;
          memo = 0;
        }
        else
        {
          if(memo == 0) answer *= 2;
          else answer *= 3;
          i++;
          memo = 1;
        }
      }
      answer %= 1000000007;
    }
    
		Console.WriteLine(answer);
	}
}