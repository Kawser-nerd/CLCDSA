using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC122D
{
    class Program
    {
        public static int N;
        public const int mod = 1000000007;
        public static int[,] mojis;
        public static int[] ng = new int[] { 6, 70, 134, 198, 24, 25, 26, 27, 9, 73, 137, 201, 36, 37, 38, 39, 18, 82, 146, 210, 72, 74, 75, 22, 30, 54 };
        static void Main(string[] args)
        {

            N = int.Parse(Console.ReadLine());
            if (N == 3) { Console.WriteLine(61); return; }
            
            mojis = new int[256, N];


            //???
            for (int i = 0; i < 256; i++)
            {
                if (!ng.Contains(i)) { mojis[i, 3] = 1; }
            }
            for (int i = 3; i < N-1; i++)
            {
                for (int k = 0; k < 256; k++)
                {
                    int h = k % 64;
                    int ne = h * 4;
                    for (int l = 0; l < 4; l++)
                    {
                        if (!ng.Contains(ne+l))
                        {
                            mojis[ne+l, i + 1] += mojis[k, i];
                            mojis[ne+l, i + 1] %= mod;
                        }
                    }

                }
            }
            int ans = 0;
            for (int i = 0; i < 256; i++)
            {
                ans += mojis[i, N - 1];
                ans %= mod;
            }
            Console.WriteLine(ans);
            
        }
    }
}