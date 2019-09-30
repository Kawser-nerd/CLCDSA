using System;
using System.Collections.Generic;

namespace C
{
	class Program
	{
		static void Main()
		{
			var line = Console.ReadLine();
			var lineSplited = line.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

			var N = int.Parse(lineSplited[0]);
			var M = int.Parse(lineSplited[1]);

			var A = new List<long>();
			var B = new List<int>();
			var items = new List<Item>();
			for (int i = 0; i < N; i++) {
				var line2 = Console.ReadLine();
				var line2Splited = line2.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

				// A.Add(long.Parse(line2Splited[0]));
				// B.Add(int.Parse(line2Splited[1]));

				items.Add(new Item(){ A = long.Parse(line2Splited[0]), B = int.Parse(line2Splited[1])});
			}

			items.Sort((a, b) => {
				if (a.A < b.A) return -1;
				else if (a.A > b.A) return 1;
				else return 0;
			});

			var money = 0L;
			var m = M;
			foreach (var item in items) {
				if (m > 0) {
					if (item.B < m) {
						money += item.A * item.B;
						m -= item.B;
					} else {
						money += item.A * m;
						m -= m;
					}
				} else {
					break;
				}
			}

			Console.WriteLine(money);
		}

		class Item
		{
			public long A;
			public int B;
		}
	}
}