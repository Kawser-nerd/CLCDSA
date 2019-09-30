using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{ 
    class Program
    {
        public static int gcd(int a, int b)
        {
            return (b != 0) ? gcd(b, a % b) : a;
        }
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            int n = int.Parse(s[0]), m = int.Parse(s[1]), k = int.Parse(s[2]);
            int ans = gcd(n, m);
            List<int> div = new List<int> { };
            for (int i = 1; i <= ans; i++)
            {
                if (ans % i == 0)
                {
                    div.Add(i);
                }
            }
            div.Reverse();
            //Console.WriteLine(ans);
            Console.WriteLine(div[k - 1]);
            Console.ReadLine();
        }
    }
}