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
    int answerFirst = -1;
    int answerSecond = -1;

    for(int i = 0; i < n-1; i++)
    {
      if(s[i] == s[i+1])
      {
        answerFirst = i+1;
        answerSecond = i+2;
      }
    }

    for(int i = 0; i < n-2; i++)
    {
      if(s[i] == s[i+2])
      {
        answerFirst = i+1;
        answerSecond = i+3;
      }
    }

		Console.WriteLine(answerFirst+" "+answerSecond);
	}
}