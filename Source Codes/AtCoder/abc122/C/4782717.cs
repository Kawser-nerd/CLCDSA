using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC122C
{
    class Program
    {
        public static int N, Q;
        public static string S;
        public static int[] l, r;
        public static List<int> acs = new List<int>();
        static void Main(string[] args)
        {
            string[] on = Console.ReadLine().Split(' ');
            N = int.Parse(on[0]);
            Q = int.Parse(on[1]);
            S = Console.ReadLine();
            l = new int[Q]; r = new int[Q];
            for (int i = 0; i < Q; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                l[i] = int.Parse(str[0]) - 1;
                r[i] = int.Parse(str[1]) - 1;
            }


            //??
            for (int i = 0; i < N - 1; i++)
            {
                if (S[i] == 'A' && S[i + 1] == 'C') { acs.Add(i); }
            }

            for (int i = 0; i < Q; i++)
            {
                int h = binary_search(l[i]);
                int g = binary_search2(r[i] - 1);
                Console.WriteLine(g-h);
            }
            Console.ReadLine();
        }

        static bool isOK(int index, int key)
        {
            if (acs[index] >= key) { return true; }
            return false;
        }
        static bool isOK2(int index, int key)
        {
            if (acs[index] > key) { return true; }
            return false;
        }
        static int binary_search(int key)
        {
            int ng = -1;
            int ok = acs.Count();
            while (Math.Abs(ok - ng) > 1)
            {
                int mid = (ok + ng) / 2;
                if (isOK(mid, key)) {
                    ok = mid;
                }
                else { ng = mid; }
            }
            return ok;

        }
        static int binary_search2(int key)
        {
            int ng = -1;
            int ok = acs.Count();
            while (Math.Abs(ok - ng) > 1)
            {
                int mid = (ok + ng) / 2;
                if (isOK2(mid, key))
                {
                    ok = mid;
                }
                else { ng = mid; }
            }
            return ok;

        }
    }
}