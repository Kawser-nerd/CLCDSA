using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GoogleJam
{
    class Program
    {
        static int[] ProcessTimes(int[][] timesa, int[][] timesb, int turnaround)
        {
            int[] result = new int[2];
            List<Int32> trainsa = new List<int>();
            List<Int32> trainsb = new List<int>();

            int ia = 0;
            int ib = 0;
            while (ia < timesa.Length || ib < timesb.Length)
            {
                if ((ib >= timesb.Length) || ((ia < timesa.Length) && (timesa[ia][0] < timesb[ib][0])))
                {
                    if ((trainsa.Count > 0) && (trainsa[0] <= timesa[ia][0]))
                        trainsa.RemoveAt(0);
                    else
                        result[0]++;
                    trainsb.Add(timesa[ia][1] + turnaround);
                    trainsb.Sort();
                    ia++;
                }
                else
                {
                    if ((trainsb.Count > 0) && (trainsb[0] <= timesb[ib][0]))
                        trainsb.RemoveAt(0);
                    else
                        result[1]++;
                    trainsa.Add(timesb[ib][1] + turnaround);
                    trainsa.Sort();
                    ib++;
                }
            }
            return result;
        }

        static int[][] ReadTimes(StreamReader reader, int n)
        {
            string[] r = new string[n];
            int[][] result = new int[n][];
            for (int i = 0; i < n; i++)
                r[i] = reader.ReadLine();
            Array.Sort(r);
            for (int i = 0; i < n; i++)
            {
                string[] s = r[i].Split(new char[] { ' ' });
                string[] s1 = s[0].Split(new char[] { ':' });
                string[] s2 = s[1].Split(new char[] { ':' });
                result[i] = new int[2];
                result[i][0] = Int32.Parse(s1[0]) * 60 + Int32.Parse(s1[1]);
                result[i][1] = Int32.Parse(s2[0]) * 60 + Int32.Parse(s2[1]);
            }
            return result;
        }

        [STAThread]
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"C:\!Install\Input.txt");
            StreamWriter writer = new StreamWriter(@"C:\!Install\Output.txt");
            int tasks = Int32.Parse(reader.ReadLine());
            for(int t = 0; t < tasks; t++)
            {
                Console.Out.WriteLine();
                Console.Out.WriteLine(String.Format("{0}", t));
                int n = Int32.Parse(reader.ReadLine());
                string[] tmp = reader.ReadLine().Split(new char[] { ' ' });
                int indexu = Int32.Parse(tmp[0]);
                int[] d_orig = new int[indexu];
                for (int j = 0; j < indexu; j++)
                    d_orig[j] = Int32.Parse(tmp[j + 1]) - 1;
                int[] d = new int[indexu];
                for (int j = 0; j < indexu; j++)
                    d[j] = d_orig[j];
                Array.Sort(d);
                int[] result = new int[indexu];
                for(int j = 0; j < indexu; j++)
                    result[j] = -1;
                int[] diry = new int[indexu];
                diry[0] = d[0] + (n - 1 - d[indexu - 1]);
                for(int i = 1; i < indexu; i++)
                    diry[i] = d[i] - d[i - 1] - 1;
                int aktualni_dira = 0;
                int zbyva_do_konce_diry = d[0];
                for (int i = 1; i <= n; i++)
                {
                    if (i % 10000 == 0)
                        Console.Out.Write(String.Format("{0} ", i / 10000));
                    int cislo = i;
                    while(cislo > 0)
                    {
                        if (cislo <= zbyva_do_konce_diry)
                        {
                            zbyva_do_konce_diry -= cislo;
                            diry[aktualni_dira] -= 1;
                            cislo = 0;
                            continue;
                        }

                        cislo -= zbyva_do_konce_diry;
                        zbyva_do_konce_diry = 0;

                        if ((cislo == 1) && (result[aktualni_dira] == -1))
                        {
                            result[aktualni_dira] = i;
                            aktualni_dira = (aktualni_dira + 1) % indexu;
                            zbyva_do_konce_diry = diry[aktualni_dira];
                            cislo = 0;
                            continue;
                        }

                        if (result[aktualni_dira] == -1)
                            cislo --;

                        aktualni_dira = (aktualni_dira + 1) % indexu;
                        zbyva_do_konce_diry = diry[aktualni_dira];
                    }
                }

                writer.Write(String.Format("Case #{0}:", t + 1));
                for (int i = 0; i < indexu; i++)
                {
                    for (int j = 0; j < indexu; j++)
                    {
                        if (d_orig[i] == d[j])
                        {
                            writer.Write(String.Format(" {0}", result[j]));
                            break;
                        }
                    }
                }
                writer.WriteLine();
            }
            reader.Close();
            writer.Close();
        }
    }
}

                //string[] tmp = reader.ReadLine().Split(new char[] { ' ' });
                //int n, A, B, C, D, x0, y0, M;
                //n = Int32.Parse(tmp[0]);
                //A = Int32.Parse(tmp[1]);
                //B = Int32.Parse(tmp[2]);
                //C = Int32.Parse(tmp[3]);
                //D = Int32.Parse(tmp[4]);
                //x0 = Int32.Parse(tmp[5]);
                //y0 = Int32.Parse(tmp[6]);
                //M = Int32.Parse(tmp[7]);
                //int X = x0;
                //int Y = y0;
                //writer.WriteLine(String.Format("{0} {1}", X, Y));
                //for(int i = 0; i < n; i++)
                //{
                //    X = (A * X + B) % M;
                //    Y = (C * Y + D) % M;
                //    writer.WriteLine(String.Format("{0} {1}", X, Y));
                //}

                //break;
