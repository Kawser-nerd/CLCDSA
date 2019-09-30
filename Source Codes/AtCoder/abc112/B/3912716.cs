using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC112 {
	class ABC112_B {
		static void Main(string[] args) {
			int N, T;
			var nt = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
			N = nt[0]; T = nt[1];

			var timeCosts = new List<TimeCost>();
			for (int i = 0; i < N; i++) timeCosts.Add(new TimeCost(Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray()));
			var withinTime = timeCosts.Where(o => o.Time <= T);

			if (!withinTime.Any()) {
				Console.WriteLine("TLE");
				return;
			}

			Console.WriteLine(withinTime.OrderBy(o => o.Cost).First());
		}
	}

	public class TimeCost {
		public int Time { get; private set; }
		public int Cost { get; private set; }
		public TimeCost(int[] tc) {
			Time = tc[1];
			Cost = tc[0];
		}

		public override string ToString() {
			return Cost.ToString();
		}
	}
}