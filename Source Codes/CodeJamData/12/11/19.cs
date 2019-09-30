using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Random {
	class Password {
		static void Main() {
			int T = int.Parse(Console.ReadLine());
			for (int t = 1; t <= T; t++) {
				var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
				int A = line[0], B = line[1];

				var probs = Console.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
				double p = 1;
				var cumProbs = probs.Select(x => p *= x).ToArray();

				double strategy1 = (B - A + 1) + (B + 1) * (1-cumProbs.Last());
				double strategy2 = (B + 2);

				double cost = 0;

				double cBest = Math.Min(strategy1, strategy2);
				for (int i = 1; i < cumProbs.Length && (B - A + 1 + 2 * i) < cBest; i++) {
					p = cumProbs[cumProbs.Length - i - 1];
					cost = (B - A + 1 + 2 * i) + (B + 1) * (1 - p);
					if (cost < cBest) {
						cBest = cost;
					}
				}
				Console.WriteLine("Case #{0}: {1:0.000000}", t, cBest);
			}
		}
	}
}
