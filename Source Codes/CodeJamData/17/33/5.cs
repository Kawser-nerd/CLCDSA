using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2017r1c
{
    class ProblemC : IProblemSolver
    {
        public bool UsedBruteForce
        {
            get
            {
                return false;
            }
        }

        public string BruteForce(int caseNo)
        {
            throw new NotImplementedException();
        }

        int N, K;
        double U;
        List<double> P;

        public void ProcessInput()
        {
            var data = GCJ.io.nextLineSeparatedAsInt();
            N = data[0];
            K = data[1];
            U = GCJ.io.nextLineAsDouble();
            P = GCJ.io.nextLineSeparatedAsDouble().ToList();
            P.Sort();
        }

        public void Seed()
        {

        }

        public string Solve(int caseNo)
        {
            bool stop = false;
            P.Add(1.0);
            for (int i = 1; i < P.Count && !stop; i++)
            {
                var diff = P[i] - P[i - 1];
                if (diff * i > U)
                {
                    stop = true;
                    diff = U / i;
                }
                for (int j = 0; j < i; j++) P[j] += diff;
                U -= diff * i;
            }
            var res = 1.0;
            for (int i = 0; i < P.Count; i++) res *= P[i];
            return res.ToString();
        }
    }
}
