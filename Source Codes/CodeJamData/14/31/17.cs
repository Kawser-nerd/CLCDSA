using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static StreamReader inp;
		static StreamWriter oup;

		static void Main(string[] args)
		{
			inp = new StreamReader(new FileStream("A.in", FileMode.Open, FileAccess.Read));
			oup = new StreamWriter(new FileStream("A.out", FileMode.Create, FileAccess.Write));
			var line = inp.ReadLine();
			var T = int.Parse(line);
			var twoPowers = new List<long>();
			var pow = 1;
			while (pow < 1000)
			{
				twoPowers.Add(pow);
				pow *= 2;
			}
			for (int caseIndex = 0; caseIndex < T; caseIndex++)
			{
				line = inp.ReadLine();
				var parts = line.Split('/');
				var P = long.Parse(parts[0]);
				var Q = long.Parse(parts[1]);
				if (!twoPowers.Contains(Q))
				{
					oup.WriteLine("Case #" + (caseIndex + 1).ToString() + ": impossible");
					continue;
				}
				int gener = 1;
				while (P < Q /2)
				{
					P = P * 2;
					gener++;
				}
				oup.WriteLine("Case #" + (caseIndex + 1).ToString() + ": " + gener.ToString());
			}
			oup.Close();
		}
	}
}