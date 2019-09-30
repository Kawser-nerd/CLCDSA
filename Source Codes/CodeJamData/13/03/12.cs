using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.IO;

namespace CJ
{
    class Program
    {
        static List<long> res = new List<long>();
        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter(@"C:\output.txt");
            string[] lines = System.IO.File.ReadAllLines(@"C:\input.txt");
            int lineid = 0;
            string line = lines[lineid++];
            int T = int.Parse(line);

            init();

            for (int t = 1; t <= T; t++)
            {
                string [] num = lines[lineid++].Split();
                long A = long.Parse(num[0]);
                long B = long.Parse(num[1]);
                
                tw.WriteLine("Case #" + t + ": " + getRes(A, B));

            }

            Console.WriteLine("FINE");
            foreach(long x in res)
                Console.WriteLine(x+" "+Math.Sqrt(x));
            
            Console.WriteLine(long.MaxValue);
            tw.Close();
        }

        private static int getRes(long A, long B)
        {
            int a = res.BinarySearch(A);
            int b = res.BinarySearch(B);
            int ret = 0;
            if(b>=0)ret=1;
            Console.WriteLine(a+" "+b);
            if (a < 0)
            {
                a *= -1;
                a--;
            }
            if (b < 0)
            {
                b *= -1;
                b--;
            }

            return ret + b - a;
        }

        static void init()
        {
            
            for (long i = 1; i < 100000000; i++)
            {
                if (!isPalindrome(i))continue;
                long x = i * i;
                if (isPalindrome(x))
                {
                    res.Add(x);
                }
            }
        }

        static Boolean isPalindrome(long x)
        {
            string s = "" + x;
            for (int i = 0; i <= s.Length / 2; i++)
                if (s[i] != s[s.Length - i - 1]) return false;
            return true;
        }
    }

}
