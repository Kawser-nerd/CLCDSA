using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder
{
	class Program
	{
		static void Main(string[] args)
		{
			var N = int.Parse(Console.ReadLine());
			List<List<int>> adj = new List<List<int>>();
			for(int i = 0;i < N;i++)
			{
				adj.Add(Console.ReadLine().Split(' ').Select(int.Parse).ToList());
			}

			var ans = WarshallFloyd(adj);

			int ret = 0;
			for(int i = 0;i < N;i++)
			{
				for(int j = 0;j < N;j++)
				{
					if (adj[i][j] != ans[i][j]) ret = -1;
				}
			}
			if (ret == -1) Console.WriteLine(-1);
			else
			{
				long count = 0;
				for(int i = 0;i < N;i++)
				{
					for(int j = i + 1;j < N;j++)
					{
						count += ans[i][j];
					}
				}
				Console.WriteLine(count - minus);
			}
			//Console.ReadLine();
		}

		static long minus;

		public static List<List<int>> WarshallFloyd(List<List<int>> adjacencyMatrix)
		{
			var retMatrix = new List<List<int>>();
			foreach (var a in adjacencyMatrix)
			{
				var list = new List<int>();
				list.AddRange(a);
				retMatrix.Add(list);
			}
			int n = retMatrix.Count;
			minus = 0;
			var dic = new HashSet<int>();
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (i != k && j != k && i < j &&  adjacencyMatrix[i][j] == retMatrix[i][k] + retMatrix[k][j] && !dic.Contains(i * 400 + j))
						{
							dic.Add(i * 400 + j);
							minus += adjacencyMatrix[i][j];
						}
						retMatrix[i][j] = Math.Min(retMatrix[i][j], retMatrix[i][k] + retMatrix[k][j]);
					}
				}
			}
			return retMatrix;
		}
	}
}