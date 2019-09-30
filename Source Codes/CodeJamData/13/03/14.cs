using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using Helpers;

namespace _2013Q3
{
    class Program
    {
        static void Main()
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            System.Threading.Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            double lastMs = 0;
            Stopwatch sw = new Stopwatch();
            sw.Start();

            var inFileName = "A.in";
            var outFileName = inFileName.Replace(".in", "_out.out");
            using (var reader = new StreamReader(inFileName))
            using (var writer = new StreamWriter(outFileName))
            {
                int numTests = reader.ReadLineAsInt();

                List<string> polinumbers = GeneratePoliNumbers();
                List<BigInteger> polisqnumbers = polinumbers.Select(t => BigInteger.Parse(t) * BigInteger.Parse(t)).Where(t => IsPalindrome(t)).ToList();
                //HashSet<long> sqNumbers = GetSqrPoliNumbersBetween(1, (long)10000000 * 10000000);      // 1 - 10^14
                //foreach (BigInteger bigInteger in polisqnumbers)
                //{
                //    writer.WriteLine(bigInteger.ToString());    
                //}
                //foreach (long num in sqNumbers)
                //{
                //    writer.WriteLine(num);
                //}

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    //long[] l = reader.ReadLineAsLongArray();
                    //long A = l[0];
                    //long B = l[1];

                    string[] s = reader.ReadLine().Split(' ');
                    UTF8Encoding encoding = new UTF8Encoding();
                    BigInteger Ab = BigInteger.Parse(s[0]);
                    BigInteger Bb = BigInteger.Parse(s[1]);
                    //BigInteger Ab = new BigInteger(A);
                    //BigInteger Bb = new BigInteger(B);

                    //var result = String.Format("Case #{0}: {1}", testcase, Solve(A, B, sqNumbers));
                    var result = String.Format("Case #{0}: {1}", testcase, Solve2(Ab, Bb, polisqnumbers));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static int Solve(long A, long B, HashSet<long> sqNumbers)
        {
            int counter = 0;

            foreach (long sqNumber in sqNumbers)
            {
                if (sqNumber >= A && sqNumber <=B)
                    counter++;
            }

            return counter;
        }

        private static int Solve2(BigInteger A, BigInteger B, List<BigInteger> polisqnumbers)
        {
            int counter = 0;
            foreach (BigInteger num in polisqnumbers)
            {
                if (num >= A && num <= B)
                    counter++;

                if (num > B)
                    break;
            }

            return counter;
        }

        private static HashSet<long> GetSqrPoliNumbersBetween(long A, long B)
        {
            HashSet<long> result = new HashSet<long>();

            for (long i = A; i<=Math.Sqrt(B); i++)
            {
                if (IsPalindrome(i))
                {
                    long sqr = (long)Math.Pow(i, 2);
                    if (IsPalindrome(sqr))
                        result.Add(sqr);
                }
            }

            return result;
        }

        private static bool IsPalindrome(long l)
        {
            char[] arr = l.ToString().ToCharArray();
            Array.Reverse(arr);
            return (long.Parse(new string(arr)) == l);
        }

        private static bool IsPalindrome(BigInteger l)
        {
            char[] arr = l.ToString().ToCharArray();
            Array.Reverse(arr);
            return (BigInteger.Parse(new string(arr)) == l);
        }

        private static List<string> GeneratePoliNumbers()
        {
            List<string> evens = new List<string> { "11", "22" };
            List<string> result = new List<string> { "1", "2", "3" };
            result.AddRange(evens);

            while(evens[0].Length < 51)
            {
                result.AddRange(CreateOddsFromEvens(evens));
                evens = CreateEvensFromEvens(evens);
                result.AddRange(evens);
            }

            return result;
        }

        private static List<string> CreateOddsFromEvens(List<string> evens)
        {
            List<string> result = new List<string>();

            foreach (string even in evens)
            {
                int halfLength = even.Length / 2;
                
                string s = even.Substring(0, halfLength) + "0" + even.Substring(halfLength, halfLength);
                if (IsPalindrome(BigInteger.Parse(s) * BigInteger.Parse(s))) result.Add(s);
                s = even.Substring(0, halfLength) + "1" + even.Substring(halfLength, halfLength);
                if (IsPalindrome(BigInteger.Parse(s) * BigInteger.Parse(s))) result.Add(s);

                if (even[0] == '1')
                {
                    s = even.Substring(0, halfLength) + "2" + even.Substring(halfLength, halfLength);
                    if (IsPalindrome(BigInteger.Parse(s) * BigInteger.Parse(s))) result.Add(s);
                }
            }

            return result;
        }

        private static List<string> CreateEvensFromEvens(List<string> evens)
        {
            List<string> result = new List<string>();

            foreach (string even in evens)
            {
                int halfLength = even.Length / 2;

                string s = even.Substring(0, halfLength) + "00" + even.Substring(halfLength, halfLength);
                if (IsPalindrome(BigInteger.Parse(s) * BigInteger.Parse(s))) result.Add(s);

                if (even[0] == '1')
                {    
                    s = even.Substring(0, halfLength) + "11" + even.Substring(halfLength, halfLength);
                    if (IsPalindrome(BigInteger.Parse(s) * BigInteger.Parse(s))) result.Add(s);
                }
            }

            return result;
        }
    }
}
