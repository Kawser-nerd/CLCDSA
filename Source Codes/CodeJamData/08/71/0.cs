using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class mixture
	{
		public string name;
		public List<string> ingredients = new List<string>();
		public List<int> index = new List<int>();
	}
	class Program
	{
		static void Main(string[] args)
		{
			string[] lines = File.ReadAllLines("a-large.in");
			int lineat = 0;
			int count = int.Parse(lines[lineat++]);
			string output = "";
			for (int i = 0; i < count; i++)
			{
				int n = int.Parse(lines[lineat++]);
				List<mixture> mixtures = new List<mixture>();
				for (int j = 0; j < n; j++)
				{
					mixture mx = new mixture();
					string[] mix = lines[lineat++].Split(' ');
					mx.name = mix[0];
					List<string> ing = new List<string>();
					int m = int.Parse(mix[1]);
					for (int k = 0; k < m; k++)
					{
						if (char.IsUpper(mix[2 + k][0]))
						{
							mx.ingredients.Add(mix[2 + k]);
						}
					}
					mixtures.Add(mx);
				}
				for (int j = 0; j < mixtures.Count; j++)
				{
					foreach (string ing in mixtures[j].ingredients)
					{
						for (int k = 0; k < mixtures.Count; k++)
						{
							if (ing == mixtures[k].name)
							{
								mixtures[j].index.Add(k);
								break;
							}
						}
					}
				}
				Program p = new Program();
				p.mixes = mixtures;

				string answer = p.cost(0).ToString();
				output += "Case #" + (i + 1) + ": " + answer + Environment.NewLine;
			}
			File.WriteAllText("output.txt", output);
			Console.WriteLine(output);
		}
		List<mixture> mixes = new List<mixture>();
		int cost(int at)
		{
			mixture m = mixes[at];
			if (m.ingredients.Count == 0)
			{
				return 1;
			}
			for (int i = 0; i < (1<<16); i++) for(int j=0;j<1000;j++) lut[j,i] = -1;
			return costdp(at, (1 << m.index.Count) - 1);
		}
		int[,] lut = new int[1000,1 << 16];
		int costdp(int at, int left)
		{
			if (lut[at,left] != -1) return lut[at,left];
			int worst = 0;
			if (left == 0) return 1;
			List<int> COSTS = new List<int>();
			for (int i = 0; i < 16; i++)
			{
				if ((left & (1 << i)) != 0)
				{
					int next = mixes[at].index[i];
					int nextcost = costdp(next, (1 << mixes[next].index.Count) - 1);
					worst = Math.Max(nextcost, worst);
					COSTS.Add(nextcost);
				}
			}
			int startCost = mixes[at].index.Count + 1;
			int tempCost = 0;
			int best = startCost;
			COSTS.Sort();
			COSTS.Reverse();
			for (int i = 0; i < COSTS.Count; i++)
			{
				int what = Math.Max(startCost, tempCost + COSTS[i]);
				best = Math.Max(what, best);
				tempCost++;
			}
			
			lut[at,left] = best;
			return best;
		}
	}
}
