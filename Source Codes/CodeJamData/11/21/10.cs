using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Diagnostics;

using System.Numerics;

namespace GoogleCodeJam
{
    class GCJ2011R2_A
    {
        string _Solve1()
        {
            int N = int.Parse(_ReadLine()); //  100
            cs = new char[N][];
            for(int n=0;n<N;n++)
            {
                var s = _ReadLine();
                cs[n] = new char[N];
                for (int j = 0; j < N; j++)
                    cs[n][j] = s[j];
            }

            List<double> WPs = new List<double>();
            for (int i = 0; i < N; i++)
            {
                int all = 0;
                int win = 0;
                for (int j = 0; j < N; j++)
                {
                    if (cs[i][j] == '.')
                        continue;
                    if (cs[i][j] == '1')
                        win++;
                    all++;
                }
                if (all > 0)
                    WPs.Add((double)win / all);
                else
                    WPs.Add(0.0);   //  ok
            }

            List<double> OWPs = new List<double>();
            for (int i = 0; i < N; i++)
            {
                List<double> list = new List<double>();
                for (int j = 0; j < N; j++)
                {
                    if (cs[j][i] == '.')
                        continue;

                    int all = 0;
                    int win = 0;
                    for (int k = 0; k < N; k++)
                    {
                        if (k == i)
                            continue;
                        if (cs[j][k] == '.')
                            continue;
                        if (cs[j][k] == '1')
                            win++;
                        all++;
                    }

                    if (all == 0)
                        continue;
                    list.Add((double)win / all);
                }
                if (list.Count > 0)
                    OWPs.Add(list.Average());
                else
                    OWPs.Add(0.0);  //  error
            }


            List<double> OOWPs = new List<double>();
            for (int i = 0; i < N; i++)
            {
                List<double> list = new List<double>();
                for (int j = 0; j < N; j++)
                {
                    if (cs[i][j] == '.')
                        continue;
                    list.Add(OWPs[j]);
                }
                OOWPs.Add(list.Average());
            }

            string res="";
            for(int i=0;i<N;i++)
            {
                res+="\n";
                res += ( 0.25 * WPs[i] + 0.5 * OWPs[i] + 0.25 * OOWPs[i] ).ToString();
            }
            return res;
        }
        char[][] cs;



        public void Solve(string inputFileName, string outputFileName)
        {
            if (!File.Exists(inputFileName))
            {
                Debug.WriteLine("\nNot Exist " + inputFileName);
                return;
            }

            using (_sr = new StreamReader(inputFileName))
            using (_sw = new StreamWriter(outputFileName))
            {
                Debug.WriteLine("\nStart... " + inputFileName);

                int T = int.Parse(_ReadLine()); //  <=100
                for (int t = 1; t <= T; t++)
                {
                    var s = _Solve1();
                    _WriteLine(String.Format("Case #{0}: {1}", t, s));
                }
            }
        }




        StreamReader _sr;
        StreamWriter _sw;

        string _ReadLine()
        {
            return _sr.ReadLine();
        }

        void _Write(string s)
        {
            Debug.Write(s);
            _sw.Write(s);
        }

        void _WriteLine(string s)
        {
            _Write(s +System.Environment.NewLine );
        }

 
        static void Main(string[] args)
        {
            var solver = new GCJ2011R2_A();
            foreach (var sub in new[] { "Sample", "Small", "Large" })
            {
                var inputFileName = @"..\..\"+solver.GetType().Name+"."+sub+".txt";
                var outputFileName = @"..\..\"+solver.GetType().Name+"."+sub+".out.txt";
                solver.Solve(inputFileName,outputFileName);
            }
        }


    }
}
