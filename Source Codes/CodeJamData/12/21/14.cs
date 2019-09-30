using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ2012.Round1B
{
    public class A
    {
        public void Solve(string type)
        {
            string inputFile = GetType().Name + "-" + type + ".in";
            string outputFile = "Round1B/"+GetType().Name + "-" + type + ".out";

            var reader = new Reader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            //start

            int T = reader.GetInt();

            for (int i = 0; i < T; i++)
            {
                reader.NewLine();
                int N = reader.GetInt();

                var lst = reader.GetIntArray(N);

                int sum = lst.Sum();
                float m2 = ((float)2*sum)/N;

                String Case = "Case #" + (i + 1) + ": ";

                int L = lst.Where(x => x < m2).Count();
                int sumlower = lst.Where(x => x < m2).Sum();
                float newm2 = ((float)sumlower + sum) / L;

                for (int j = 0; j < N; j++)
                {
                    int pj = lst[j];
                    double res = 100 * ((double)(newm2 - pj)) / sum;
                    if (res < 0) res = 0;
                    Case += string.Format("{0:0.000000}", res).Replace(",", ".")+" ";
                }

                // write result
                
                tw.WriteLine(Case.Trim());

            }

            tw.Close();
            reader.Close();
        }



        #region reader
        private class Reader
        {
            private readonly StreamReader reader;
            private String[] valori;
            private int seek = 0;

            public Reader(string inputFile)
            {
                reader = new StreamReader(inputFile);
                NewLine();
            }

            public void NewLine()
            {
                string line = reader.ReadLine();
                valori = line.Split(' ');
                seek = 0;
            }

            public void Close()
            {
                reader.Close();
            }

            public int GetInt()
            {
                return int.Parse(valori[seek++]);
            }

            public long GetLong()
            {
                return long.Parse(valori[seek++]);
            }

            public float GetFloat()
            {
                return float.Parse(valori[seek++].Replace(".",","));
            }

            public double GetDouble()
            {
                return double.Parse(valori[seek++].Replace(".", ","));
            }

            public string GetString()
            {
                return valori[seek++];
            }

            public string[] GetStringArray(int count)
            {
                var array = new string[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetString();
                }
                return array;
            }

            public int[] GetIntArray(int count)
            {
                var array = new int[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetInt();
                }
                return array;
            }

            public long[] GetLongArray(int count)
            {
                var array = new long[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetLong();
                }
                return array;
            }

            public float[] GetFloatArray(int count)
            {
                var array = new float[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetFloat();
                }
                return array;
            }

            public double[] GetDoubleArray(int count)
            {
                var array = new double[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetDouble();
                }
                return array;
            }

            public int[,] GetIntMatrix(int h, int w)
            {
                var array = new int[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetInt();
                    }
                }

                return array;
            }

            public long[,] GetLongMatrix(int h, int w)
            {
                var array = new long[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetLong();
                    }
                }

                return array;
            }

            public string[,] GetStringMatrix(int h, int w)
            {
                var array = new string[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetString();
                    }
                }

                return array;
            }

            public float[,] GetFloatMatrix(int h, int w)
            {
                var array = new float[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetFloat();
                    }
                }

                return array;
            }

            public double[,] GetDoubleMatrix(int h, int w)
            {
                var array = new double[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetDouble();
                    }
                }

                return array;
            }

        }
        #endregion




    }


}
