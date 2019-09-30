using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ2012.Round1B
{
    public class C
    {

        public string binary(int number)
        {
            if (number <= 1)
            {
                return number.ToString();
            }

            return binary(number >> 1) + (number % 2);
        }

        public void Solve(string type)
        {
            string inputFile = GetType().Name + "-" + type + ".in";
            string outputFile = "Round1B/" + GetType().Name + "-" + type + ".out";

            var reader = new Reader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            //start

            int T = reader.GetInt();

            int[] pow = new int[20];

            int v = 1;
            for (int i = 0; i < 20; i++)
            {
                pow[i] = v;
                v *= 2;
            }

            for (int i = 0; i < T; i++)
            {
                reader.NewLine();
                int N = reader.GetInt();

                var lst = reader.GetIntArray(N);

                string[] res = result(lst, N);


                // write result
                String Case = "Case #" + (i + 1).ToString() + ": ";
                tw.WriteLine(Case);
                for (int j = 0; j < res.Length; j++)
                {
                    tw.WriteLine(res[j]);
                }


            }

            tw.Close();
            reader.Close();
        }


        private string[] result(int[] lst, int N)
        {
            List<string> res = new List<string>();

            long n2 = (long)Math.Pow(2, N);

            var ress = new Dictionary<int, string>();

            for (int j = 1; j < n2; j++)
            {
                var bx = binary(j).PadLeft(N, '0');
                char first = bx[0];

                string l1 = "";
                string l2 = "";
                int s1 = 0;
                int s2 = 0;

                for (int k = 0; k < N; k++)
                {
                    int lx = lst[k];
                    if (bx[k] == first)
                    {
                        l1 += lx + " ";
                        s1 += lx;
                    }
                    else
                    {
                        l2 += lx + " ";
                        s2 += lx;
                    }
                }
                if (!ress.ContainsKey(s1)) { ress.Add(s1, l1); }
                else
                {
                    if (ress[s1] != l1)
                    {
                        res.Add(ress[s1]);
                        res.Add(l1);
                        return res.ToArray();
                    }
                }
                if (!ress.ContainsKey(s2)) { ress.Add(s2, l2); }
                else
                {
                    if (ress[s2] != l2)
                    {
                        res.Add(ress[s2]);
                        res.Add(l2);
                        return res.ToArray();
                    }
                }
            }

            return new string[] { "Impossible" };

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
                return float.Parse(valori[seek++].Replace(".", ","));
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
