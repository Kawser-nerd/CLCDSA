using System;
using System.IO;

class Program
{
	int m = 0;
	int[] t, v;
	bool[] c;
	
	int getMin(int cur, int val)
	{
		//Console.WriteLine(cur);
		if (2 * cur + 1 > m)
		{
			if (v[cur] == val)
			{
				return 0;
			}
			return 999999999;
		}
		int a0 = getMin(cur * 2, 0);
		int a1 = getMin(cur * 2, 1);
		int b0 = getMin(cur * 2 + 1, 0);
		int b1 = getMin(cur * 2 + 1, 1);
		int ret = 999999999;
		if (t[cur] == 0 && val == 0)
		{
			ret = Math.Min(ret, a0 + b0);
			if (c[cur])
			{
				ret = Math.Min(ret, 1 + a0 + b0);
				ret = Math.Min(ret, 1 + a0 + b1);
				ret = Math.Min(ret, 1 + a1 + b0);
			}
		}
		if (t[cur] == 0 && val == 1)
		{
			ret = Math.Min(ret, a0 + b1);
			ret = Math.Min(ret, a1 + b0);
			ret = Math.Min(ret, a1 + b1);
			if (c[cur])
			{
				ret = Math.Min(ret, 1 + a1 + b1);
			}
		}
		if (t[cur] == 1 && val == 0)
		{
			ret = Math.Min(ret, a0 + b0);
			ret = Math.Min(ret, a1 + b0);
			ret = Math.Min(ret, a0 + b1);
			if (c[cur])
			{
				ret = Math.Min(ret, 1 + a0 + b0);
			}
		}
		if (t[cur] == 1 && val == 1)
		{
			ret = Math.Min(ret, a1 + b1);
			if (c[cur])
			{
				ret = Math.Min(ret, 1 + a0 + b1);
				ret = Math.Min(ret, 1 + a1 + b0);
				ret = Math.Min(ret, 1 + a1 + b1);
			}
		}
		return ret;
	}
	
	public int minChanges(int[] nodeTypes, bool[] change, int[] nodeValues, int val)
	{
		m = nodeTypes.Length - 1;
		t = nodeTypes;
		v = nodeValues;
		c = change;
		return getMin(1, val);
	}
	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"f:\a-large.in");
		StreamWriter output = File.CreateText(@"f:\a-large.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			string[] s = input.ReadLine().Split(' ');
			int m = Convert.ToInt32(s[0]);
			int v = Convert.ToInt32(s[1]);
			int[] nodeTypes = new int[m + 1];
			int[] nodeValues = new int[m + 1];
			bool[] change = new bool[m + 1];
			for (int j = 1; j <= m; j++)
			{
				string[] t = input.ReadLine().Split(' ');
				if (t.Length == 2)
				{
					nodeTypes[j] = Convert.ToInt32(t[0]);
					change[j] = (t[1].Equals("1"));
				}
				else
				{
					nodeTypes[j] = 2;
					nodeValues[j] = Convert.ToInt32(t[0]);
				}
			}
			Program p = new Program();
			int ret = p.minChanges(nodeTypes, change, nodeValues, v);
			output.WriteLine("Case #" + i + ": " + ((ret == 999999999) ? "IMPOSSIBLE": ret.ToString()));
		}
		input.Close();
		output.Close();
	}
}
