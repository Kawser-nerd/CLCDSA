using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{

    public class TextMessagingOutrage
    {
        private static int maxLetters;
        private static int keys;
        private static int letters;
        private static int[] frequency;

        private static string inputFile = "A0.in";
        private static string outputFile = "output.txt";
        private static FileStream fin;
        private static StreamReader sr;
        private static FileStream fout;
        private static StreamWriter sw;

       private static int count()
        {
           int num = 0;
           Array.Sort(frequency);

           int k = letters - 1;
           int numPresed = 0;
           while (k >= 0)
           {
               numPresed++;
               for (int i = 0; i < keys; i++)
               {
                   num += frequency[k] * numPresed;
                   k--;
                   if (k < 0)
                       break;
               }
           }

           return num;
        }

        public static void Solve()
        {
            fin = new FileStream(inputFile, FileMode.Open, FileAccess.Read);
            sr = new StreamReader(fin);
            fout = new FileStream(outputFile, FileMode.Create, FileAccess.Write);
            sw = new StreamWriter(fout);

            int numTestCases = Int32.Parse(sr.ReadLine());
            for (int t = 1; t <= numTestCases; t++)
            {
                string[] tmp = sr.ReadLine().Split(' ');
                maxLetters = Int32.Parse(tmp[0]);
                keys = Int32.Parse(tmp[1]);
                letters = Int32.Parse(tmp[2]);
                frequency = new int[letters];
                tmp = sr.ReadLine().Split(' ');
                for (int i = 0; i < letters; i++)
                    frequency[i] = Int32.Parse(tmp[i]);

                string output = "Case #" + t + ": " + count();
                sw.WriteLine(output);
            }

            sw.Close(); fout.Close();
            sr.Close(); fin.Close();
        }


    }

}
