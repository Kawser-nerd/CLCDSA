using System;
using System.Collections.Generic;
using System.IO;

class Program
{
	int[] room;
	bool[,,] can;
	List<int> v = new List<int>();
	int[] c= new int[1024];
	
	public bool valid(int x)
	{
		for (int i = 0; i <= 8; i++)
			if ((x & (3 << i)) == (3 << i))
				return false;
		Console.WriteLine("VAlid: " + x);
		return true;
	}
	
	public int countBits(int x)
	{
		int ret = 0;
		for (int i = 0; i < 10; i++)
			if ((x & (1 << i)) > 0)
				ret++;
		return ret;
	}
	
	public int go()
	{
		for (int i = 0; i < 1024; i++)
		{
			c[i] = countBits(i);
			if (valid(i))
				v.Add(i);
		}
		can = new bool[room.Length, 1024, room.Length * 10];
		for (int i = 0; i < v.Count; i++)
		{
			if ((v[i] & room[0]) == v[i])
			{
				can[0, v[i], c[v[i]]] = true;
			}
		}
		Console.WriteLine("vcount: " + v.Count);
		for (int r = 1; r < room.Length; r++)
		{
			for (int m = 0; m < v.Count; m++)
			{
				int m1 = v[m] << 1;
				int m2 = v[m] >> 1;
				int mask = ~(m1 | m2) & room[r];
				for (int j = 0; j < v.Count; j++)
				{
					if ((mask & v[j]) == v[j])
					{
						for (int k = 0; k < room.Length * 10; k++)
						{
							if (can[r - 1, v[m], k])
							        can[r, v[j], k + c[v[j]]] = true;
						}
					}
				}
			}
		}
		for (int k = room.Length * 10 - 1; k > 0; k--)
			for (int j = 0; j < 1024; j++)
				if (can[room.Length - 1, j, k])
			        return k;
		return 0;
	}

	
	public static void Main(string[] args)
	{
		StreamReader input = File.OpenText(@"f:\c-small.in");
		StreamWriter output = File.CreateText(@"f:\c-small.out");
		int c = Convert.ToInt32(input.ReadLine());
		for (int i = 1; i <= c; i++)
		{
			Console.WriteLine(i);
			string[] s = input.ReadLine().Split(' ');
			int m = Convert.ToInt32(s[0]);
			int n = Convert.ToInt32(s[1]);
			int[] room = new int[m];
			for (int j = 0; j < m; j++)
			{
				string t = input.ReadLine();
				for (int k = 0; k < n; k++)
					if (t[k] == '.')
						room[j] |= (1 << k);
			}
			
			
			
			Program pr = new Program();
			pr.room = room;
			
			int ret = pr.go();
			
			output.WriteLine("Case #" + i + ": " + ret);
		}
		input.Close();
		output.Close();
		Console.ReadLine();
	}
}
