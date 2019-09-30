using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class Program
    {
        static bool NextPerm(int[] a)
        {
            for (int i = a.Length - 2; i >= 0; i--)
                if (a[i] < a[i + 1])
                {
                    Array.Reverse(a, i + 1, a.Length - i - 1);
                    for (int j = i + 1; ; j++)
                        if (a[i] < a[j])
                        {
                            int temp = a[i]; a[i] = a[j]; a[j] = temp;
                            return true;
                        }
                }
            return false;
        }

        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\D.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\D.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    int N = int.Parse(line);
                    line = sr.ReadLine().Trim();

                    int[] perm = new int[N];
                    for (int i = 0; i < perm.Length; i++)
                    {
                        perm[i] = i;
                    }

                    int minCount = int.MaxValue;
                    do
                    {
                        int count = 0;
                        char prev = '-';
                        int pos = 0;
                        int ipos = 0;
                        for (int i = 0; i < line.Length; i++)
                        {
                            char cur = line[ipos + perm[pos]];
                            if (cur != prev)
                            {
                                prev = cur;
                                count++;
                            }

                            pos++;
                            if (pos >= perm.Length)
                            {
                                pos -= perm.Length;
                                ipos += perm.Length;
                            }
                        }
                        if (count < minCount)
                        {
                            minCount = count;
                        }
                    } while (NextPerm(perm));

                    sout.WriteLine("Case #{0}: {1}", cas, minCount);
                }
            }
        }
    }
}
