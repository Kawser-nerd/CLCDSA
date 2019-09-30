using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace AtCoder
{
    class Program
    {
        static List<int> primeNumbers;
        static int count = 0;
        
        static void Main(string[] args)
        {
            //[summary]D - 756
            primeNumbers = new List<int> { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                                           53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

            int n = int.Parse(Console.ReadLine());

            //????????????????Dictionary
            var divisors = new Dictionary<int, int>();

            foreach (var num in primeNumbers)
            {
                divisors.Add(num, 0);
            }
            
            //N!??????
            for (int i = 2; i <= n; i++)
            {
                Divide(i, divisors);
            }

            //74x1 ??????????????
            CountCombisByOneNum(divisors);

            //14x4 ??????????????
            CountCombisByTwoNums(divisors, 14, 4);

            //24x3 ??????????????
            CountCombisByTwoNums(divisors, 24, 2);

            //4x4x2 ??????????????
            CountCombisByThreeNums(divisors);
            
            Console.WriteLine(count);
        }

        static void CountCombisByThreeNums(Dictionary<int, int> divisors)
        {
            var combis = new List<List<int>>();

            foreach (var p in divisors)
            {
                if (p.Value >= 4)
                {
                    foreach (var q in divisors)
                    {
                        if (q.Key != p.Key && q.Value >= 4)
                        {
                            if (!IsSameCombiExists(combis, p.Key, q.Key))
                            {
                                foreach (var r in divisors)
                                {
                                    if (r.Key != p.Key && r.Key != q.Key && r.Value >= 2)
                                    {
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        static bool IsSameCombiExists(List<List<int>> combis, int p, int q)
        {
            foreach(var c in combis)
            {
                if (c.Contains(p) && c.Contains(q))
                {
                    return true;
                }
            }

            combis.Add(new List<int> { p, q });
            return false;
        }

        static void CountCombisByTwoNums(Dictionary<int, int> divisors, int a, int b)
        {
            foreach (var p in divisors)
            {
                if (p.Value >= a)
                {
                    foreach(var q in divisors)
                    {
                        if (p.Key != q.Key && q.Value >= b)
                        {
                            count++;
                        }
                    }
                }
            }
        }

        static void CountCombisByOneNum(Dictionary<int, int> divisors)
        {
            foreach(var divisor in divisors)
            {
                if (divisor.Value >= 74)
                {
                    count++;
                }
            }
        }

        static void Divide(int num, Dictionary<int, int> divisors)
        {
            if (IsPrimeNumber(num))
            {
                divisors[num]++;
                return;
            }
            else
            {
                for (int i = 2; i < num; i++)
                {
                    if (num % i == 0)
                    {
                        divisors[i]++;
                        Divide(num / i, divisors);
                        return;
                    }
                }
            }
        }

        static bool IsPrimeNumber(int num)
        {
            if (primeNumbers.Contains(num))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}