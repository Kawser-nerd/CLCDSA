using System;
using System.Collections.Generic;
using System.Text;

public class A
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		A task = new A ();
		
		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve (Console.ReadLine ()));
	}

	List<int> mul (List<int> a, int b)
	{
		List<int> res = new List<int> ();
		int rem = 0;

		foreach (int i in a)
		{
			rem += i * b;
			res.Add (rem % 10);
			rem /= 10;
		}

		while (rem > 0)
		{
			res.Add (rem % 10);
			rem /= 10;
		}

		return res;
	}

	List<int> plus (List<int> a, int rem)
	{
		List<int> res = new List<int> ();

		foreach (int i in a)
		{
			rem += i;
			res.Add (rem % 10);
			rem /= 10;
		}

		while (rem > 0)
		{
			res.Add (rem % 10);
			rem /= 10;
		}

		return res;
	}

	public string Solve (string s)
	{
		string pos = "0123456789abcdefghijklmnopqrstuvwxyz";
		bool[] bol = new bool[pos.Length];

		foreach (char c in s)
			bol[pos.IndexOf (c)] = true;

		int cnt = 0;
		foreach (bool b in bol)
			if (b)
				++cnt;

		if (cnt == 1)
			++cnt;

		int?[] num = new int?[pos.Length];
		int now = 0;

		foreach (char c in s)
		{
			int i = pos.IndexOf (c);
			if (num[i].HasValue)
				continue;

			if (now == 0)
				num[i] = 1;
			else if (now == 1)
				num[i] = 0;
			else
				num[i] = now;

			++now;
		}

		List<int> res = new List<int> ();
		res.Add (0);

		foreach (char c in s)
		{
			res = mul (res, cnt);
			res = plus (res, num[pos.IndexOf (c)].Value);
		}

		string _res = "";

		foreach (int i in res)
			_res = "" + i + _res;

		return _res;
	}
}
