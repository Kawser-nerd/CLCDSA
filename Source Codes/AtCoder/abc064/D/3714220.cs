using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		long n = long.Parse(Console.ReadLine());//long.Parse?string?long????
		string s = Console.ReadLine();
		string answer = "";
    int leftCount = 0;
    int rightCount = 0;

    for(int i = 0; i < n; i++)
    {
      if(s[i] == '(') leftCount++;
      else
      {
        if(leftCount == 0) rightCount++;
        else leftCount--;
      }
    }
    for(int i = 0; i < rightCount; i++) answer += "(";
    answer += s;
    for(int i = 0; i < leftCount; i++) answer += ")";
    
		Console.WriteLine(answer);
	}
}