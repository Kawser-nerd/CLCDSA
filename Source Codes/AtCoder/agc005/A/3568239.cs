using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    int n = s.Length;
		int answer = s.Length;
    int sCount = 0;

    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'S') sCount++;
      else if(sCount > 0)
      {
        answer -= 2;
        sCount--;
      }
    }
    
		Console.WriteLine(answer);
	}
}