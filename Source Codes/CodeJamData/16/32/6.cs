using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class Slides : AbstractSolver
    {
        private int B;
        private long M;
        private int[,] matrix;

        protected override object Solve(System.IO.StreamReader input)
        {
            B = NextInt();
            M = NextLong();

            matrix = new int[B, B];

            for (int i = 0; i < B; i++)
            {
                for (int j = i + 1; j < B - 1; j++)
                {
                    matrix[i, j] = 1;
                }
            }

            if (M == 1L << (B - 2))
            {
                for (int i = 0; i < B - 1; i++)
                {
                    matrix[i, B - 1] = 1;
                }
            }
            else if (M > 1L << (B - 2))
            {
                return "IMPOSSIBLE";
            }
            else
            {
                for (int i = 1; i < B - 1; i++)
                {
                    if (M % 2 == 1)
                    {
                        matrix[i, B - 1] = 1;
                    }
                    M /= 2;
                }
            }
            return matrixToString();
        }

        private string matrixToString()
        {
            var result = "POSSIBLE";
            for (int i = 0; i < B; i++)
            {
                result += "\n";
                for (var j = 0; j < B; j++)
                {
                    result += matrix[i, j];
                }

            }
            return result;
        }
    }
}
