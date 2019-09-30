/*
 * @Author: Putt Sakdhnagool
 */ 

using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace GoogleCodeJam
{
    public class CodeJam
    {
        static bool IsPrime(int n)
        {
            for (int i = 2; i <= Math.Sqrt(n); i++)
            {
                if (n % i == 0) return false;
            }
            return true;
        }

        static void Main(String[] args)
        {
            StreamReader reader = new StreamReader("B-small.in");
            StreamWriter writer = new StreamWriter("B-small.out");
            int testCases = int.Parse(reader.ReadLine());
            for (int caseNum = 0; caseNum < testCases; caseNum++)
            {
                string[] tmp = reader.ReadLine().Split(' ');
                int A = int.Parse(tmp[0]);
                int B = int.Parse(tmp[1]);
                int P = int.Parse(tmp[2]);

                List<List<int>> numset = new List<List<int>>();

                for (int i = A; i <= B; i++)
                {
                    //Console.WriteLine(i);
                    numset.Add(new List<int>());
                    for (int j = P; j <= i; j++)
                    {
                        if (i % j == 0)
                        {
                            if (IsPrime(j))
                            {
                                numset[numset.Count - 1].Add(j);
                                //Console.Write(j + " ");
                            }
                        }
                    }
                    //Console.WriteLine();
                }

                bool finished = false;

                while (!finished)
                {
                    bool changed = false;
                    for (int i = 0; i < numset.Count; i++)
                    {
                        for (int j = i + 1; j < numset.Count; j++)
                        {
                            for (int m = 0; m< numset[i].Count; m++)
                            {
                                bool change = false;
                                for (int n = 0; n < numset[j].Count; n++)
                                {
                                    if (numset[i][m] == numset[j][n])
                                    {
                                        change = true;
                                        changed = true;
                                        numset[i].AddRange(numset[j]);
                                        numset.RemoveAt(j);
                                        break;
                                    }
                                }
                                if (change) break;
                            }
                        }
                    }
                    if (!changed) finished = true;
                }

                writer.WriteLine("Case #" + (caseNum + 1) + ": " + numset.Count);
                Console.WriteLine("Case #" + (caseNum + 1) + ": " + numset.Count);
            }
            writer.Close();
            reader.Close();
        }
    }
}