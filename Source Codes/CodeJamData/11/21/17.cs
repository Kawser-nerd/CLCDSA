using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace R1B11A
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "A-large";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);


            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                // get all the data for your case here
                int numTeams = int.Parse(f.ReadLine());
                int[,] record = new int[numTeams, numTeams]; // [x, y] = 1 means x beat y

                for (int j = 0; j < numTeams; j++)
                {
                    s = f.ReadLine();

                    for (int k = 0; k < numTeams; k++)
                    {
                        if (s[k] == '1')
                            record[j, k] = 1;
                        else if (s[k] == '0')
                            record[j, k] = 0;
                        else
                            record[j, k] = -1;
                    }
                }
                computeCase(i + 1, numTeams, record);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
            System.Diagnostics.Process proc = new System.Diagnostics.Process();
            proc.StartInfo.FileName = "Upload.bat";
            proc.StartInfo.RedirectStandardError = false;
            proc.StartInfo.RedirectStandardOutput = false;
            proc.StartInfo.UseShellExecute = false;
            proc.Start();
            proc.WaitForExit();
        }
        public static void computeCase(int c, int T, int[,] rec)
        {
            double[] WP = new double[T];
            int[] g = new int[T];
            double[] OWP = new double[T];
            double[] OOWP = new double[T];
            for (int i = 0; i < T; i++)
            {
                int n = 0;
                int w = 0;
                for (int j = 0; j < T; j++)
                {
                    if (rec[i, j] > 0)
                        w++;
                    if (rec[i, j] >= 0)
                        n++;
                }
                g[i] = n;
                WP[i] = ((double)w) / n;
            }
            for (int i = 0; i < T; i++)
            {
                int n = 0;
                double r = 0;
                for (int j = 0; j < T; j++)
                {
                    if (rec[i, j] >= 0)
                    {
                        n++;
                        r += ((WP[j] * g[j]) - 1 + rec[i, j]) / (g[j] - 1);
                    }
                }
                OWP[i] = r / n;
            }
            for (int i = 0; i < T; i++)
            {
                int n = 0;
                double r = 0;
                for (int j = 0; j < T; j++)
                {
                    if (rec[i, j] >= 0)
                    {
                        n++;
                        r += OWP[j];
                    }
                }
                OOWP[i] = r / n;
            }
            outLines.Add("Case #" + c.ToString() + ":");
            for (int i = 0; i < T; i++)
            {
                outLines.Add((.25 * WP[i] + .5 * OWP[i] + .25 * OOWP[i]).ToString());
            }

        }
    }
}
