using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA {
    class Program {
        static void Main(string[] args) {
            int T;
            int N, K;
            string[] tokens;
            int[] R;
            int[] H;
            double[] surfB;
            double[] surfH;
            double[] surfT;
            double totSurf;
            double maxSurf;
            double maxSurfR;
            double maxSurfB;
            int maxSurfIndex;

            double pi = Math.PI;
            double twoPi = Math.PI * 2;

            bool update;

            //string ioPath = @"D:\Aleaimo\Downloads\input";
            //string ioPath = @"D:\Aleaimo\Downloads\A-small-attempt1";
            string ioPath = @"D:\Aleaimo\Downloads\A-large";

            StreamReader sr = new StreamReader(ioPath + ".in");
            StreamWriter sw = new StreamWriter(ioPath + ".out", true);


            T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++) {
                tokens = sr.ReadLine().Split(' ');
                N = int.Parse(tokens[0]);
                K = int.Parse(tokens[1]);

                R = new int[N];
                H = new int[N];
                surfB = new double[N];
                surfH = new double[N];
                surfT = new double[N];

                maxSurf = 0.0;
                maxSurfIndex = 0;

                maxSurfR = 0.0;
                maxSurfB = 0.0;
                totSurf = 0.0;

                for (int n = 0; n < N; n++) {
                    tokens = sr.ReadLine().Split(' ');
                    R[n] = int.Parse(tokens[0]);
                    H[n] = int.Parse(tokens[1]);
                    surfB[n] = pi * R[n] * R[n];
                    surfH[n] = twoPi * R[n] * H[n];
                    surfT[n] = surfB[n] + surfH[n];

                    if (surfT[n] > maxSurf) {
                        maxSurfIndex = n;
                        maxSurf = surfT[n];
                    }

                }

                for (int k = 0; k < K; k++) {
                    totSurf += maxSurf;
                    if (R[maxSurfIndex] > maxSurfR) {
                        maxSurfR = R[maxSurfIndex];
                        maxSurfB = pi * maxSurfR * maxSurfR; 
                        update = true;
                    }
                    else {
                        update = false;
                    }

                    surfB[maxSurfIndex] = 0.0;
                    surfH[maxSurfIndex] = 0.0;
                    surfT[maxSurfIndex] = 0.0;

                    maxSurf = 0.0;
                    maxSurfIndex = 0;

                    for (int n = 0; n < N; n++) {
                        if(surfT[n] > 0.0) {
                            if (update) {
                                if (maxSurfR >= R[n]) {
                                    surfB[n] = 0.0;
                                }
                                else {
                                    surfB[n] = pi * R[n] * R[n] - maxSurfB;
                                }
                                surfT[n] = surfB[n] + surfH[n];
                            }

                            if (surfT[n] > maxSurf) {
                                maxSurfIndex = n;
                                maxSurf = surfT[n];
                            }

                        }
                    }

                }

                sw.WriteLine("Case #{0}: {1}", t + 1, totSurf.ToString().Replace(',', '.'));
                Console.WriteLine(t + 1);
            }

            sw.Close();

        }
    }
}
