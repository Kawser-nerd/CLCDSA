using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace C
{
	public class EqualSums
	{
		public String Solve(String str)
		{
			String[] strs = str.Split(' ');
			String output = "";
			int [] n = new int[20];
			for (int i = 0; i < 20; i++)
				n[i] = Convert.ToInt32(strs[i + 1]);
			ArrayList S1 = new ArrayList();
			ArrayList S2 = new ArrayList();
			if (Find(ref S1, ref S2, n))
			{
				output = "\r\n";
				foreach (int m in S1)
					output += (m + " ");
				output += "\r\n";
				foreach (int m in S2)
					output += (m + " ");

			}
			else
				output = "impossible";
			return output;
		}

		int Sum(int current, int[] n, ArrayList set)
		{
			int sum = 0;
			for (int i = 0; i < 20; i++)
			{
				if ((current & 1) == 1)
				{
					sum += n[i];
					set.Add(n[i]);
				}
				current = (current >> 1);
			}
			return sum;
		}

		bool Find(ref ArrayList S1, ref ArrayList S2, int [] n)
		{
			int current = 0;
			Hashtable ht = new Hashtable();
			while (current < Math.Pow(2, 20))
			{
				current++;
				ArrayList set = new ArrayList();
				int sum = Sum(current, n, set);
				if (ht[sum] != null)
				{
					S1 = set;
					S2 = (ArrayList)ht[sum];
					return true;
				}
				else
				{
					ht.Add(sum, set);
				}
			}
			return false;
		}
	}
}
