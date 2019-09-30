using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Round1C
{
    class A
    {
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                String input = text.ReadLine();
                String[] inputs = input.Split(' ');
                int R = int.Parse(inputs[0]);
                int C = int.Parse(inputs[1]);
                int W = int.Parse(inputs[2]);
                int ans = 0;
                if (C == W)
                {
                    ans = W + (R - 1);
                }
                else if (C % W == 0)
                {
                    ans = C / W + (W - 1);
                    ans += (R - 1) * (C / W);
                }
                else 
                {
                    ans += (R) * (C / W);
                    ans += W;
                }
                outtext.WriteLine("Case #" + n_case + ": "+ans);
            }
            outtext.Flush();
        }
    }
}
