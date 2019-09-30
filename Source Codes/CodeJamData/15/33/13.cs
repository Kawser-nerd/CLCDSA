using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Round1C
{
    class C
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
                int C = int.Parse(inputs[0]);
                int D = int.Parse(inputs[1]);
                int V = int.Parse(inputs[2]);
                int[] denom = new int[D];
                input = text.ReadLine();
                inputs = input.Split(' ');
                for (int i = 0; i < D; i++)
                {
                    denom[i] = int.Parse(inputs[i]);
                }
                int uptonow = 0;
                int toadd = 0;
                int index = 0;
                while (uptonow < V && index < D)
                {
                    if (uptonow < denom[index] - 1)
                    {
                        toadd++;
                        uptonow += (uptonow + 1) * C;
                    }
                    else
                    {
                        uptonow += denom[index++] * C;
                    }
                }
                if (uptonow >= V)
                {
                    outtext.WriteLine("Case #" + n_case + ": " + toadd);
                }
                else 
                {
                    while (uptonow < V)
                    {
                        toadd++;
                        uptonow += (uptonow + 1) * C;
                    }

                    outtext.WriteLine("Case #" + n_case + ": " + toadd);
                }
            }
            outtext.Flush();
        }
    }
}
