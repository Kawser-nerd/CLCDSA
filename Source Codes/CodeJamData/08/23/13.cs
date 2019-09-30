using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace Round1C
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream file = new FileStream("C-small-attempt0.in", FileMode.OpenOrCreate, FileAccess.Read);
            StreamReader sr = new StreamReader(file);

            FileStream file2 = new FileStream("out.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(file2);

            String tempStr;
            Int32 numProb;

            tempStr = sr.ReadLine();
            numProb = Int32.Parse(tempStr);

            for (int i = 1; i <= numProb; i++)
            {
                long[] ans = FindAnswer(sr);
                sw.Write("Case #" + i + ": ");
                for (int j = 0; j < ans.Length-1; j++)
                    sw.Write(ans[j] + " ");

                sw.WriteLine(ans[ans.Length - 1]);

            }

            sw.Close();
            sr.Close();
            file.Close();
            file2.Close();
        }

        static long[] FindAnswer(StreamReader sr)
        {
            String tempStr;
            long numCards;

            tempStr = sr.ReadLine();
            numCards = Int32.Parse(tempStr);
            
            ArrayList myAL = new ArrayList();
            for (long i = 1; i <= numCards; i++)
            {
                myAL.Add(i);
            }

            long[] deck = new long[numCards + 1];
            long start = 0;
            for (long i = 1; i <= numCards; i++)
            {
                long x = (i - 1 + start) % myAL.Count;
                start = x;
                deck[(Int64)myAL[(int)x]] = i;
                myAL.Remove(myAL[(int)x]);
            }


            char[] seps = { ' ' };
            tempStr = sr.ReadLine();
            String[] sArr = tempStr.Split(seps);
            long n = Int64.Parse(sArr[0]);

            long[] ans = new long[n];
            for (long i = 0; i < n; i++)
            {
                ans[i] = deck[Int64.Parse(sArr[i + 1])];
            }

            return ans;

        }


    }
}
