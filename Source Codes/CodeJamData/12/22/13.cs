using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ2012.Round1B
{
    public class B
    {
        public void Solve(string type)
        {
            string inputFile = GetType().Name + "-" + type + ".in";
            string outputFile = "Round1B/" + GetType().Name + "-" + type + ".out";

            var reader = new Reader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            //start

            int T = reader.GetInt();

            for (int i = 0; i < T; i++)
            {
                reader.NewLine();
                int H = reader.GetInt();
                int N = reader.GetInt();
                int M = reader.GetInt();

                var ceil = reader.GetIntMatrix(N, M);

                var floor = reader.GetIntMatrix(N, M);

                double[,] pos = new double[N, M];
                for (int n = 0; n < N; n++)
                {
                    for (int m = 0; m < M; m++)
                    {
                        pos[n, m] = -1;
                    }
                }
                pos[0, 0] = 0;

                bool mod = true;

                while (mod)
                {
                    mod = false;
                    for (int n = 0; n < N; n++)
                    {
                        for (int m = 0; m < M; m++)
                        {
                            if (pos[n, m]!=0) continue;
                            if (n>0)
                            {
                                int n2 = n - 1;
                                int m2 = m;

                                int f = Math.Max(Math.Max(H, floor[n2, m2]), floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (pos[n2, m2] != 0 && c - f >= 50)
                                {
                                    pos[n2, m2] = 0;
                                    mod = true;
                                }
                            }
                            if (m > 0)
                            {
                                int n2 = n ;
                                int m2 = m-1;
                                int f = Math.Max(Math.Max(H, floor[n2, m2]), floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (pos[n2, m2] != 0 && c - f >= 50)
                                {
                                    pos[n2, m2] = 0;
                                    mod = true;
                                }
                            }
                            if (n < N-1)
                            {
                                int n2 = n + 1;
                                int m2 = m;
                                int f = Math.Max(Math.Max(H, floor[n2, m2]), floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (pos[n2, m2] != 0 && c - f >= 50)
                                {
                                    pos[n2, m2] = 0;
                                    mod = true;
                                }
                            }
                            if (m < M-1)
                            {
                                int n2 = n;
                                int m2 = m + 1;
                                int f = Math.Max(Math.Max(H, floor[n2, m2]), floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (pos[n2, m2] != 0 && c - f >= 50)
                                {
                                    pos[n2, m2] = 0;
                                    mod = true;
                                }
                            }
                        }
                    }
                }








                mod = true;

                while (mod)
                {
                    mod = false;
                    for (int n = 0; n < N; n++)
                    {
                        for (int m = 0; m < M; m++)
                        {
                            if (pos[n, m] < 0) continue;
                           
                            if (n > 0)
                            {
                                int n2 = n-1;
                                int m2 = m;

                                int f = Math.Max(floor[n2, m2], floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (c - f >= 50)
                                {
                                    double tx = Math.Max(pos[n, m], (H + 50 - ceil[n2, m2]) * 0.1);
                                    int wtx = H - (int)(10 * tx);
                                    if (wtx < 0) wtx = 0;
                                    int move = wtx - floor[n, m] >= 20 ? 1 : 10;
                                    double nt = tx + move;
                                    if (pos[n2, m2] < 0 || pos[n2, m2] > nt)
                                    {
                                        pos[n2, m2] = nt;
                                        mod = true;
                                    }
                                }

                               

                            }
                            if (m > 0)
                            {
                                int n2 = n;
                                int m2 = m - 1;
                                int f = Math.Max(floor[n2, m2], floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (c - f >= 50)
                                {
                                    double tx = Math.Max(pos[n, m], (H + 50 - ceil[n2, m2]) * 0.1);
                                    int wtx = H - (int)(10 * tx);
                                    if (wtx < 0) wtx = 0;
                                    int move = wtx - floor[n, m] >= 20 ? 1 : 10;
                                    double nt = tx + move;
                                    if (pos[n2, m2] < 0 || pos[n2, m2] > nt)
                                    {
                                        pos[n2, m2] = nt;
                                        mod = true;
                                    }
                                }

                                
                                
                            }
                            if (n < N - 1)
                            {
                                int n2 = n + 1;
                                int m2 = m;
                                int f = Math.Max(floor[n2, m2], floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (c - f >= 50)
                                {
                                    double tx = Math.Max(pos[n, m], (H + 50 - ceil[n2, m2]) * 0.1);
                                    int wtx = H - (int)(10 * tx);
                                    if (wtx < 0) wtx = 0;
                                    int move = wtx - floor[n, m] >= 20 ? 1 : 10;
                                    double nt = tx + move;
                                    if (pos[n2, m2] < 0 || pos[n2, m2] > nt)
                                    {
                                        pos[n2, m2] = nt;
                                        mod = true;
                                    }
                                }

                                
                                
                            }
                            if (m < M - 1)
                            {
                                int n2 = n;
                                int m2 = m + 1;
                                int f = Math.Max(floor[n2, m2], floor[n, m]);
                                int c = Math.Min(ceil[n2, m2], ceil[n, m]);
                                if (c - f >= 50)
                                {
                                    double tx = Math.Max(pos[n, m], (H + 50 - ceil[n2, m2]) * 0.1);
                                    int wtx = H - (int)(10 * tx);
                                    if (wtx < 0) wtx = 0;
                                    int move = wtx - floor[n, m] >= 20 ? 1 : 10;
                                    double nt = tx + move;

                                    if (pos[n2, m2] < 0 || pos[n2, m2] > nt)
                                    {
                                        pos[n2, m2] = nt;
                                        mod = true;
                                    }
                                }

                                
                            }
                            
                        }
                    }
                }

                double res = pos[N-1,M-1];
                // write result
                String Case = "Case #" + (i + 1).ToString() + ": " + string.Format("{0:0.000000}", res).Replace(",", ".");
                tw.WriteLine(Case);
                

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
