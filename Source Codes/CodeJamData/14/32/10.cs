using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\B-small-attempt0.in"))
            {
                using (var sw = new StreamWriter(@"..\..\B-small-attempt0.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        sr.ReadLine();
                        var s = sr.ReadLine().Split();

                        var k = Enumerable.Range(0, s.Length).ToArray();

                        int res = 0;
                        do
                        {
                            //for (int i = 0; i < k.Length; i++)
                            //{
                            //    Console.Write(k[i]);
                            //    Console.Write(" ");
                            //}
                            //Console.WriteLine();
                            //continue;

                            var u = new bool[50];
                            int i;
                            for (i = 0; i < k.Length; i++)
                            {
                                int j;
                                for (j = 0; j < s[k[i]].Length; j++)
                                {
                                    if (u[s[k[i]][j] - 'a'])
                                    {

                                        if (j > 0)
                                        {
                                            if (s[k[i]][j - 1] != s[k[i]][j])
                                            {
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (s[k[i - 1]][s[k[i - 1]].Length - 1] != s[k[i]][j])
                                            {
                                                break;
                                            }
                                        }
                                    }
                                    u[s[k[i]][j] - 'a'] = true;
                                }
                                if (j < s[k[i]].Length)
                                {
                                    break;
                                }
                            }
                            if (i == k.Length)
                            {
                                res++;
                            }
                        } while (NextPermutation(k));
                        sw.WriteLine("Case #{0}: {1}", t, res);
                    }
                }
            }
        }

        private static bool NextPermutation(int[] numList)
        {
            /*
             Knuths
             1. Find the largest index j such that a[j] < a[j + 1]. If no such index exists, the permutation is the last permutation.
             2. Find the largest index l such that a[j] < a[l]. Since j + 1 is such an index, l is well defined and satisfies j < l.
             3. Swap a[j] with a[l].
             4. Reverse the sequence from a[j + 1] up to and including the final element a[n].

             */
            var largestIndex = -1;
            for (var i = numList.Length - 2; i >= 0; i--)
            {
                if (numList[i] < numList[i + 1])
                {
                    largestIndex = i;
                    break;
                }
            }

            if (largestIndex < 0) return false;

            var largestIndex2 = -1;
            for (var i = numList.Length - 1; i >= 0; i--)
            {
                if (numList[largestIndex] < numList[i])
                {
                    largestIndex2 = i;
                    break;
                }
            }

            var tmp = numList[largestIndex];
            numList[largestIndex] = numList[largestIndex2];
            numList[largestIndex2] = tmp;

            for (int i = largestIndex + 1, j = numList.Length - 1; i < j; i++, j--)
            {
                tmp = numList[i];
                numList[i] = numList[j];
                numList[j] = tmp;
            }

            return true;
        }
    }
}

