using System;
using System.Linq;

namespace abc007_4
{
	class Program
	{
		static long calc(long n)
		{
			string s = n.ToString();
			int len = s.Length;
			long ret = 0;
			//???? 1????
			if (len == 1)
			{
				if (n < 4) return 0;
				if (n < 9) return 1;
				return 2;
			}
			int head = int.Parse(s[0].ToString());
			long body = long.Parse(s.Substring(1, len - 1));
			//???? 10^n*m???
			if (body == 0)
			{
				return head == 4 || head == 9 ? calc(n - 1) + 1 : calc(n - 1);
			}
			if (head == 9 || head == 4) ret += body + 1;
			else ret += calc(body);

			if (head > 4) ret += (long)Math.Pow(10, len - 1);

			int a = head;
			if (head > 4) a--;
			ret += calc((long)Math.Pow(10, len - 1)) * a;
			return ret;
		}
		static void Main(string[] args)
		{
			long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
			Console.WriteLine(calc(x[1]) - calc(x[0] - 1));
		}
	}
}