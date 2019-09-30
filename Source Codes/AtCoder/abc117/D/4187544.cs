using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D_XXOR
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            //int N = int.Parse(Console.ReadLine());
            // ?????????????
            string[] input1 = Console.ReadLine().Split(' ');
            int N = int.Parse(input1[0]);
            long K = long.Parse(input1[1]);

            int[] column = new int[40];// ?????????
            string[] A = new string[N];
            long[] numA = new long[N];
            string[] input2 = Console.ReadLine().Split(' ');
            for (var i = 0; i < N; i++)
            {
                numA[i] = long.Parse(input2[i]);
                string tmp = Convert.ToString(long.Parse(input2[i]), 2);// 2???
                A[i] = string.Join("", tmp.Reverse()); // ??????
                for (var j = 0; j < A[i].Length; j++)
                {
                    string s = A[i].Substring(j, 1);
                    if (s == "1")
                    {
                        column[j]++; // ??????
                    }
                }
            }
            /*
            for(var k = 0; k < N; k++)
            {
                Console.Write(A[k]+" ");
            }
            Console.WriteLine();
            for(var k = 0; k < column.Length; k++)
            {
                Console.WriteLine(k+":"+column[k]);
            }
            */
            //
            long X = 0;
            for (var k = column.Length-1; k >=0 ; k--)
            {
                if (column[k] < N - column[k])
                {
                    X += (long)Math.Pow(2, k);
                    if (X > K)
                    {
                        X -= (long)Math.Pow(2, k);
                    }
                }
            }
            //Console.WriteLine(X);
            long ans = 0;
            foreach (long num in numA)
            {
                ans += X ^ num;
                //ans = X ^ num;
                //Console.WriteLine(ans);
            }
            Console.WriteLine(ans);
        }
    }
}