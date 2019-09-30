using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static public bool isprime(int n)
        {
            checked
            {
                if (n == 2)
                    return true;
                if (n % 2 == 0)
                    return false;
                for (int i = 3; i * i <= n; i += 2)
                {
                    if (n % i == 0)
                        return false;
                }
                return true;
            }
        }
        static void Main(string[] args)
        {
            checked
            {
                StreamReader sr = new StreamReader(args[0]);
                int N = int.Parse(sr.ReadLine());
                for (int t = 1; t <= N; t++)
                {
                    string[] split = sr.ReadLine().Split();
                    int A = int.Parse(split[0]);
                    int B = int.Parse(split[1]);
                    int P = int.Parse(split[2]);
                    bool[] inset = new bool[B - A+1];
                    int rtn = B-A+1;
                    for (int i = Math.Max(2,P); i <=B-A; i++)
                    {
                        if (!isprime(i))
                            continue;
                        rtn++;
                        int first = ((A + i - 1) / i) * i;
                        //Console.WriteLine(A+" "+i+" "+first);
                        bool firstset = true;
                        for (int j = first; j <= B; j+=i)
                        {
                            if (inset[j-A])
                            {
                                if (firstset)
                                {
                                    rtn--;
                                    firstset = false;
                                }
                            }
                            else
                            {
                                rtn--;
                                inset[j-A] = true;
                            }
                        }
                    }
                    Console.WriteLine("Case #{0}: {1}", t, rtn);
                }
            }
        }
    }
}
