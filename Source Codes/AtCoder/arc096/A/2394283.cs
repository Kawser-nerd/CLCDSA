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
        private long A, B, C, X, Y;

        private void Scan()
        {
            var sc = new Scanner();
            A = sc.NextInt();
            B = sc.NextInt();
            C = sc.NextInt();
            X = sc.NextInt();
            Y = sc.NextInt();
        }

        public void Solve()
        {
            Scan();
            long ans = 0;
            if (A + B > C * 2)
            {
                long min = Math.Min(X, Y);
                ans += C * 2 * min;
                X -= min;
                Y -= min;
            }

            ans += Math.Min(A, C * 2) * X;
            ans += Math.Min(B, C * 2) * Y;
            Console.WriteLine(ans);
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}