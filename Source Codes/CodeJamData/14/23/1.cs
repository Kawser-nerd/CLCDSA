using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
	class Program
	{
		static Int32 n;
		static Int32 m;
		static List<Int32>[] edges;
		static Boolean[] deleted;
		static Boolean[] deleted2;
		static Int32[] queue;
		static Boolean[] visited;
		static Boolean[] outbound;

		static Boolean CheckConnectivity(Int32 start, Int32 needToVisit)
		{
			for (Int32 i = 0; i < n; ++i)
				visited[i] = false;

			Int32 first = 0; Int32 last = 1;
			Int32 total = 1;
			queue[0] = start;
			visited[start] = true;

			while (first < last)
			{
				Int32 current = queue[first];
				for (Int32 i = 0; i < edges[current].Count; ++i)
				{
					Int32 x = edges[current][i];
					if (!visited[x] && !deleted[x] && !deleted2[x])
					{
						visited[x] = true;
						queue[last++] = x;
						++total;
					}
				}
				first++;
			}

			return total == needToVisit;
		}


		static void Main(string[] args)
		{
			using (StreamReader reader = new StreamReader(@"j:\codejam\ConsoleApplication7\input.txt"))
			{
				using (StreamWriter writer = new StreamWriter(@"j:\codejam\ConsoleApplication7\output.txt"))
				{
					Int32 T = Int32.Parse(reader.ReadLine());
					for (Int32 test = 1; test <= T; ++test)
					{
						String[] str = reader.ReadLine().Split(' ');
						n = Int32.Parse(str[0]);
						m = Int32.Parse(str[1]);
						edges = new List<Int32>[n];
						String[] zip = new String[n];
						for (int i = 0; i < n; ++i)
						{
							edges[i] = new List<Int32>();
							zip[i] = reader.ReadLine();
						}

						for (Int32 i = 0; i < m; ++i)
						{
							String[] s = reader.ReadLine().Split(' ');
							Int32 x = Int32.Parse(s[0]) - 1;
							Int32 y = Int32.Parse(s[1]) - 1;
							edges[x].Add(y);
							edges[y].Add(x);
						}

						deleted = new Boolean[n];
						deleted2 = new Boolean[n];
						queue = new Int32[n+2];
						visited = new Boolean[n];
						outbound = new Boolean[n];

						Int32[] stack = new Int32[n + 2];
						Int32 stackTop = 0;

						String min = zip[0];
						Int32 minI = 0;
						Int32 minTop;

						for (Int32 i = 0; i < n; ++i)
							if (zip[i].CompareTo(min) < 0)
							{
								min = zip[i];
								minI = i;
							}

						outbound[minI] = true;
						Int32 start = stack[stackTop] = minI;
						String answer = min;

						Int32 deletedTotal = 0;
						Int32 deletedWillbe = 0;
						Int32 outboundTotal = 1;

						while (outboundTotal < n)
						{
							min = null;
							minI = -1;
							minTop = -1;
							deletedWillbe = 0;
							for (Int32 i = 0; i < n; ++i)
								deleted2[i] = false;
							for (Int32 i = stackTop; i >= 0; i--)
							{
								Int32 current = stack[i];
								for (Int32 j = 0; j < edges[current].Count; ++j)
								{
									Int32 x = edges[current][j];
									if (!outbound[x] && (min == null || zip[x].CompareTo(min) < 0))
									{
										min = zip[x];
										minI = x;
										minTop = i;
									}
								}
								deleted2[current] = true;
								++deletedWillbe;
								if (!CheckConnectivity(start, n - deletedTotal - deletedWillbe))
									break;
							}
							while (stackTop > minTop)
							{
								deleted[stack[stackTop]] = true;
								++deletedTotal;
								--stackTop;
							}
							answer += min;
							outbound[minI] = true;
							stack[++stackTop] = minI;
							outboundTotal++;
						}

						writer.WriteLine("Case #" + test + ": " + answer);
					}
				}
			}
		}
	}
}
