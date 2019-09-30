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
		long answer = n;

    for(int i = 0; i <= n; i++)
    {
      bool memo = true;
      for(int j = i; j < n; j++)
      {
        if(sUp[j] != sDown[j-i]) memo = false;
      }
      if(memo)
      {
        answer = n+i;
        break;
      }
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}