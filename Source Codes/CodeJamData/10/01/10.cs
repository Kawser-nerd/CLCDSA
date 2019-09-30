using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SnapperChain
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            using (var stream = File.OpenRead("in.in"))
            {
                using (var reader = new StreamReader(stream))
                {
                    int t = Int32.Parse(reader.ReadLine());
                    for (int i = 1; i <= t; ++i)
                    {
                        var val = reader.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

                        int n = Int32.Parse(val[0]);
                        long k = Int64.Parse(val[1]);

                        output.Append("Case #").Append(i).Append(": ");


						bool isOn = ((k + 1) % (1 << n)) == 0;
						output.AppendLine(isOn ? "ON" : "OFF");
                    }
                }
            }

            File.WriteAllText("p1.out", output.ToString());
        }
    }
}
