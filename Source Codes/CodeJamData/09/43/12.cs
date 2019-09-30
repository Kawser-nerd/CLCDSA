using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2009
{
    class Program
    {
		int[,] prices;
		int nn;
		int kk;
		int[] can;
		int[] dp;
		int solve(int[,] prices, int n, int k)
		{
			dp = new int[1 << n];
			this.prices = prices;
			nn = n;
			kk = k;
			can = new int[n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i != j)
					{
						if (higher(i, j) || higher(j, i))
						{
							can[i] |= 1 << j;
						}
					}
					else
					{
						can[i] |= 1 << i;
					}
				}
			}

			cdp = new int[1 << n];
			return merge((1 << n) - 1);
		}
		int count(int bits)
		{
			int n = 0;
			while (bits != 0)
			{
				n++;
				bits &= bits - 1;
			}
			return n;
		}
		int trysolve(int left, int build,int at)
		{
			if (at == nn)
			{
				if (build != 0)
					return merge(left ^ build) + 1;
				else return count(left);
			}
			else
			{
				int best = trysolve(left, build, at + 1);
				if (((left & (1 << at)) != 0) && (can[at] & build) == build)
				{
					int t = trysolve(left, build | (1 << at), at + 1);
					best = Math.Min(t, best);
				}
				return best;
			}
		}
		int merge(int left)
		{
			if (left == 0) return 0;
			if (dp[left] != 0)
			{
				return dp[left] - 1;
			}
			int best = trysolve(left, 0, 0);
			/*
			int best = count(left);
			for (int p = 1; p <= left; p++)
			{
				if ((p & left) == p)
				{
					if (compat(p))
					{
						best = Math.Min(best, merge(left ^ p) + 1);
					}
				}
			}
			 * */
			dp[left] = best + 1;
			return best;
		}
		int[] cdp;
		bool compat(int bits)
		{
			if (cdp[bits] != 0) return cdp[bits] == 1 ? false : true;
			for (int i = 0; i < nn; i++)
			{
				if ((bits & (1 << i)) != 0)
				{
					if ((can[i] & bits) != bits)
					{				
						cdp[bits] = 1;
						return false;
					}
				}
			}
			cdp[bits] = 2;
			return true;
		}
		bool higher(int i, int j)
		{
			for (int p = 0; p < kk; p++)
			{
				if (prices[i, p] >= prices[j, p]) return false;
			}
			return true;
		}

		static void Main(string[] args)
        {
			string[] input = File.ReadAllLines("C-small-attempt2.in");
            string output = "";
            int lineAt = 0;
            
			int T = int.Parse(input[lineAt++]);
            
            for (int i = 0; i < T; i++)
            {
                string[] res = input[lineAt++].Split(' ');
				int n = int.Parse(res[0]);
				int k = int.Parse(res[1]);
				int[,] prices = new int[n, k];
				for (int j = 0; j < n; j++)
				{
					string[] res2 = input[lineAt++].Split(' ');
					for (int m = 0; m < k; m++)
					{
						prices[j,m] = int.Parse(res2[m]);
					}
				}
				Program p = new Program();

                output += "Case #" + (i + 1) + ": " + p.solve(prices, n, k) + Environment.NewLine;
				Console.WriteLine(i);
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
