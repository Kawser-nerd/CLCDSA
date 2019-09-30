using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GC032A2
{
    class Program
    {
        public static List<int> B = new List<int>();
        public static List<int> ans = new List<int>();
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] b = new int[n];
            string[] input = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                b[i] = int.Parse(input[i]);
                B.Add(b[i]);
            }
            for (int i = B.Count; i >0; i--)
            {
            pull_from_B(B.Count);
            }
            if (B.Count == 0)
            {
                ans.Reverse();
                foreach(int member in ans)
                    {
                        Console.WriteLine(member);
                    }
            }
            else
                {
                    Console.WriteLine(-1);
                }
            }
            public static void pull_from_B(int u)
            {
                if (B.IndexOf(u) == (u - 1))
                {
                    ans.Add(u);
                    B.Remove(u);
                }
                else
                {
                    pull_from_B(u - 1);
                }
            }
    }
}