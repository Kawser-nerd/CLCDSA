using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RoundOne
{
    class ProgramA
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var T = Convert.ToInt32(input);

            var k = 1;
            while (k <= T)
            {
                var answer = ProcessTestCase();

                Console.WriteLine($"Case #{k}: {answer}");
                k++;
            }
        }

        internal static string ProcessTestCase()
        {
            var parameters = Console.ReadLine().Split(' ');
            var R = Convert.ToInt32(parameters[0]);
            var C = Convert.ToInt32(parameters[1]);

            var cakeStrings = new List<char[]>();
            foreach (var i in Enumerable.Range(1, R))
                cakeStrings.Add(Console.ReadLine().ToCharArray());

            var firstColWithChar = 0;
            for (int j = 0; j < C; j++)
            {
                var charInCol = false;
                for (int i = 0; i < R; i++)
                {
                    if (cakeStrings[i][j] != '?')
                    {
                        charInCol = true;
                        FillUpAndDown(cakeStrings, i, j);
                    }
                }

                if (!charInCol && j > firstColWithChar)
                {
                    CopyPreviousCol(cakeStrings, j);
                }
                else if (!charInCol)
                {
                    firstColWithChar++;
                }
            }

            //handle first cols
            while (firstColWithChar > 0)
            {
                firstColWithChar--;
                CopyNextCol(cakeStrings, firstColWithChar);
            }

            var answer = new StringBuilder();
            answer.AppendLine();
            foreach (var line in cakeStrings)
            {
                answer.AppendLine(new string(line));
            }
            return answer.ToString();
        }

        private static void CopyNextCol(List<char[]> cakeStrings, int col)
        {
            for (int i = 0; i < cakeStrings.Count; i++)
            {
                cakeStrings[i][col] = cakeStrings[i][col + 1];
            }
        }

        private static void CopyPreviousCol(List<char[]> cakeStrings, int col)
        {
            for (int i = 0; i < cakeStrings.Count; i++)
            {
                cakeStrings[i][col] = cakeStrings[i][col - 1];
            }
        }

        private static void FillUpAndDown(List<char[]> cakeStrings, int r, int c)
        {
            var ch = cakeStrings[r][c];
            for (int i = r - 1; i >= 0; i--)
            {
                if (cakeStrings[i][c] != '?') break;

                cakeStrings[i][c] = ch;
            }
            for (int i = r + 1; i < cakeStrings.Count; i++)
            {
                if (cakeStrings[i][c] != '?') break;

                cakeStrings[i][c] = ch;
            }
        }
    }
}
