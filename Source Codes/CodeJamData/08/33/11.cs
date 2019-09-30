using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static Int64 sum;
        static int[] T;
        
        static int C;
        static int Number;
       
        static Int64[] result;
        static int[] finalresult;
        static int final;
        static Int64[] miles;

        static StreamWriter sw1 = new StreamWriter("out1.txt");
          
        
        public static void cal(int N)
        {

            if (N == 0)
            {
                bool test = true;

                Int64 tmp = -1;
                Int64 tmp2 = 0;
                for (int i = 0; i < Number; i++)
                {
                    sw1.Write(result[i]);
                    if (result[i] == 0)
                    {
                        tmp2++;
                        if (tmp >= miles[i])
                        {
                            test = false;

                        }
                        tmp = miles[i];
                    }
                    
                    }
                    if ((test) && (tmp != -1)) sum++;
                    sw1.WriteLine();
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
        
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader("9.in");
            StreamWriter sw = new StreamWriter("out.txt");
            string line = sr.ReadLine();
            C = int.Parse(line);

            for (int i = 0; i < C; i++)
            {
                final = 10000;
                line = sr.ReadLine();
                string[] numlist = line.Split(new char[] { ' ' });

                int n = int.Parse(numlist[0]);
                int m = int.Parse(numlist[1]);
                Number = n;

                Int64 X = int.Parse(numlist[2]);
                Int64 Y = int.Parse(numlist[3]);
                Int64 Z = int.Parse(numlist[4]);

                Int64[] A = new Int64[m];
                miles = new Int64[n];

                for (int ii = 0; ii < m; ii++)
                {
                    line = sr.ReadLine();
                    A[ii] = int.Parse(line);

                }
              for (int ii = 0; ii < n; ii++)
              {
                  miles[ii] = A[ii % m];
                  A[ii % m] = (X * A[ii % m] + Y * (ii + 1)) % Z;
              }

              sum = 0;
              result = new Int64[n];

              for (int kk = 0; kk < n; kk++)
              {
                  result[kk] = 0;
              }
              result[0] = 1;
              for (int i1 = 1; i1 < n; i1++)
              {
                  result[i1] = 1;
                  for (int i2 = 0; i2 < i1; i2++)
                  {
                      if (miles[i2] < miles[i1])
                      {
                          result[i1] = result[i1] + result[i2];
                         result[i1] = result[i1] % 1000000007;
                      }
                      }
              }

              for (int iii = 0; iii < n; iii++)
              {
                  sum = sum + result[iii];
                  sum = sum % 1000000007;
              }

              //cal(n);
               //for (int k = 0; k < 
              Int64 result_all = sum % 1000000007;
                sw.WriteLine("Case #" + (int)(i + 1) + ": " + result_all);
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
