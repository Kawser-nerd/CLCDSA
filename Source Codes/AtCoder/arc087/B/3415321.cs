using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string s = Console.ReadLine();
    string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long x = long.Parse(input[0]);
		long y = long.Parse(input[1]);
    long[,] dpx = new long[2,16001];//???????+8000?0????1?????
    long[,] dpy = new long[2,16001];
    bool answer = false;
    long memoForward = 0;
    long turnCount = 0;

    for(long i = 0; i < s.Length; i++)
    {
      if(s[(int)i] == 'F') memoForward++;
      if(s[(int)i] == 'T' || i == s.Length-1)
      {
        if(turnCount == 0)
        {
          dpx[0,memoForward+8000] = 1;
        }else if(turnCount == 1)
        {
          dpy[0,memoForward+8000] = 1;
          dpy[0,-memoForward+8000] = 1;
        }else if(turnCount % 2 == 0)
        {
          for(long j = 0; j < 16001; j++)
          {
            if(dpx[0,j] == 1)
            {
              dpx[1,j-memoForward] = 1;
              dpx[1,j+memoForward] = 1;
            }
          }
          for(long j = 0; j < 16001; j++)
          {
            dpx[0,j] = dpx[1,j];
            dpx[1,j] = 0;
          }
        }else if(turnCount % 2 == 1)
        {
          for(long j = 0; j < 16001; j++)
          {
            if(dpy[0,j] == 1)
            {
              dpy[1,j-memoForward] = 1;
              dpy[1,j+memoForward] = 1;
            }
          }
          for(long j = 0; j < 16001; j++)
          {
            dpy[0,j] = dpy[1,j];
            dpy[1,j] = 0;
          }
        }
        turnCount++;
        memoForward = 0;
      }
    }
    
    if(turnCount >= 2) Console.WriteLine((dpx[0,x+8000] == 1 && dpy[0,y+8000] == 1) ? "Yes" : "No");
    else if(turnCount == 1 && s[s.Length-1] == 'F')Console.WriteLine((s.Length == x && y == 0) ? "Yes" : "No");
    else if(turnCount == 1 && s[s.Length-1] == 'T')Console.WriteLine((s.Length == x+1 && y == 0) ? "Yes" : "No");
	}
}