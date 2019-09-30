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
		char[][] aims = new char[h][];
    for(int i = 0; i < h; i++)
    {
      string s = Console.ReadLine();
      aims[i] = new char[w];
      for(int j = 0; j < w; j++)
      {
        aims[i][j] = s[j];
      }
    }
    char[][] answersTop = new char[h][];
    char[][] answersDown = new char[h][];
    for(int i = 0; i < h; i++)
    {
      answersTop[i] = new char[w];
      answersDown[i] = new char[w];
      for(int j = 0; j < w; j++)
      {
        answersTop[i][j] = '.';
        answersDown[i][j] = '.';//???

        if(j == 0) answersTop[i][j] = '#';
        if(j == w-1) answersDown[i][j] = '#';
        if(i%2 == 0 && j!= w-1) answersTop[i][j] = '#';
        if(i%2 == 1 && j!=0) answersDown[i][j] = '#';
        if(aims[i][j] == '#')
        {
          answersTop[i][j] = '#';
          answersDown[i][j] = '#';
        }
      }
    }

    for(int i = 0; i < h; i++)
    {
      Console.WriteLine(string.Join("", answersTop[i]));
    }
    Console.WriteLine("");
    for(int i = 0; i < h; i++)
    {
      Console.WriteLine(string.Join("", answersDown[i]));
    }
    
	}
}