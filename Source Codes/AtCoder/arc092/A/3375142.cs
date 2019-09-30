using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
    long answer = 0;
		long n = long.Parse(Console.ReadLine());//int.Parse???????????
    long[][] vertexesRed = new long[n][];//x???y???????1
    long[][] vertexesBlue = new long[n][];//x???y???????1
    for(long i = 0; i < n; i++)
    {
      vertexesRed[i] = new long[3];
      vertexesBlue[i] = new long[2];
    }
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexesRed[i][0] = nums[0];
      vertexesRed[i][1] = nums[1];
    }
    for(long i = 0; i < n; i++)
    {
      long[] nums = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
      vertexesBlue[i][0] = nums[0];
      vertexesBlue[i][1] = nums[1];
    }
    Array.Sort(vertexesRed, (a, b) => a[0].CompareTo(b[0]));//x??????
    Array.Sort(vertexesBlue, (a, b) => a[0].CompareTo(b[0]));

    long[] maxMemo = new long[2];//???y??

    for(long blueNum = 0; blueNum < n; blueNum++)
    {
    maxMemo[0] = -1;
    maxMemo[1] = -1;
      for(long redNum = 0; redNum < n; redNum++)
      {
        if(vertexesRed[redNum][0] < vertexesBlue[blueNum][0] &&
          vertexesRed[redNum][1] < vertexesBlue[blueNum][1] &&
          vertexesRed[redNum][1] > maxMemo[1] &&
          vertexesRed[redNum][2] == 0)
        {
          maxMemo[1] = vertexesRed[redNum][1];
          maxMemo[0] = redNum;
        }
      }
      //Console.WriteLine(maxMemo[0]+" "+maxMemo[1]);
      
      if(maxMemo[0] != -1)
      {
        vertexesRed[maxMemo[0]][2] = 1;
        answer++;
        //Console.WriteLine(maxMemo[0]+" "+maxMemo[1]);
      }
      
    }

		Console.WriteLine(answer);//WriteLine?Write?????????????
	}
}