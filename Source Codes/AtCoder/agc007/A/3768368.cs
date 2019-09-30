using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');//Split???????????????????
		long h = long.Parse(input[0]);
		long w = long.Parse(input[1]);
    long count = 0;
    for(int i = 0; i < h; i++)
    {
		  string s = Console.ReadLine();
      for(int j = 0; j < w; j++)
      {
        if(s[j] == '#') count++;
      }
    }
		
		if(count == h+w-1) Console.WriteLine("Possible");
    else Console.WriteLine("Impossible");
	}
}