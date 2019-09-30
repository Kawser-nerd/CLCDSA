using System.Collections.Generic;
using System.Linq;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            int[] A = new int[N];
            for (int i = 0; i < N; i++)
                A[i] = int.Parse(ReadLine());

            Dictionary<int, int> dics = new Dictionary<int, int>();
            int cnt = 0;
            foreach (var g in A.OrderBy(_ => _).GroupBy(__ => __))
                dics.Add(g.Key, cnt++);
            for (int i = 0; i < N; i++)
                WriteLine(dics[A[i]]);
        }
    }
}