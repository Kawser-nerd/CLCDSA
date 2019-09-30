using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Qualification
{
    class Two
    {
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                int D = int.Parse(text.ReadLine());
                int[] d = new int[1001];
                String line = text.ReadLine();
                String[] infos = line.Split(' ');
                int max = 0;
                int res = 1000;
                for (int i = 0; i < D; i++)
                {
                    d[i] = int.Parse(infos[i]);
                    max = Math.Max(max, d[i]);
                }
                for (int i = 1; i <= max; i++)
                {
                    int count = 0;
                    for (int j = 0; j < D; j++)
                    {
                        if (d[j] > 0)
                        {
                            count += d[j] / i;
                            if (d[j] % i == 0 && d[j] >= i )
                            {
                                count -= 1;
                            }
                        }
                    }
                    res = Math.Min(res, i + count);
                }
                outtext.WriteLine("Case #" + n_case + ": " + res);
            }
            outtext.Flush();
        }
    }
}
