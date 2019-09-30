using System;

class Program
{
	static void Main()
	{
		var T = int.Parse(Console.ReadLine());
		for (var i = 0; i < T; )
		{
			Console.WriteLine("Case #{0}:", ++i);
			Case();
		}
	}

	static void Case()
	{
		var N = int.Parse(Console.ReadLine());
		var schedule = new bool?[N, N];
		var WP = new Tuple<int,int>[N];
		for (var i = 0; i < N; i++)
		{
			var ttl = 0;
			var win = 0;
			var line = Console.ReadLine();
			for (var j = 0; j < N; j++)
			{
				schedule[j, i] = line[j] == '.' ? null as bool? : line[j] == '1';
				if (schedule[j, i] != null)
				{
					ttl++;
					if ((bool)schedule[j, i] == true) win++;
				}
			}
			WP[i] = new Tuple<int, int>(win, ttl);
		}

		var OWP = new double[N];
		for (var i = 0; i < N; i++)
		{
			var sum = 0d;
			for (var j = 0; j < N; j++)
				if (schedule[j, i] != null)
					sum += ((bool)schedule[j, i] ? WP[j].Item1 : WP[j].Item1 - 1) / (double)(WP[j].Item2 - 1);
			OWP[i] = sum / WP[i].Item2;
		}

		var OOWP = new double[N];
		for (var i = 0; i < N; i++)
		{
			var sum = 0d;
			for (var j = 0; j < N; j++)
				if (schedule[j, i] != null)
					sum += OWP[j];
			OOWP[i] = sum / WP[i].Item2;
			Console.WriteLine(0.25 * (WP[i].Item1 / (double)WP[i].Item2) + 0.50 * OWP[i] + 0.25 * OOWP[i]);
		}
	}
}