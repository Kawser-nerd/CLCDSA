using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace task1
{
	class Program
	{
		static void Main(string[] args)
		{
			var splitters = new char[] { ' ', '\t' };
			TextReader reader = null;
			TextWriter writer = null;
			try
			{
				reader = new StreamReader(args[0], Encoding.ASCII);
				writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Number of cases {0}", cases);
				for (var k = 1; k <= cases; ++k)
				{
					var message = reader.ReadLine();
					var digits = new int[36];
					for (var i = 0; i < 36; ++i)
						digits[i] = -1;
					var classesNum = 0;
					var value = new int[message.Length];
					int idx = 0;
					foreach (var ch in message)
					{
						var index = ch <= '9' ? ch - '0' : ch - 'a' + 10;
						var digit = digits[index];
						if (digit == -1)
						{
							++classesNum;
							if (classesNum == 1)
								digits[index] = 1;
							else if (classesNum == 2)
								digits[index] = 0;
							else
								digits[index] = classesNum - 1;
							digit = digits[index];
						}
						value[idx] = digit;
						++idx;
					}
					if (classesNum == 1)
						classesNum = 2;
					var res = 0L;
					foreach (var digit in value)
					{
						res *= classesNum;
						res += digit;
					}
					var result = String.Format(CultureInfo.InvariantCulture,"Case #{0}: {1}", k, res);
					Console.WriteLine(result);
					writer.WriteLine(result);
				}
			}
			finally
			{
				if (writer != null)
					writer.Close();
				if (reader != null)
					reader.Close();
			}
		}
	}
}