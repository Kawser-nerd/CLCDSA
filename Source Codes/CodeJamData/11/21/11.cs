using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A1cs
{
    class Program
    {
        const int NMAX = 100;
        static void Main()
        {
            TextReader fin = File.OpenText("input.txt");
            TextWriter fout = File.CreateText("output.txt");
            int t = int.Parse(fin.ReadLine());
            for (int q = 0; q < t; q++)
            {
                fout.WriteLine("Case #{0}: ", q + 1);
                int n = int.Parse(fin.ReadLine());
                bool[,] played = new bool[n,n];
                bool[,] res = new bool[n, n];
                int[] lost = new int[n];
                int[] win = new int[n];
                double[] wp = new double[n];
                double[] owp = new double[n];
                double[] oowp = new double[n];
                for (int i = 0; i < n; i++)
                {
                    string s = fin.ReadLine();
                    for (int j = 0; j < n; j++)
                        switch (s[j])
                        {
                            case '.':
                                {
                                    break;
                                }
                            case '0':
                                {
                                    played[i, j] = true;
                                    res[i, j] = false;
                                    lost[i]++;
                                    break;
                                }
                            case '1':
                                {
                                    played[i, j] = true;
                                    res[i, j] = true;
                                    win[i]++;
                                    break;
                                }
                        }
                     wp[i] = (double)(win[i]) / (win[i] + lost[i]);
                }
                
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                        if (played[i, j])
                        {
                            
                            if (res[i, j]) owp[i] += ((double)(win[j]) / (win[j] + lost[j] - 1));
                            else owp[i] += ((double)(win[j] - 1) / (win[j] + lost[j] - 1));
                        }
                    owp[i] /= lost[i] + win[i]; 
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                        if (played[i, j])
                        {
                           oowp[i] += owp[j];
                        }
                    oowp[i] /= lost[i] + win[i];
                }
                for (int i = 0; i < n; i++)
                {
                    double rpi = 0;
                    rpi += wp[i] / 4;
                    rpi += owp[i] / 2;
                    rpi += oowp[i] / 4;
                    fout.WriteLine(rpi);
                }
            }
            fin.Close();
            fout.Close();
        }
    }
}
