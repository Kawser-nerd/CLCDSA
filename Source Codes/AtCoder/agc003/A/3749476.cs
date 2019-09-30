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
    int[] news = new int[4];
    bool answer = true;

    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'N') news[0]++;
      if(s[i] == 'E') news[1]++;
      if(s[i] == 'W') news[2]++;
      if(s[i] == 'S') news[3]++;
    }

    if(news[0] > 0 && news[3] == 0) answer = false;
    if(news[1] > 0 && news[2] == 0) answer = false;
    if(news[2] > 0 && news[1] == 0) answer = false;
    if(news[3] > 0 && news[0] == 0) answer = false;
    
		Console.WriteLine((answer) ? "Yes" : "No");
	}
}