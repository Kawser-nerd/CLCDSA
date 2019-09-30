using System.IO;
using System.Linq;
using System.Text;

namespace Round1BProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var arrangement = ArrangeUnicorns(line[0], line[1], line[2], line[3], line[4], line[5], line[6]);

                    writer.WriteLine("Case #{0}: {1}", caseId, arrangement ?? "IMPOSSIBLE");
                    writer.Flush();
                }
            }
        }

        private static string ArrangeUnicorns(int n, int r, int o, int y, int g, int b, int v)
        {
            string rStr = "R", yStr = "Y", bStr = "B";

            var result = new StringBuilder();

            r -= g;
            y -= v;
            b -= o;

            int i;
            if (r >= y && r >= b) i = 0;
            else if (y >= r && y >= b) i = 1;
            else i = 2;

            var firstI = i;

            if (r < 0 || y < 0 || b < 0) return null;

            while (r + y + b> 0)
            {
                switch (i)
                {
                    case 0:
                        // red
                        result.Append('R');
                        r--;
                        while (g > 0)
                        {
                            result.Append("GR");
                            g--;
                        }

                        if (y == b)
                        {
                            i = firstI == 1 ? 1 : 2;
                        }
                        else
                        {
                            i = y >= b ? 1 : 2;
                        }
                        break;

                    case 1:
                        // yellow
                        result.Append('Y');
                        y--;
                        while (v > 0)
                        {
                            result.Append("VY");
                            v--;
                        }

                        if (r == b)
                        {
                            i = firstI == 2 ? 2 : 0;
                        }
                        else
                        {
                            i = r >= b ? 0 : 2;
                        }
                        break;

                    case 2:
                        // blue
                        result.Append('B');
                        b--;
                        while (o > 0)
                        {
                            result.Append("OB");
                            o--;
                        }

                        if (r == y)
                        {
                            i = firstI == 1 ? 1 : 0;
                        }
                        else
                        {
                            i = r >= y ? 0 : 1;
                        }
                        break;
                }
            }

            if (r < 0 || y < 0 || b < 0) return null;


            if (result.Length == 0)
            {
                if (g > 0 && o == 0 && v == 0)
                {
                    while (g > 0)
                    {
                        result.Append("GR");
                        g--;
                    }
                }
                else if (g == 0 && o > 0 && v == 0)
                {
                    while (o > 0)
                    {
                        result.Append("OB");
                        o--;
                    }
                }
                else if (g == 0 && o == 0 && v > 0)
                {
                    while (v > 0)
                    {
                        result.Append("VY");
                        v--;
                    }
                }
                else return null;
            }

            if (result.Length > 1 && result[0] == result[result.Length - 1]) return null;

            if (result.Length < n) return null;

            return result.ToString();
        }
    }
}
