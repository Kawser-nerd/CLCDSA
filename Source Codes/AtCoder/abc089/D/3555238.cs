using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Program
{
	static void Main()
  {
		int[] s = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[,] h = new long[s[0]*s[1]+1, 2];//1~h*w?(x,y)
		long[] a = new long[s[0]*s[1]+1];//0~h*w
		long[][] arr = new long[s[0]][];//h
		for(int i = 0; i < s[0]; i++)//h
    {
			arr[i] = Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			for(int j = 0; j < s[1]; j++)//w
      {
				h[arr[i][j],0] = i;
				h[arr[i][j],1] = j;
			}
		}
		for(int i = 1; i <= s[0]*s[1]-s[2]; i++)//1~h*w-d
    {
			a[i+s[2]] = Math.Abs(h[i+s[2],0] - h[i,0]) + 
        Math.Abs(h[i+s[2],1] - h[i,1]) + a[i];//d???DP
		}
		int n = int.Parse(Console.ReadLine());//q
		for(int i = 0; i < n; i++)//q
    {
			int[] q = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			Console.WriteLine(a[q[1]] - a[q[0]]);
		}
	}
}