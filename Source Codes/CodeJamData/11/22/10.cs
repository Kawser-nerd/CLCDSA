using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Diagnostics;

using System.Numerics;

namespace GoogleCodeJam
{
    class GCJ2011R2_B
    {
        string _Solve1()
        {
            var ss = _ReadLine().Split(' ');
            int C = int.Parse(ss[0]);   //  200
            int D = int.Parse(ss[1]);   //  10^6

            List<int> Ps = new List<int>();
            List<int> Vs = new List<int>();
            for (int i = 0; i < C; i++)
            {
                ss = _ReadLine().Split(' ');
                int P =int.Parse(ss[0]);    //  +-10^5
                int V = int.Parse(ss[1]);   //  10^6
                Ps.Add(P);
                Vs.Add(V);
            }

            double max = 0;
            for (int c = 1; c <= C; c++)
            {
                double t = 0;
                for (int s = 0; s + c <= C; s++)
                {
                    var ps2 = Ps.GetRange(s, c);
                    var vs2 = Vs.GetRange(s, c);

                    int init = ps2.Max() - ps2.Min();
                    int sumOfV = vs2.Sum(); //  10^6

                    t = 0.5 * ((long)D * (sumOfV - 1) - init);
                    max = Math.Max(t, max);
                }
            }

            return max.ToString();
        }


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
            var solver = new GCJ2011R2_B();
            foreach (var sub in new[] { "Sample", "Small", "Large" })
            {
                var inputFileName = @"..\..\"+solver.GetType().Name+"."+sub+".txt";
                var outputFileName = @"..\..\"+solver.GetType().Name+"."+sub+".out.txt";
                solver.Solve(inputFileName,outputFileName);
            }
        }


    }
}
