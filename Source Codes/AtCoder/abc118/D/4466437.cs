using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D118
    {


        static void Main(string[] args)
        {
            int[] p = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = p[0], M = p[1];
            int[] A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x=>x).ToArray();
            
            int[] m = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

            string[] z = new string[N+1];

            for(int i = 0; i < M; i++)
            {
                int k = A[i];
                int nm = m[k];

                for (int j = nm; j <= N; j++)
                {
                    if (j > nm && z[j - nm] == null) continue;
                    string scand = k.ToString() + z[j - nm];
                    //??????????????????????????????
                    if (z[j] == null || scand.Length >= z[j].Length) z[j] = scand;
                }

            }
            Console.WriteLine(z[N]);
        }
    }
}