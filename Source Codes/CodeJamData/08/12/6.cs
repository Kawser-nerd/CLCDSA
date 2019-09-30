using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace GCJ2008
{
	class MSP
	{
		
		// n is the number of source vertices 
		// m is the number of dest vertices
		// adj is the adjacency graph - (n+m)x(n+m)
		static bool maxflow(int flavors, int customers, List<int>[] preferences,int maltLimit, out bool[] malts)
		{
			malts = null;
			int flavorTrackStart = 0;
			int unflavoredStart = flavorTrackStart + flavors;
			int maltFlavorStart = unflavoredStart + flavors;
			int customerStart = maltFlavorStart + flavors;
			int maltVertex = customerStart + customers;
			int maltLimitNode = maltVertex + 1;
			int source = maltLimitNode + 1;
			int sink = source + 1;
			int total = sink + 1;

			int[,] flow = new int[total, total];
			int[,] res = new int[total, total];
			int[] from = new int[total];
			// initialize the residual
			for (int i = 0; i < flavors; i++)
			{
				res[source, flavorTrackStart + i] = 1;
				res[flavorTrackStart + i, maltVertex] = 1;
				res[flavorTrackStart + i, unflavoredStart + i] = 1;
				res[maltLimitNode, maltFlavorStart + i] = 1;
			}

			res[maltVertex, maltLimitNode] = maltLimit;
			for (int i = 0; i < preferences.Length; i++)
			{
				res[customerStart + i, sink] = 1;
				foreach (int choice in preferences[i])
				{
					int m = choice;
					if(m < 0)
					{
						m *= -1;
						m += flavors;
					}

					m--;
					res[unflavoredStart + m, customerStart + i] = 1;
				}
			}

			bool improved;

			do
			{
				// bfs from the source to the sink
				improved = false;
				for (int i = 0; i < total; i++) from[i] = -1;
				Queue<int> next = new Queue<int>();
				next.Enqueue(source);

				do
				{
					int at = next.Dequeue();
					if (at == sink)
					{
						int capacity = res[from[at], at];
						// we found an augmenting path, add it to the flow and update the residual
						while (at != source)
						{
							capacity = Math.Min(res[from[at], at], capacity);
							at = from[at];
						}
						at = sink;
						while(at != source)
						{
							flow[from[at], at] += capacity;
							res[from[at], at] -= capacity;
							res[at, from[at]] += capacity;
							at = from[at];
						}
						improved = true;
						break;
					}
					else
					{
						for (int i = 0; i < total; i++)
						{
							if (res[at, i] > 0 && from[i] == -1)
							{
								next.Enqueue(i);
								from[i] = at;
							}
						}
					}
				} while (next.Count > 0);

				int sum = 0;
				
				for (int i = 0; i < customers; i++)
				{
					sum += flow[customerStart + i, sink];
				}
				if (sum == customers)
				{
					malts = new bool[flavors];
					for (int i = 0; i < flavors; i++)
					{
						if (flow[maltLimitNode, maltFlavorStart + i] > 0)
						{
							malts[i] = true;
						}
					}
					
					return true;
				}
			} while (improved);

			return false;
			// the matching is all edges (i,j) such that flow[i,n+j] == true
		}
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("B-large.in");
			int lineAt = 0;
			string output = "";

			int cases = int.Parse(lines[lineAt++]);
			for (int i = 0; i < cases; i++)
			{
				int flavors = int.Parse(lines[lineAt++]);
				int customers = int.Parse(lines[lineAt++]);
				List<int>[] preferences = new List<int>[customers];
					
				for (int j = 0; j < customers; j++)
				{
					preferences[j] = new List<int>();
					string[] s = lines[lineAt++].Split(' ');
					int types = int.Parse(s[0]);
					
					for (int k = 1; k < s.Length; k += 2)
					{
						int flavor = int.Parse(s[k]);
						//flavor--;
						int malt = int.Parse(s[k + 1]);
						if (malt == 1) flavor *= -1;
						preferences[j].Add(flavor);
					}
				}
				bool bad = false;
				List<int> need = new List<int>();
				bool[] unmalted = new bool[flavors+1];
				bool[] malted = new bool[flavors+1];
				bool[] done = new bool[customers];

				string o = "";// "IMPOSSIBLE";
				/*
				for (int ii = 0; ii < (1 << flavors); ii++)
				{
					bool good = true;
					for (int j = 0; j < customers; j++)
					{
						bool got = false;
					
						foreach (int choice in preferences[j])
						{
							int p = choice;
							if (p < 0)
							{
								p *= -1;
								p--;
								if ((ii & (1 << p)) != 0)
								{
									got = true;
									break;
								}
							}
							else
							{
								p--;
								if ((ii & (1 << p)) == 0)
								{
									got = true;
									break;
								}
							}
						}
						if (!got) good = false;
					}
					if (good)
					{
						o = "";
						for (int j = 0; j < flavors; j++)
						{
							if(j > 0) o += " ";
							if ((ii & (1 << j)) != 0)
							{
								o += "1";
							}
							else
							{
								o += "0";
							}
						}
						break;
					}
				}
				 * */
				bool changed = false;
				do
				{
					changed = false;
					for (int j = preferences.Length - 1; j >= 0; j--)
					{
						if (!done[j])
						{
							if (preferences[j].Count == 0)
							{
								bad = true;
								break;
							}
							if (preferences[j].Count == 1)
							{
								int set = preferences[j][0];
								int m = preferences[j][0];
								if (m < 0)
								{
									m *= -1;
									if (unmalted[m])
									{
										bad = true;
										break;
									}
									malted[m] = true;
								}
								else
								{
									if (malted[m])
									{
										bad = true;
										break;
									}
									unmalted[m] = true;
								}
								for (int q = 0; q < preferences.Length; q++)
								{
									if (!done[q])
									{
										if (preferences[q].Contains(set))
										{
											done[q] = true;
										}
									}
									preferences[q].Remove(m);
									preferences[q].Remove(-m);
								}
								done[j] = true;
								changed = true;
							}
						}
					}
					if (bad) break;
				} while (changed);

				
				if (bad) o += "IMPOSSIBLE";
				else
				{
					for (int j = 0; j < flavors; j++)
					{
						if (j > 0) o += " ";
						if (malted[j+1])
						{
							o += "1";
						}
						else
						{
							o += "0";
						}
					}
				}
				bool gotone = false;
				if (!bad && false)
				{
					for (int limit = 0; limit <= flavors; limit++)
					{
						bool[] malts;
						if (maxflow(flavors, customers, preferences, limit, out malts))
						{
							//o = "";
							for (int j = 0; j < flavors; j++)
							{
								if (j > 0) o += " ";
								if (malts[j])
								{
									o += "1";
								}
								else
								{
									o += "0";
								}
							}
							gotone = true;
							break;
						}
					}

				}
				if (!gotone && false)
				{
					o += "IMPOSSIBLE";
				}

				output += "Case #" + (i + 1) + ": " + o;
				output += Environment.NewLine;
			}
			File.WriteAllText("output.txt", output);
		}
	}
}
