using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

namespace Code_Jam_Qualification_Round
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader SR = new StreamReader(@"C:\Users\evelyne\Desktop\C-small-attempt0.in");
            StreamWriter SW = new StreamWriter(@"C:\Users\evelyne\Desktop\C-small-attempt0.out");

            string line;
            string[] words;
            int NoTests = 0;

            line = SR.ReadLine();
            NoTests = Int32.Parse(line);

            int K = 0;

            for (int Q = 1; Q <= NoTests; ++Q)
            {
                line = SR.ReadLine();
                K = Int32.Parse(line);

                line = SR.ReadLine();
                words = line.Split();


                ArrayList A = new ArrayList();

                for (int i = 1; i <= K; ++i)
                    A.Add(i);

                int[] level = new int[K];
                int poz, val, leg = 0;

                for (int i = 1; i <= K; ++i)
                {
                    poz = (leg + i - 1) % A.Count;

                    val = (int)A[poz];
                    A.RemoveAt(poz);

                    leg = poz;

                    level[val - 1] = i;
                }



                SW.Write("Case #{0}:", Q);
                for (int i = 1; i < words.Length; ++i)
                    SW.Write(' ' + level[Int32.Parse(words[i]) - 1].ToString());
                SW.WriteLine();
            }

            SW.Flush();
            SW.Close();
        }
    }
}
