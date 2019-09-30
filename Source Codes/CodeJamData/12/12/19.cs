using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Random {
	class Kingdom {
		static void Main() {
			int T = int.Parse(Console.ReadLine());
			for (int t = 1; t <= T; t++) {
				int N = int.Parse(Console.ReadLine());
				var levels = new Tuple<int, int>[N];
				for (int i = 0; i < N; i++) {
					var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
					levels[i] = new Tuple<int, int>(line[0], line[1]);
				}
				var sortedLevels = levels.OrderByDescending(l => l.Item2).ThenBy(l => l.Item1).ToList();
				var oneStarLevels = new List<Tuple<int, int>>();
				int stars = 0;
				int used = 0;
				while (sortedLevels.Count > 0 || oneStarLevels.Count > 0) {
					var nextLevel = oneStarLevels.Where(l => l.Item2 <= stars);
					if (nextLevel.Any()) {
						var level = nextLevel.First();
						//Console.WriteLine("Level 2 from 1 on {0},{1} -> {2} stars", level.Item1, level.Item2, stars);
						oneStarLevels.Remove(level);
						stars++;
						used++;
						continue;
					}
					nextLevel = sortedLevels.Where(l => l.Item2 <= stars);
					if (nextLevel.Any()) {
						var level = nextLevel.Last();
						//Console.WriteLine("Level 2 from 0 on {0},{1} -> {2} stars", level.Item1, level.Item2, stars);
						sortedLevels.Remove(level);
						stars += 2;
						used++;
						continue;
					}
					nextLevel = sortedLevels.Where(l => l.Item1 <= stars);
					if (nextLevel.Any()) {
						var level = nextLevel.First();
						//Console.WriteLine("Level 1 from 0 on {0},{1} -> {2} stars", level.Item1, level.Item2, stars);
						oneStarLevels.Add(level);
						sortedLevels.Remove(level);
						stars++;
						used++;
						continue;
					} else {
						used = -1;
						break;
					}
				}
				if (used < 0) {
					Console.WriteLine("Case #{0}: Too Bad", t);
				} else {
					Console.WriteLine("Case #{0}: {1}", t, used);
				}
			}
		}
	}
}
