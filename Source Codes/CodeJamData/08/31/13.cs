using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static int[] T;
        static int[]X;
        static int[][] Y;
        static int C;
        static int Number;
        static int M;
        static int[] result;
        static int[] finalresult;
        static int final;
        static StreamWriter sw1 = new StreamWriter("out1.txt");
          
        /*
        public static void cal(int N)
        {

            if (N == 0)
            {

                List<int> L = new List<int>();
                for (int i = 0; i < Number; i++)
                {
                    sw1.Write(result[i]);
                    if (result[i] == 0) L.Add(i + 1);
                }
                sw1.WriteLine("result.Length = " + result.Length);
                bool test2 = false;

               
                    
                    for (int i = 0; i < M; i++)
                {
                    bool test = true;
                    for (int j = 0; j < T[i]; j++)
                    {
                        if ((Y[i][j] == 0) && (L.Contains(X[i][j]))) test = false;
                        if ((Y[i][j] != 0) && (!(L.Contains(X[i][j])))) test = false;
                    }
                    if (test) { test2 = true; };

                }
                if ((Number - L.Count < final) && (!test2))
                {
                    final = Number - L.Count;
                    for (int jjj = 0; jjj < Number; jjj++)
                    {
                        finalresult[jjj] = result[jjj];
                    }
                }
                }
            else 
            {
                result[N - 1] = 1;
                cal(N - 1);
                
                result[N - 1] = 0;
                cal(N - 1);
            }

            //if (N > 0) 

        }
        */
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader("7.in");
            StreamWriter sw = new StreamWriter("out.txt");
            string line = sr.ReadLine();
            C = int.Parse(line);

            for (int i = 0; i < C; i++)
            {
                final = 10000;
                line = sr.ReadLine();



                string[] numlist = line.Split(new char[] { ' ' });

                int P = int.Parse(numlist[0]);
                int Key = int.Parse(numlist[1]);
               
                int Max = int.Parse(numlist[2]);

               T = new int[Max];

                line = sr.ReadLine();
                numlist = line.Split(new char[] { ' ' });

                for (int j = 0; j < numlist.Length; j++)
                {
                    T[j] = int.Parse(numlist[j]);
                }
                Int64 sum = 0;
                List<int> L = new List<int>();
                for (int k = 0; k < Max; k++)
                {
                    L.Add(T[k]);
                }
                L.Sort();
                int last = L.Count - 1;

                //if (last < 0) sw.WriteLine("Case #" + (int)(i + 1) + ": " + sum);
                for (int kk = 0; kk < P; kk++)
                {
                    for (int k = 0; k < Key; k++)
                    {
                        if (last >= 0 )
                        {
                            sum = sum + (kk + 1) * L[last];
                            last --;
                        }
                    }
                }
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + sum);
            }


               
                //X[kk] = new int[T[kk]];
                
                //Y[kk] = new int[T[kk]];
                /*
                    int testx = 0;
                    int testy = 0;
                    for (int j = 0; j < numlist.Length - 1; j++)
                    {
                        if ((j % 2) == 0)
                        {
                            X[kk][testx] = int.Parse(numlist[j + 1]);
                            testx++;
                        }
                    }
                    for (int j = 0; j < numlist.Length - 1; j++)
                    {
                        if ((j % 2) != 0)
                        {
                            Y[kk][testy] = int.Parse(numlist[j + 1]);
                            testy++;
                            //Y[kk][j] = int.Parse(numlist[j + 2]);
                        }
                    }
                }

                for (int rr = 0; rr < Number; rr++)
                {
                    result[rr] = 0;
                }
                cal(Number);
                if (final == 10000) sw.WriteLine("IMPOSSIBLE");
                else
                {
                    sw.Write("Case #" + (int)(i + 1) + ": ");
                    for (int jjj = 0; jjj < Number; jjj++)
                    {
                         sw.Write(finalresult[jjj] + " ");
                    }
                    sw.WriteLine();
                    }
            }
                 */ 
            sr.Close();
            sw.Close();
            sw1.Close();
        }
    }
}
