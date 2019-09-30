using System;

namespace MyNamespace
{
    class MyClass
    {
        static int n, k;
        static int[,] t;
        public static void Main()
        {
            Solve();
            //Console.ReadKey();
        }
        static void Solve()
        {
            string[] input = Console.ReadLine().Split();
            n = int.Parse(input[0]);
            k = int.Parse(input[1]);
            string[] tin = new string[n];
            t = new int[n, k];
            for (int i = 0; i < n; i++)
            {
                tin = Console.ReadLine().Split();
                for (int j = 0; j < k; j++)
                {
                    t[i, j] = int.Parse(tin[j]);
                }
            }
            if (Search(0, 0)) Console.WriteLine("Found");
            else Console.WriteLine("Nothing");

        }
        static bool Search(int numQ,int val)
        {
            if (numQ == n) return (val == 0);
            for (int i = 0; i < k; i++)
            {
                if (Search(numQ + 1, val ^ t[numQ, i])) return true;
            }
            return false;
        }
    }
}