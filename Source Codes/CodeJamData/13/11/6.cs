using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Numerics;

namespace BullsEyes
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\A-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\A-small-attempt0.out");

            StreamReader sr = new StreamReader("D:\\A-large.in");
            StreamWriter sw = new StreamWriter("D:\\A-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                BigInteger r = BigInteger.Parse(str[0]);
                BigInteger t = BigInteger.Parse(str[1]);

                BigInteger A = 2 * r + 1;
                BigInteger d = 4;


                BigInteger min = 1;
                BigInteger max = t;

                while (max - min > 1)
                {
                    BigInteger n = (min + max) / 2;
                    BigInteger sum = (2 * A + (n - 1) * d) * n / 2;

                    if (sum > t)
                    {
                        max = n;
                        continue;
                    }
                    else if (sum < t)
                    {
                        min = n;
                        continue;
                    }
                    else
                    {
                        max = n;
                        min = n;
                        break;
                    }
                }

                BigInteger sum1 = (2 * A + (min - 1) * d) * min / 2;
                BigInteger sum2 = (2 * A + (max - 1) * d) * max / 2;

                sw.Write("Case #{0}: ", i + 1);
                if (sum2<= t)
                {
                    sw.Write(max);
                }
                else if (sum1 <= t)
                {
                    sw.Write(min);
                }
                else
                {
                    throw new Exception();
                }
                sw.WriteLine();

            }
            sw.Close();
        }

        
    }
}
