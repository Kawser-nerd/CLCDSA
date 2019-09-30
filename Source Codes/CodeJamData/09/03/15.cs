using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2009
{
    class Program
    {
        static void Main(string[] args)
        {
			string[] input = File.ReadAllLines("C-large.in");
            string output = "";
            int lineAt = 0;
            int T = int.Parse(input[lineAt++]);
            for (int i = 0; i < T; i++)
            {
				string dim = input[lineAt++];
				string find = "welcome to code jam";
				int[,] dp = new int[dim.Length, find.Length + 1];
				//dp[j,k] means you are at char j, matched k chars of find
				for (int j = 0; j < dim.Length; j++)
				{
					for (int k = 1; k < find.Length + 1; k++)
					{
						int sum = 0;
							
						if(dim[j] == find[k - 1])
						{
							if (k == 1)
							{
								sum = 1;
							}
							else
							{
								for (int p = 0; p < j; p++)
								{
									sum += dp[p, k - 1];
									sum %= 10000;
								}
							}
						}
						dp[j, k] = sum;
					}
				}
				int total = 0;
				for (int j = 0; j < dim.Length; j++) { total += dp[j, find.Length]; total %= 10000; }
				string ret = total.ToString();
				while (ret.Length < 4) ret = "0" + ret;

                output += "Case #" + (i + 1) + ": " + ret + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
