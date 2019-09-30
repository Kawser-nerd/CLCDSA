using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
			int N = int.Parse(Console.ReadLine());
			int[] d = new int[N];
			int[] n = new int[N];
			int[] w = new int[N];
			int[] e = new int[N];
			int[] s = new int[N];
			int[] delta_d = new int[N];
			int[] delta_p = new int[N];
			int[] delta_s = new int[N];
			for (int i = 0; i < N; i++)
			{
				string[] p = Console.ReadLine().Split();
				d[i] = int.Parse(p[0]);
				n[i] = int.Parse(p[1]);
				w[i] = int.Parse(p[2]);
				e[i] = int.Parse(p[3]);
				s[i] = int.Parse(p[4]);
				delta_d[i] = int.Parse(p[5]);
				delta_p[i] = int.Parse(p[6]);
				delta_s[i] = int.Parse(p[7]);
			}
			List<Attack> attacks = new List<Attack>();
			for (int i = 0; i < N; i++)
			{
				int cd = d[i];
				int cp = 0;
				int cs = s[i];
				for (int j = 0; j < n[i]; j++)
				{
					attacks.Add(new Attack(cd, cp + e[i], cp + w[i], cs));
					cd += delta_d[i];
					cs += delta_s[i];
					cp += delta_p[i];
				}
			}
			attacks.Sort();
			int ans = 0;
			int[] strength = new int[1000];
			for (int i = 0; i < attacks.Count; i++)
			{
				int from = attacks[i].w * 2 + 500;
				int to = attacks[i].e * 2 + 500;
				bool succeed = false;
				for (int j = from; !succeed && j <= to; j++)
					if (strength[j] < attacks[i].s)
						succeed = true;
				if (succeed) ans++;
				if (i + 1 < attacks.Count && attacks[i + 1].d == attacks[i].d)
					continue;
				int k = i;
				while (k >= 0 && attacks[k].d == attacks[i].d)
				{
					from = attacks[k].w * 2 + 500;
					to = attacks[k].e * 2+ 500;
					for (int j = from; j <= to; j++)
						if (strength[j] < attacks[k].s)
							strength[j] = attacks[k].s;
					k--;
				}
			}
            Console.WriteLine("Case #" + CASE + ": " + ans);
        }
    }
}

public class Attack : IComparable<Attack>
{
	public int d, e, w, s;

	public Attack(int d, int e, int w, int s)
	{
		this.d = d;
		this.e = e;
		this.w = w;
		this.s = s;
	}

	public int CompareTo(Attack other)
	{
		return d.CompareTo(other.d);
	}
}
