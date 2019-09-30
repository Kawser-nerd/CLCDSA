using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ConsoleApplication
{
    class Program
    {
        static void Main()
        {
            new Solution().answer();
        }
    }

    class Solution
    {
        string input, M;
        string P, Q, ans;
        double A, B,N, Max, Min, diff, S;

        public Solution()
        {
            input = Console.ReadLine();  //N A B
            string[] N_split = input.Split(' ');         
            List<int> list = new List<int>();
            int i;

            for (i = 0; i < Convert.ToInt32(N_split[0]); i++) 
            {
                M = Console.ReadLine();
                list.Add(Convert.ToInt32(M));
            }

            N = Convert.ToDouble(N_split[0]);
            A = Convert.ToDouble(N_split[1]);
            B = Convert.ToDouble(N_split[2]);

            S = list.Average();
            Max = list.Max();
            Min = list.Min();
            diff = Max - Min;
            
            if (diff == 0) { ans = "-1"; }
            else
            {
                P = (B / diff).ToString();
                Q = (A - Convert.ToDouble(P) * S).ToString();
                ans = P + " " + Q;
            }

        }

        public void answer()
        {
            Console.WriteLine(ans);
        }
    }
}