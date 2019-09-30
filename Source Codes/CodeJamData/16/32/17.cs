using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam2016Library
{
    public class Problem1C_B
    {
        public static string Run(string input)
        {
            StringBuilder output = new StringBuilder();
            string[] lines = input.Split('\n');

            int i = 0;
            int cases = int.Parse(lines[i++]);

            for (int c = 0; c < cases; c++)
            {
                string[] caseinput = lines[i++].Split(' ');
                string caseoutput = RunCase(long.Parse(caseinput[0]), long.Parse(caseinput[1]));
                output.Append("Case #" + (c + 1) + ": " + caseoutput);
            }

            return output.ToString();
        }

        private static string RunCase(long B, long M)
        {
            StringBuilder output = new StringBuilder();

            if (M > Math.Pow(2, B - 2))
                output.AppendLine("IMPOSSIBLE");
            else
            {
                output.AppendLine("POSSIBLE");

                char[,] matrix = new char[B, B];
                for (int i =0; i< B; i++)
                    for (int j=0; j< B; j++)
                    {
                        if (i < j)
                            matrix[i, j] = '1';
                        else
                            matrix[i, j] = '0';

                    }

                double objective = M;
                for (int i=1; i< B-1; i++)
                {
                    double valor = Math.Pow(2, B - 2 - i);
                    if (objective > valor)
                    {
                        matrix[0, i] = '1';
                        objective -= valor;

                    }
                    else
                    {
                        matrix[0, i] = '0';
                    }
                }
                if (objective > 0)
                    matrix[0, B-1] = '1';

                //print
                for (int i = 0; i < B; i++)
                {
                    for (int j = 0; j < B; j++)
                    {
                        output.Append(matrix[i, j]);
                    }
                    output.AppendLine();
                }
            }


            return output.ToString();
        }
        
        

    }

}
