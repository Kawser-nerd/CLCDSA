using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
  int answer = 0;
	string s = Console.ReadLine();
  char[] ss = s.ToCharArray();
  string tt = Console.ReadLine();

    for(int i = ss.Length - 1; i >= tt.Length - 1; i--)
    {
      for(int j = 0; j < tt.Length; j++)
      {
        if(ss[i - j] != tt[tt.Length - 1 - j]
        && ss[i - j] != '?') break;
        if(j == tt.Length - 1)
        {
          for(int k = 0; k < tt.Length; k++)
          {
            ss[i - k] = tt[tt.Length - 1 - k];
          }
          for(int k = 0; k < ss.Length; k++)
          {
            if(ss[k] == '?') ss[k] = 'a';
          }
        Console.WriteLine(ss);
        answer = 1;
        break;
        }
      }
      if(answer != 0) break;
    }

    if(answer == 0) Console.WriteLine("UNRESTORABLE");

	}
}