using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContestPractice
{
    class Welcome_to_Code_Jam
    {
        static void Main(string[] args)
        {
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Welcome_to_Code_Jam\\sample.txt";
            string strInputFile = "C:\\GoogleCodeJamInputOutput\\Welcome_to_Code_Jam\\C-small-attempt0.in";
            //string strInputFile = "C:\\GoogleCodeJamInputOutput\\Welcome_to_Code_Jam\\A-large.in";

            System.IO.TextReader tr = new StreamReader(strInputFile);
            System.IO.TextWriter tw = new StreamWriter(strInputFile + ".out.txt");

            int iTotalTestCases = Int32.Parse(tr.ReadLine());

            for (int iCase = 0; iCase < iTotalTestCases; iCase++)
            {
                para = tr.ReadLine();
                cache = new int[20][];
                for(int j =0 ; j < 20;j++)
                {
                    cache[j] = new int[1505];
                    for (int k = 0; k < 1505; k++) cache[j][k] = -1;
                }
                tw.WriteLine("Case #{0}: {1}", (1 + iCase), ("" + Count(0, 0)).PadLeft(4, '0'));
            }

            tr.Close();
            tw.Close();

            Console.WriteLine("press any key to continue");
            Console.ReadKey();
        }

        static string para = null;
        static string WTCJ = "welcome to code jam";
        //static string WTCJ = "wcj";
        static int[][] cache = null;

        private static int Count(int wtcj, int iSearchStartIndex)
        {
            //Console.WriteLine("{0}, {1}", wtcj, iSearchStartIndex);
            if (cache[wtcj][iSearchStartIndex] != -1) return cache[wtcj][iSearchStartIndex];
            if (wtcj >= WTCJ.Length) return 1; //count = (1 + count) % 9999;
            else
            {
                int count = 0;
                for (int i = iSearchStartIndex; i < para.Length; i++)
                {
                    if (para[i] == WTCJ[wtcj])
                    {
                        count = (count + Count(wtcj + 1, i + 1)) % 10000;
                    }
                }
                cache[wtcj][iSearchStartIndex] = count;
                return count;
            }
        }
        
    }
}
