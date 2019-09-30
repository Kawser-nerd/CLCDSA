using System;
using System.Linq;

public class MainClass
{
	public static void Main (string[] args)
	{
		MainClass task = new MainClass();
		
		int n = int.Parse(Console.ReadLine());
		for(int i = 1; i <= n; ++i)
			Console.WriteLine("Case #{0}: {1}", i, task.Solve());
	}
	
	public string Solve()
	{
		string[] ss = Console.ReadLine().Split(' ');
		int x = int.Parse(ss[0]);
		int s = int.Parse(ss[1]);
		int r = int.Parse(ss[2]);
		int t = int.Parse(ss[3]);
		int n = int.Parse(ss[4]);
		
		double[] spd = new double[n + 1];
		double[] len = new double[n + 1];
		spd[0] = s;
		len[0] = x;
		
		for (int i = 1; i <= n; ++i)
		{
			ss = Console.ReadLine().Split(' ');
			int b = int.Parse(ss[0]);
			int e = int.Parse(ss[1]);
			int w = int.Parse(ss[2]);
			
			spd[i] = s + w;
			len[i] = e - b;
			len[0] -= len[i];
		}
		
		Array.Sort(spd, len);
		double rem = t;
		double tim = 0;
		double boost = r - s;
		
		for (int i = 0; i <= n; ++i)
		{
			double tt = Math.Min(len[i] / (spd[i] + boost), rem);
			rem -= tt;
			tim += tt;
			tim += (len[i] - tt * (spd[i] + boost)) / spd[i];
		}
		
		return tim.ToString();
	}
}