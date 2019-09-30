using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_0C
    {
        const string fileName = "C-large-2";
        const string inputFile = fileName + ".in";
        const string outputFile = fileName + ".out";
        StreamReader reader = new StreamReader(inputFile);
        StreamWriter writer = new StreamWriter(outputFile);
        List<string> square = new List<string>();

        int maxDigits = 101;

        public void InitSquare(int totalDigits, int index, int middle, int[] baseDigits)
        {
            if (index == (totalDigits + 1) / 2)
            {
                int[] halfSquare = new int[totalDigits];
                for (int i = 0; i < index; i++)
                {
                    halfSquare[i + i] += baseDigits[i] * baseDigits[i];
                    if (totalDigits - 1 - i != i)
                    {
                        halfSquare[totalDigits - 1] += 2 * baseDigits[i] * baseDigits[i];
                    }
                    for (int j = i + 1; j < index; j++)
                    {
                        halfSquare[i + j] += 2 * baseDigits[i] * baseDigits[j];
                        if (totalDigits - j - 1 != j)
                        {
                            halfSquare[i + totalDigits - j - 1] += 2 * baseDigits[i] * baseDigits[j];
                        }
                    }
                }
                string wholeSquare = halfSquare[totalDigits - 1].ToString();
                for (int i = halfSquare.Length - 2; i >= 0; i--)
                {
                    wholeSquare = halfSquare[i].ToString() + wholeSquare + halfSquare[i].ToString();
                }
                square.Add(wholeSquare.PadLeft(maxDigits, '0'));
                //writer.WriteLine(square.Last());
                return;
            }
            for (int i = (index == 0) ? 1 : 0; i <= 3; i++)
            {
                int add = i * i * ((index * 2 + 1 == totalDigits) ? 1 : 2);
                if (middle + add <= 9)
                {
                    baseDigits[index] = i;
                    InitSquare(totalDigits, index + 1, middle + add, baseDigits);
                }
            }
        }

        public int bSearch(string x)
        {
            int left = 0, right = square.Count - 1, middle;
            int cmp;
            while (right > left)
            {
                middle = (left + right) / 2;
                cmp = square[middle].CompareTo(x);
                if (cmp == 0) return middle;
                else if (cmp < 0) left = middle + 1;
                else right = middle - 1;
            }
            cmp = square[left].CompareTo(x);
            return (cmp < 0) ? left + 1 : left;
        }

        public GCJ2013_0C()
        {
            char[] sep = { ' ' };
            for (int i = 1; i <= 51; i++)
            {
                InitSquare(i, 0, 0, new int[(i+1)/2]);
            }
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] s = reader.ReadLine().Split(sep);
                string A = s[0].PadLeft(maxDigits, '0');
                string B = s[1].PadLeft(maxDigits, '0');
                int x = bSearch(A), y=bSearch(B);
                int result = y - x;
                if (square[y] == B) result++;
                writer.WriteLine(String.Format("Case #{0}: {1}", (i + 1), result));
            }

            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_0C();
        }
    }
}
