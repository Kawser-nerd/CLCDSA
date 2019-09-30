using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Remoting.Contexts;
using System.Security.Cryptography.X509Certificates;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    class Program
    {
        private long N, H;
        private long[] A, B;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            H = sc.NextInt();
            A = new long[N];
            B = new long[N];
            for (int i = 0; i < N; i++)
            {
                A[i] = sc.NextInt();
                B[i] = sc.NextInt();
            }
        }

        public void Solve()
        {
            Scan();
            Array.Sort(B, (a, b) => -a.CompareTo(b));
            long max = A.Max();
            long cnt = 0;
            foreach (var i in B)
            {
                if (H <= 0)
                {
                    Console.WriteLine(cnt);
                    return;
                }

                if (i < max)
                {
                    break;
                }
                H -= i;
                cnt++;
            }

            cnt += (H + max - 1) / max;
            Console.WriteLine(cnt);
        }


        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}