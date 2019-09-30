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
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	public string Solve ()
	{
		int n = int.Parse (Console.ReadLine ());

		List<int> max = new List<int> ();

		for (int i = 0; i < n; ++i)
		{
			int x = Console.ReadLine ().LastIndexOf ('1');

			max.Add (x == -1 ? 0 : x);
		}

		int res = 0;

		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			while (max[j] > i)
			{
				++j;
				++res;
			}

			max.RemoveAt (j);
		}

		return res.ToString ();
	}
}
