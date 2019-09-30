using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1CA
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var N = int.Parse(Console.ReadLine());
				var graph = new List<int[]>(N);
				for (var i = 0; i < N; i++)
				{
					var elements = Console.ReadLine().Split();
					var M = int.Parse(elements[0]);
					var node = new int[M];
					for (var j = 0; j < M; j++)
						node[j] = int.Parse(elements[j + 1]) - 1;
					graph.Add(node);
				}
				var checkedNodes = new bool[N];
				var found = false;
				while (true)
				{
					var index = 0;
					while (index < N && checkedNodes[index])
						index++;
					if (index == N)
						break;
					var meek = new HashSet<int>();
					var queue = new Queue<int>();
					queue.Enqueue(index);
					while (queue.Count > 0)
					{
						var node = queue.Dequeue();
						if (!meek.Add(node))
						{
							found = true;
							break;
						}
						foreach (var inheritor in graph[node])
							queue.Enqueue(inheritor);
					}
					if (found)
						break;
					foreach (var item in meek)
						checkedNodes[item] = true;
				}

				Console.WriteLine("Case #{0}: {1}", testNumber, found ? "Yes" : "No");
			}
		}
	}
}
