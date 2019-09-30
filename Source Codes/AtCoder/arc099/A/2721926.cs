using System;

namespace bla
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int k = int.Parse(s[1]);
            int ans = (n - 1) / (k - 1);
            if (ans * (k - 1) < (n - 1))
                ans++;
            Console.WriteLine(ans);
        }
    }
}