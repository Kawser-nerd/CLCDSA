using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Test
{
    static class C
    {
        private const string inputFile = "c-small.in";
        private const string outputFile = "c-small.out";
        public static void Solve()
        {
            using (StreamReader reader = new StreamReader(inputFile))
            using (StreamWriter writer = new StreamWriter(outputFile, false))
            {
                int n = int.Parse(reader.ReadLine());
                for (int i = 1; i <= n; i++)
                {
                    Console.WriteLine("solving {0}/{1}", i, n);
                    writeCaseResult(writer, i, solveCase(reader));
                }
            }
        }
        private static string solveCase(StreamReader reader)
        {
            string result = string.Empty;
            string[] split = C.split(reader.ReadLine(), ' ');
            int m = int.Parse(split[0]);
            int n = int.Parse(split[1]);

            byte[,] board = buildBoard(reader, m, n);
            int maxPossible = Math.Min(n, m);

            SortedDictionary<int, int> found = new SortedDictionary<int, int>();
            found[maxPossible] = 0;
            while (maxPossible > 0)
            {
                if (find(board, m, n, maxPossible))
                    found[maxPossible]++;
                else
                    found[--maxPossible] = 0;
            }

            List<KeyValuePair<int, int>> lFound = new List<KeyValuePair<int, int>>(found.Where(c => c.Key > 0 && c.Value > 0));

            StringBuilder res = new StringBuilder(lFound.Count + Environment.NewLine);

            while (lFound.Count > 0)
            {
                KeyValuePair<int, int> cur = lFound[lFound.Count - 1];
                res.AppendFormat("{0} {1}", cur.Key, cur.Value);
                lFound.RemoveAt(lFound.Count - 1);
                if (lFound.Count > 0)
                    res.AppendLine();
            }

            result = res.ToString();
            return result;
        }

        private static bool find(byte[,] board, int m, int n, int size)
        {
            if (size == 0)
                return false;

            bool found = false;
            int i = 0;
            int j = 0;
            for (i = 0; i <= m - size; i++)
            {
                for (j = 0; j <= n - size; j++)
                {
                    if (checkSize(board, i, j, size))
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    break;
            }

            if (found)
            {
                for (int k = 0; k < size; k++)
                    for (int l = 0; l < size; l++)
                        board[i + k, j + l] = 2;
            }

            return found;
        }

        private static bool checkSize(byte[,] board, int m, int n, int size)
        {
            bool baseColor = board[m, n] == 0;
            for (int i = 0; i < size; i++)
            {
               for (int j = 0; j < size; j++)
               {
                   if (board[m + i, n + j] != 0 && board[m + i, n + j] != 1)
                       return false;
                   bool color = board[m + i, n + j] == 0;
                   bool sameAsBase = color == baseColor;
                   bool needSame = ((i + j)%2) == 0;

                   if (sameAsBase != needSame)
                       return false;
               }
            }

            return true;
        }

        private static byte[,] buildBoard(StreamReader reader, int m, int n)
        {
            byte[,] board = new byte[m, n];
            for (int i = 0; i < m; i++)
            {
                string line = reader.ReadLine();
                int ni = n >> 2;
                for (int j = 0; j < ni; j++)
                {
                    int val = int.Parse(line[j].ToString(), System.Globalization.NumberStyles.HexNumber);

                    int baseIndex = j*4;
                    board[i, baseIndex++] = (byte)((val & 8)/8);
                    board[i, baseIndex++] = (byte)((val & 4)/3);
                    board[i, baseIndex++] = (byte)((val & 2)/2);
                    board[i, baseIndex] = (byte)((val & 1));
                }
            }

            return board;
        }
        private static void writeCaseResult(TextWriter writer, int caseNumber, string result)
        {
            writer.WriteLine("Case #{0}: {1}", caseNumber, result);
        }
        private static string[] split(string line, char del)
        {
            return line.Split(new char[] { del }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
