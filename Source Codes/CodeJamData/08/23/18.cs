/*
 * @Author: Putt Sakdhnagool
 */ 

using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace GoogleCodeJam
{
    public struct Point
    {
        public double x, y;
    }

    public class CodeJam
    {
        static void Main(String[] args)
        {
            StreamReader reader = new StreamReader("C-small.in");
            StreamWriter writer = new StreamWriter("C-small.out");
            int testCases = int.Parse(reader.ReadLine());
            for (int caseNum = 0; caseNum < testCases; caseNum++)
            {
                int K = int.Parse(reader.ReadLine());
                string[] tmp = reader.ReadLine().Split(' ');

                int n = int.Parse(tmp[0]);
                List<int> qNum = new List<int>();
                for (int i = 1; i < tmp.Length; i++)
                {
                    qNum.Add(int.Parse(tmp[i]));
                }

                int[] perfectTrap = new int[K];
                int count = 1;
                int index = 0;
                for (int i = 1; i <= K; i++)
                {
                    while (count < i)
                    {
                        index = (index + 1) % K;
                        if (perfectTrap[index] == 0) count++;
                    }
                    perfectTrap[index] = i;
                    count = 0;
                }

                //for (int i = 0; i < K; i++)
                //{
                //    Console.Write(perfectTrap[i] + " ");
                //}
                //Console.WriteLine();

                writer.Write("Case #" + (caseNum + 1) + ": ");
                for (int i = 0; i < qNum.Count - 1; i++)
                {
                    writer.Write(perfectTrap[qNum[i] - 1] + " ");
                }
                writer.WriteLine(perfectTrap[qNum[qNum.Count - 1] - 1]);

                Console.WriteLine("Case #" + (caseNum + 1) + ": ");
                //for (int i = 0; i < qNum.Count - 1; i++ )
                //{
                //    Console.Write(perfectTrap[qNum[i] - 1] + " ");
                //}
                //Console.WriteLine(perfectTrap[qNum[qNum.Count-1] - 1]);
            }
            writer.Close();
            reader.Close();
        }
    }
}