using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC032
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var N = int.Parse(input[0]);
            var M = int.Parse(input[1]);
            var uf = new UF(N);
            for (var i = 0; i < M; i++)
            {
                var union = Console.ReadLine().Split(' ');
                uf.union(int.Parse(union[0]), int.Parse(union[1]));
            }
            Console.WriteLine(uf.getAnswer());
        }
    }
    class UF
    {
        int[] unions;
        int[] size;
        bool[] roots;
        public UF(int n)
        {
            unions = new int[n + 1];
            size = new int[n + 1];
            roots = new bool[n + 1];

            for (var i = 1; i <= n; i++)
            {
                unions[i] = i;
                size[i] = 1;
                roots[i] = false;
            }
        }

        public void union(int x, int y)
        {
            var rootX = root(x);
            var rootY = root(y);

            if (rootX != rootY)
            {
                if (size[rootX] <= size[rootY])
                {
                    unions[rootX] = rootY;
                    size[rootY] += size[rootX];

                }
                else
                {
                    unions[rootY] = rootX;
                    size[rootX] += size[rootY];

                }
            }
        }

        public int root(int x)
        {
            while (unions[x] != x)
            {
                x = unions[x];
            }

            return x;
        }

        public bool connect(int x, int y)
        {
            return root(x) == root(y);
        }

        public int getAnswer()
        {
            var ans = 0;
            for (var i = 1; i < unions.Length; i++)
            {
                var r = root(i);
                if (!roots[r]) ans++;
                roots[r] = true;
            }
            return ans -1;
        }
    }
}