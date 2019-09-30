using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace c
{
	class Program
	{
		static void Main(string[] args)
		{
			List<BigInteger> nums = new List<BigInteger>();
			nums.Add(9);
			xxx("1", 0, 1, nums);
			xxx("2", 0, 1, nums);
			for (int len = 1; len < 27; len++)
			{
				//Console.WriteLine("len {0}: {1}", len, nums.Count);
				xxx("1", len, 1, nums);
				string s = "2";
				for (int i = 1; i < len; i++)
				{
					s += 0;
				}
				xxx(s + 0, 0, 1, nums);
				xxx(s + 1, 0, 1, nums);
			}
			/*
			Console.WriteLine("fin: {0}", nums.Count);
			for (int i = 0; i < 10; i++)
			{
				Console.WriteLine(nums[i]);
			}
			Console.WriteLine("...");
			for (int i = 0; i < 10; i++)
			{
				Console.WriteLine(nums[nums.Count - 10 + i]);
			}
			Console.ReadLine();
			return;
			*/
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] linea = Console.ReadLine().Split(' ');
				BigInteger min = BigInteger.Parse(linea[0]);
				BigInteger max = BigInteger.Parse(linea[1]);
				int ok = 0;
				foreach (BigInteger n in nums)
				{
					if (n >= min && n <= max)
					{
						ok++;
					}
				}

				Console.WriteLine("Case #{0}: {1}", caso, ok);
			}
		}

		static bool ispal(BigInteger p)
		{
			BigInteger n = p * p;
			string s = n + "";
			string s1 = s.Substring(0, s.Length / 2);
			string s2 = s.Substring(s.Length / 2);
			if (s2.Length > s1.Length)
			{
				s2 = s2.Substring(1);
			}
			return s1 == new string(s2.Reverse().ToArray());
		}

		static void xxx(string s, int prof, int unos, List<BigInteger> nums)
		{
			if (prof == 0)
			{
				string r = new string(s.Reverse().ToArray());
				BigInteger p1 = BigInteger.Parse(s + r.Substring(1));
				BigInteger p2 = BigInteger.Parse(s + r);

				if (ispal(p1))
				{
					//Console.WriteLine(p1);
					//Console.WriteLine("{0} / {1} / {2}", s, p1, p1 * p1);
					nums.Add(p1 * p1);
				}
				if (ispal(p2))
				{
					//Console.WriteLine(p2);
					//Console.WriteLine("{0} / {1} / {2}", s, p2, p2 * p2);
					nums.Add(p2 * p2);
				}
			}
			else
			{
				if (s[0] == '2')
				{
					xxx(s + 0, prof - 1, unos, nums);
					if (prof == 1)
					{
						xxx(s + 1, 0, unos, nums);
					}
				}
				else
				{
					xxx(s + 0, prof - 1, unos, nums);
					if (unos < 5)
					{
						xxx(s + 1, prof - 1, unos + 1, nums);
						if (prof == 1)
						{
							xxx(s + 2, 0, unos, nums);
						}
					}
				}
			}
		}
	}
}
