using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class MultibaseHappiness
    {
        int minHappyNumber(int[] bases)
        {
            int n = 2;
            while (true)
            {
                bool allHappy = true;
                foreach (int b in bases)
                {
                    if (!isHappy(b, n))
                    {
                        allHappy = false;
                        break;
                    }
                }
                if (allHappy)
                    return n;
                n++;
            }
        }

        bool isHappy(int b, int n)
        {
            List<int> nn = new List<int>();

            while (true)
            {
                if (n == 1)
                    return true;
                
                if (nn.Contains(n))
                    return false;

                nn.Add(n);

                int newn = 0;

                while (n > 0)
                {
                    int digit = n%b;
                    n /= b;

                    newn += digit*digit;
                }

                n = newn;

            }
        }

        public static void Main()
        {
            StreamReader sr = new StreamReader("A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("MultibaseHappiness.out");

            var obj = new MultibaseHappiness();

            int testsCount = int.Parse(sr.ReadLine());

            for (int i = 0; i < testsCount; i++)
            {
                string[] bases = sr.ReadLine().Split(' ');
                int result = obj.minHappyNumber(bases.Select(s=>int.Parse(s)).ToArray());
                sw.WriteLine("Case #{0}: {1}", i + 1, result);
            }

            sr.Close();
            sw.Close();
        }
    }
}
