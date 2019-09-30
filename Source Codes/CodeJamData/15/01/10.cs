using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace waterfood.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines(@"../../A-large.in");
            var outputs = new StringBuilder();

            int T = int.Parse(inputs[0]);
            for (int x = 0; x < T; x++)
            {
                string[] content = inputs[x + 1].Split(' ');
                int n = int.Parse(content[0]);
                int[] shyness = content[1].ToCharArray().Select(c => int.Parse(c.ToString())).ToArray();
                int friends = 0;
                int standup = 0;
                for (int j = 0; j <= n; j++)
                {
                    if (standup < j)
                    {
                        friends += (j - standup);
                        standup = j;
                    }
                    standup += shyness[j];
                }
                outputs.AppendLine(string.Format("Case #{0}: {1}", x + 1, friends));
            }

            File.WriteAllText(@"../../large.out", outputs.ToString());
        }
    }
}
