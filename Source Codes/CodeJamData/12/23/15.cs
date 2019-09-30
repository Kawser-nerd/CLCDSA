using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

/* Yoel Grodentzik
 * thed0okie
 * C#
 * Equal Sums (C)
 */

namespace goroGCjam
{
    class GCJ20120R1SATc
    {
        static int NUM_BIN = 1048576;
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader(@"C:\C-small-attempt1.in");
            StreamWriter sw = new StreamWriter(@"C:\C-small-attempt1.out");

            int numCases = 0;
            numCases = Convert.ToInt32(sr.ReadLine());

            string[] strs = new string[NUM_BIN];
            for (int t = 0; t < NUM_BIN; t++)
                strs[t] = Convert.ToString(t, 2);
            for(int t = 0; t < NUM_BIN; t++)
            {
                while(strs[t].Length < 20)
                    strs[t] = '0' + strs[t];
            }
            for (int i = 0; i < numCases; i++)
            {
                int N = 0;

                string theLine = sr.ReadLine();
                string[] tmp = new string[20];
                tmp = theLine.Split(' ');

                int[] J = new int[20];
                for (int j = 0; j < 20; j++)
                    J[j] = Convert.ToInt32(tmp[j]);

                int THESUM = 0;
                Dictionary<int, string> myDict = new Dictionary<int, string>();
                string ans = "";
                for (int t = 0; t < NUM_BIN; t++)
                {
                    int s = 0;
                    string myS = strs[t];
                    for (int k = 0; k < 20; k++)
                    {
                        if (myS[k] == '1')
                            s += J[k];
                    }
                    if (myDict.ContainsKey(s))
                    {
                        ans = myS;
                        THESUM = s;
                        break;
                    }
                    else
                    {
                        myDict.Add(s, myS);
                    }
                }

                sw.WriteLine("Case #" + (i + 1) + ":");

                bool first = true;
                for(int j = 0; j < 20; j++)
                    if (ans[j] == '1')
                    {
                        if (first)
                        {
                            sw.Write(J[j]);
                            first = false;
                        }
                        else
                        {
                            sw.Write(" " + J[j]);
                        }
                    }
                sw.WriteLine();



                first = true;
                string ans2 = myDict[THESUM];

                for (int j = 0; j < 20; j++)
                    if (ans2[j] == '1')
                    {
                        if (first)
                        {
                            sw.Write(J[j]);
                            first = false;
                        }
                        else
                        {
                            sw.Write(" " + J[j]);
                        }
                    }
                sw.WriteLine();

            }




            sr.Close();
            sw.Close();
        }
    }
}
