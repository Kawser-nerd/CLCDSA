using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Diagnostics;


namespace _1B_A
{

    class Program
    {

        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                str = Console.ReadLine();
                int N = int.Parse(str);
                strs = new string[N];

                for (int i = 0; i < N; i++)
                {
                    strs[i] = Console.ReadLine();
                }

                Console.WriteLine("Case #" + caseNumber + ":");

                double[] OWP = new double[N];

                for (int i = 0; i < N; i++)
                {
                    List<double> d = new List<double>();
                    //ex.BのOWP
                    for (int j = 0; j < N; j++)
                    {
                        if (strs[i][j] == '.') { continue; }
                        //ex.AのBを除いたWP
                        int battleCount = 0;
                        int winCount = 0;
                        for (int k = 0; k < N; k++)
                        {
                            if (i == k) { continue; }
                            switch (strs[j][k])
                            {
                                case '.':
                                    break;
                                case '1':
                                    battleCount++;
                                    winCount++;
                                    break;
                                case '0':
                                    battleCount++;
                                    break;
                            }
                        }
                        d.Add(winCount / (double)battleCount);
                    }
                    OWP[i] = d.Average();
                }


                
                for (int j = 0; j < N; j++)
                {
                    double WP;
                    double OOWP;
                    List<double> OWPs = new List<double>();
                    //ex.AのWP
                    int battleCount = 0;
                    int winCount = 0;
                    for (int k = 0; k < N; k++)
                    {
                        switch (strs[j][k])
                        {
                            case '.':
                                break;
                            case '1':
                                battleCount++;
                                winCount++;
                                OWPs.Add(OWP[k]);
                                break;
                            case '0':
                                battleCount++;
                                OWPs.Add(OWP[k]);
                                break;
                        }
                    }
                    WP = winCount / (double)battleCount;
                    OOWP = OWPs.Average();

                    Console.WriteLine((WP * 0.25 + OWP[j] * 0.5 + OOWP * 0.25).ToString());
                }

                        





            }
            Debug.WriteLine("fin");

            Console.ReadLine();

        }
    }
}
