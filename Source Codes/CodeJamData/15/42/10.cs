using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

// The solution might use the C5 C# library, available at http://www.itu.dk/research/c5/

namespace GCJ
{
    class Program
    {
      


        static void Main(string[] args)
        {

            var root = @"D:\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            
            double[] data = input.SelectMany(x => x.Split(' ').Select(y => double.Parse(y))).ToArray();
            IEnumerator<double> scanner = data.AsEnumerable<double>().GetEnumerator();
            scanner.MoveNext();
            long numCases = Convert.ToInt64(scanner.Current + 0.1);
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int N = Convert.ToInt32(scanner.Current + 0.1);
                scanner.MoveNext();
                double V = scanner.Current;
                scanner.MoveNext();
                double X = scanner.Current;

                List<Tuple<double, double>> flows = new List<Tuple<double, double>>();

                for (int i = 0; i < N; ++i)
                {
                    scanner.MoveNext();
                    double R = scanner.Current;

                    scanner.MoveNext();
                    double C = scanner.Current;

                    flows.Add(Tuple.Create(R, C));
                }

                double res = 0.0;
                bool pos = true;
                if (flows.Count == 1)
                {
                    Console.WriteLine("here1 {0} {1} {2} {3}", flows[0].Item1, flows[0].Item2, V, X);
                    if (Math.Abs(flows[0].Item2 - X) > 0.00000001)
                    {
                        pos = false;
                    }
                    else
                    {
                        res = V / flows[0].Item1;
                    }
                }
                else
                {
                    Console.WriteLine("here2 {0} {1} {2} {3} {4} {5}", flows[0].Item1, flows[0].Item2, flows[1].Item1, flows[1].Item2, V, X);
                    if (Math.Abs(flows[0].Item2 - flows[1].Item2) < 0.0000001)
                    {
                        if (Math.Abs(flows[0].Item2 - X) > 0.000000001)
                        {
                            pos = false;
                        }
                        else
                        {
                            res = V / (flows[0].Item1 + flows[1].Item1);
                        }
                    }
                    else
                    {

                        double V0 = (V * X - V * flows[1].Item2) / (flows[0].Item2 - flows[1].Item2);
                        double V1 = V - V0;
                        if (flows[0].Item2 > X && flows[1].Item2 > X || flows[0].Item2 < X && flows[1].Item2 < X)
                        {
                            pos = false;
                        }
                        else
                        {
                            res = Math.Max(V0 / flows[0].Item1, V1 / flows[1].Item1);
                        }
                    }
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, !pos ? "IMPOSSIBLE" : String.Format("{0:0.00000000}", res));
                Console.WriteLine("Case #{0}: {1}", nc + 1, !pos ? "IMPOSSIBLE" : String.Format("{0:0.00000000}", res));
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
