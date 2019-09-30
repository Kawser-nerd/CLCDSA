using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var hwd = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[][] field = new int[hwd[0]][];
            for (int i = 0; i < hwd[0]; i++)
            {
                field[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            }
            var map = new Dictionary<int, int>();
            for (int i = 0; i < hwd[0]; i++)
            {
                for (int j = 0; j < hwd[1]; j++)
                {
                    map[field[i][j]] = 1000 * i + j;
                }
            }
            map = map.OrderBy(x => x.Key).ToDictionary(x => x.Key, x => x.Value);
            int[] warp = map.Values.ToArray();
            int[] ans = new int[warp.Count()];
            int q = int.Parse(Console.ReadLine());
            for (int i = ans.Count() - 1; i >= 0; i--)
            {
                if (i >= ans.Count() - hwd[2]) ans[i] = 0;
                else
                {
                    ans[i] = ans[i + hwd[2]] + Math.Abs(warp[i] % 1000 - warp[i + hwd[2]] % 1000) + Math.Abs(warp[i] / 1000 - warp[i + hwd[2]] / 1000);
                }
            }
            for (int i = 0; i < q; i++)
            {
                var lr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                Console.WriteLine(ans[lr[0] - 1] - ans[lr[1] - 1]);
            }
        }
    }
}