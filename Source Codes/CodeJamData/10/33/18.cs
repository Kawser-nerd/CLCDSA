using System;
using System.IO;
using System.Text;

namespace Problem_C
{
    class Program
    {
        static string[] input;
        static int cur = 0;
        const string test = "C-test";
        const string small = "C-small";
        const string large = "C-large";
        static void Main(string[] args)
        {
            string currentFile = small;
            input = File.ReadAllLines(@"..\..\" + currentFile + ".in");
            StreamWriter f = File.CreateText(@"..\..\" + currentFile + ".out");

            int T = ReadInt();
            for (int i = 1; i <= T; i++)
            {
                int[] temp = ReadInts();
                int M = temp[0];
                int N = temp[1];
                string[] board = new string[M];
                for (int j = 0; j < M; j++)
                {
                    StringBuilder s = new StringBuilder(N);
                    string s1 = ReadString();
                    for (int k = 0; k < N / 4; k++)
                    {
                        char c = s1[k];
                        string binaryVal = Convert.ToString(Convert.ToInt32((c.ToString()), 16), 2);
                        binaryVal = binaryVal.PadLeft(4, '0');
                        s.Append(binaryVal);
                    }
                    board[j] = s.ToString();
                }
                int size = M < N ? M : N;
                int[] results = new int[size];
                int result = 0;
                for (int j = size; j > 0; j--)
                {
                    int ans = IsSquare(board, j);;
                    results[j - 1] = ans;
                    if(ans != 0)
                        result++;
                }
                f.WriteLine("Case #" + i.ToString() + ": " + result.ToString());
                for (int j = size; j > 0; j--)
                {
                    if (results[j - 1] != 0)
                        f.WriteLine(j.ToString() + " " + results[j - 1].ToString());
                }
            }
            f.Close();
        }

        static int IsSquare(string[] board, int n)
        {
            int count = 0;
            StringBuilder s1 = new StringBuilder(n);
            StringBuilder s2 = new StringBuilder(n);
            StringBuilder temp = new StringBuilder(n);
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    s1.Append('0');
                    s2.Append('1');
                }
                else
                {
                    s2.Append('0');
                    s1.Append('1');
                }
                temp.Append('a');
            }
            string pattern1 = s1.ToString();
            string pattern2 = s2.ToString();
            string pad = temp.ToString();

            int startIndex = 0;
            for (int i = 0; i < board.Length - n + 1;)
            {
                int index1 = board[i].IndexOf(pattern1,startIndex);
                int index2 = board[i].IndexOf(pattern2, startIndex);
                if(index1 == -1 && index2 == -1)
                {
                    i++;
                    startIndex = 0;
                    continue;                    
                }
                int index;
                string pattern, patternX;
                if (index1 < startIndex)
                {
                    index = index2;
                    pattern = pattern2;
                    patternX = pattern1;
                }
                else if (index2 < startIndex)
                {
                    index = index1;
                    pattern = pattern1;
                    patternX = pattern2;
                }
                else
                {
                    index = index1 < index2 ? index1 : index2;
                    pattern = index1 < index2 ? pattern1 : pattern2;
                    patternX = index1 > index2 ? pattern1 : pattern2;
                }
                if (index != -1)
                {
                    bool proper = true;
                    int x = 0;
                    for (int j = i + 1; j < i + n; j++)
                    {
                        if (x % 2 == 0)
                        {
                            if (board[j].IndexOf(patternX, index, n) != index)
                            {
                                proper = false;
                                break;
                            }
                        }
                        else
                        {
                            if (board[j].IndexOf(pattern, index, n) != index)
                            {
                                proper = false;
                                break;
                            }
                        }
                        x++;
                    }
                    if (proper)
                    {
                        count++;
                        for (int j = i; j < i + n; j++)
                        {
                            board[j] = board[j].Remove(index, n);
                            board[j] = board[j].Insert(index, pad);
                        }
                    }
                    else
                    {
                        startIndex = index + 1;
                        if (startIndex > board[i].Length - n)
                        {
                            i++;
                            startIndex = 0;
                        }
                        continue;
                    }
                }
            }
            return count;
        }

        //-----------------Helper read methods----------------------//

        static string ReadString()
        {
            return input[cur++];
        }

        static int ReadInt()
        {
            return int.Parse(input[cur++]);
        }

        static double ReadDouble()
        {
            return double.Parse(input[cur++]);
        }

        static string[] ReadStrings()
        {
            return input[cur++].Split(' ');
        }

        static int[] ReadInts()
        {
            string[] s = input[cur++].Split(' ');
            int[] result = new int[s.Length];
            for (int i = 0; i < s.Length; i++)
                result[i] = int.Parse(s[i]);
            return result;
        }

        static double[] ReadDoubles()
        {
            string[] s = input[cur++].Split(' ');
            double[] result = new double[s.Length];
            for (int i = 0; i < s.Length; i++)
                result[i] = double.Parse(s[i]);
            return result;
        }
    }
}
