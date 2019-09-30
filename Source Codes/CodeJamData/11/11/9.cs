using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace a
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] linea = Console.ReadLine().Split(' ');

				long N = long.Parse(linea[0]);
				int PD = int.Parse(linea[1]);
				int PG = int.Parse(linea[2]);

				//0 < D <= N
				//G >= D
				//D*PD mult 100
				//G*PG mult 100

				//G*PG/100 >= D*PD

				//N <= 10
				bool ok = false;
				if (PG == 100 && PD < 100 || PG == 0 && PD > 0)
				{
					ok = false;
				}
				else
				{
					ok = posible(N, PD);
				}

				Console.WriteLine("Case #{0}: {1}", caso, ok ? "Possible" : "Broken");
			}
		}

		static bool posible(long N, int PD)
		{
			if (N >= 100) return true;
			for (int D = 1; D <= N; D++)
			{
				if (D * PD % 100 == 0) return true;
			}
			return false;
		}
	}
}
