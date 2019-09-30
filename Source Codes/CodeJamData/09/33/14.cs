using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        private static bool[] freed;
        private static int p, q;
        private static int[] cn;
        static void Main(string[] args)
        {
            const string inputFileName = "C-small.in";
            const string outputFileName = "C-small.out.txt";
            var input = new StreamReader(inputFileName);
            var output = new StreamWriter(outputFileName);
            var tc = int.Parse(input.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                var temp = Array.ConvertAll(input.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), x => int.Parse(x));
                p = temp[0];
                q = temp[1];
                cn = Array.ConvertAll(input.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), x => int.Parse(x));
                freed = new bool[q];
                output.WriteLine("Case #{0}: {1}", t + 1, Go(0));
            }
            output.Close();
        }

        private static int Go(int sp)
        {
            if (sp == q)
                return 0;
            int? mn = null;
            for (int i = 0; i < q; i++)
            {
                if (!freed[i])
                {
                    freed[i] = true;
                    var j = 0;
                    for (j = i - 1; j >= 0 && !freed[j]; --j)
                    {}
                    var temp = j == -1 ? cn[i] - 1 : cn[i] - cn[j] - 1;
                    for (j = i + 1; j < q && !freed[j]; j++)
                    {}
                    temp += j == q ? p - cn[i] : cn[j] - cn[i] - 1;
                    temp += Go(sp + 1);
                    freed[i] = false;
                    if (!mn.HasValue || mn.Value > temp)
                    {
                        mn = temp;
                    }
                }
            }
            return mn.Value;
        }
    }
}
