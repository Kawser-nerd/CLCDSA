using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class A
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("a.in.txt");
            StreamWriter output = new StreamWriter("a.out.txt");

            int T = Int32.Parse(input.ReadLine());

            for (int tc = 0; tc < T; tc++)
            {
                int result = 0;

                int n = Int32.Parse(input.ReadLine());

                List<Boolean[]> lines = new List<bool[]>();

                for (int ln = 0; ln < n; ln++)
                    lines.Add(input.ReadLine().Select(ch => ch == '1').ToArray());

                for (int x = 0; x < n; x++)
                    for (int rr = 0; ;rr++ )
                        if (lines[rr].Skip(x + 1).All(b => b == false))
                        {
                            result += rr;
                            lines.RemoveAt(rr);
                            break;
                        }

                 output.WriteLine("Case #{0}: {1}", tc+1, result);
            }

            input.Close();
            output.Close();
        }
    }
}
