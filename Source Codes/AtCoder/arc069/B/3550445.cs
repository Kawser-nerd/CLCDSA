using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		int n = int.Parse(Console.ReadLine());//long.Parse?string?long????
		string s = Console.ReadLine();
		string[] answers = new string[n];
    bool answer = false;

    for(int i = 0; i < 4; i++)
    {
      if(i % 2 == 0) answers[0] = "S";
      else answers[0] = "W";
      if(i <= 1) answers[1] = "S";
      else answers[1] = "W";

      for(int j = 2; j < n; j++)//2??????????1??
      {
        if(s[j-1] == 'o' && answers[j-1] == "S" ||
          s[j-1] == 'x' && answers[j-1] == "W")
        {
          if(answers[j-2] == "S") answers[j] = "S";
          else answers[j] = "W";
        }
        if(s[j-1] == 'x' && answers[j-1] == "S" ||
          s[j-1] == 'o' && answers[j-1] == "W")
        {
          if(answers[j-2] == "S") answers[j] = "W";
          else answers[j] = "S";
        }
      }

      if(s[n-1] == 'o' && answers[n-1] == "S" ||
        s[n-1] == 'x' && answers[n-1] == "W")
      {
        if(answers[0] != answers[n-2]) continue;
      }else 
      {
        if(answers[0] == answers[n-2]) continue;
      }

      if(s[0] == 'o' && answers[0] == "S" ||
        s[0] == 'x' && answers[0] == "W")
      {
        if(answers[1] != answers[n-1]) continue;
      }else 
      {
        if(answers[1] == answers[n-1]) continue;
      }

      answer = true;
      break;
    }

  	if(answer) Console.WriteLine(string.Join("", answers));
    else Console.WriteLine(-1);
	}
}