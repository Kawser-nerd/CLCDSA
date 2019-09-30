using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static StreamReader inp;
		static StreamWriter oup;
		static long count;
		static string[] strings;

		static void Main(string[] args)
		{
			inp = new StreamReader(new FileStream("B.in", FileMode.Open, FileAccess.Read));
			oup = new StreamWriter(new FileStream("B.out", FileMode.Create, FileAccess.Write));
			var line = inp.ReadLine();
			var T = int.Parse(line);
			for (int caseIndex = 0; caseIndex < T; caseIndex++)
			{
				line = inp.ReadLine();
				var n = int.Parse(line);
				line = inp.ReadLine();
				strings = line.Split(' ');

				var array = new int[n];
				for (int i = 0; i < n; i++)
				{
					array[i] = i;
				}
				count = 0;
				Permute(0, n, array, Act);
				oup.WriteLine("Case #" + (caseIndex + 1).ToString() + ": " + count.ToString());
				Console.WriteLine(caseIndex);
			}
			oup.Close();
		}

		static void Act(int[] array, int n)
		{
			//oup.WriteLine(string.Join(",", array));
			char? current = null;
			var set = new SortedSet<char>();
			for (int i = 0; i < n; i++)
			{
				var s = strings[array[i]];
				for (int j = 0; j < s.Length; j++)
				{
					if (current == null)
					{
						current = s[j];
						set.Add(current.Value);
					}
					else if (current != s[j])
					{
						current = s[j];
						if (set.Contains(current.Value))
						{
							return;
						}
						set.Add(current.Value);
					}
				}
			}
			count++;
			if (count >= 1000000007)
			{
				count -= 1000000007;
			}
		}

		static void Permute(int i, int n, int[] array, Action<int[], int> action)
		{
			if (n == 1)
			{
				action(array, n);
				return;
			}
			if (i == n - 2)
			{
				action(array, n);
			}
			else
			{
				Permute(i + 1, n, array, action);
			}
			for (int j = i + 1; j < n; j++)
			{
				var temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				if (i == n - 2)
				{
					action(array, n);
				}
				else
				{
					Permute(i + 1, n, array, action);
				}
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}