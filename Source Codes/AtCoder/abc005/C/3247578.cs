using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
	int t = int.Parse(Console.ReadLine());//int.Parse???????????
  int n = int.Parse(Console.ReadLine());//int.Parse???????????
  int[] presents = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
  int m = int.Parse(Console.ReadLine());//int.Parse???????????
  int[] players = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
  int presentNum = 0;
  bool answer = true;

    for(int i = 0; i < m; i++)
    {
      while(presentNum < n)
      {
      presentNum++;
        if(presents[presentNum-1] <= players[i] && presents[presentNum-1]+t >= players[i]) break;
        else if(presentNum == n)answer = false;
      }
      
    }
      
      if(n<m)answer = false;

  
	Console.WriteLine((answer) ? "yes" : "no");
	}
}