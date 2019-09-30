using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			var s = Console.ReadLine().ToCharArray();
			var t = Console.ReadLine().ToCharArray();

			var flag = false;

			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] != t[i])
				{
					if ((s[i] == '@' && Regex.IsMatch(t[i].ToString(), "[a,t,c,o,d,e,r]")) || ((t[i] == '@' && Regex.IsMatch(s[i].ToString(), "[a,t,c,o,d,e,r]"))))
					{
						continue;
					}
					flag = true;
				}
			}

			if (flag)
			{
				Console.WriteLine("You will lose");
			}
			else
			{
				Console.WriteLine("You can win");
			}
		}
	}
}