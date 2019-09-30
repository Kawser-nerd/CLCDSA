using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC122C2
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????????????
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int Q = int.Parse(input[1]);
            // ??????
            string S = Console.ReadLine();
            int[] cumulative = new int[N + 1];//???
            cumulative[0] = 0;
            cumulative[1] = 0;
            for (int i = 2; i <= S.Length; i++)
            {
                if ((S.Substring(i-1, 1) == "C")&&(S.Substring(i-2, 1) == "A"))
                {
                    cumulative[i] = cumulative[i - 1] + 1;
                }
                else
                {
                    cumulative[i] = cumulative[i - 1];
                }
            }
/*
            foreach (var item in cumulative)
            {
                Console.Write(item+" ");
            }
*/
            for (int i = 0; i < Q; i++)
            {
                string[] inputLR = Console.ReadLine().Split(' ');
                int l = int.Parse(inputLR[0]);
                int r = int.Parse(inputLR[1]);
                Console.WriteLine(cumulative[r] - cumulative[l]);
            }
        }
    }
}