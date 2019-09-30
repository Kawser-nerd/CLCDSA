using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace A
{
	public class SafetyNumbers
	{
		public String Solve(String str)
		{
			String[] strs = str.Split(' ');
			int N = Convert.ToInt32(strs[0]);
			double[] C = new double[N];
			double sum = 0;
			for (int i = 0; i < N; i++)
			{
				C[i] = Convert.ToDouble(strs[i + 1]);
				sum += C[i];
			}
			String outputs = "";
			Hashtable ht = new Hashtable();
			for (int i = 0; i < N; i++)
			{
				double f = 0;
				if (ht[C[i]] != null)
					f = (double)ht[C[i]];
				else
				{
					f = SearchScore(0, 1, i, sum, C);
					ht.Add(C[i], f);
				}
				outputs += (String.Format("{0:0.000000}", f * 100) + " ");
			}
			return outputs;
		}

		double SearchScore(double low, double high, int index, double sum, double [] C)
		{
			if(Math.Abs(high - low) < 0.00000001)
				return high;

			double f = (low + high) / 2;
			if (IsSafe(f, C, index, sum))
			{
				return SearchScore(low, f, index, sum, C);
			}
			else
				return SearchScore(f, high, index, sum, C);
		}

		double GetScore(double fraction, double score, double sum)
		{
			return score + fraction * sum;
		}

		bool IsSafe(double fraction, double[] C, int index, double sum)
		{
			double safe_score = GetScore(fraction, C[index], sum);
			double rest = 1 - fraction;
			for (int i = 0; i < C.Length; i++)
			{
				if (rest <= 0)
					return true;
				if (i != index)
				{
					double f = (safe_score - C[i]) / sum;
					if (f < 0)
						f = 0;
					rest -= f;
				}
			}
			if (rest > 0)
				return false;
			else
				return true;
		}
	}
}
