using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_QR_B
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_B_la.txt");
            TextWriter writer = new StreamWriter("../../output_B_la.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                string[] s = reader.ReadLine().Split();
                int N = int.Parse(s[0]);
                int M = int.Parse(s[1]);

                int[,] a = new int[N,M];
                int[] maxInRow = new int[N];
                int[] maxInCol = new int[M];
                for (int i = 0; i < N; i++)
                {
                    s = reader.ReadLine().Split();
                    for (int j = 0; j < M; j++)
                    {
                        a[i, j] = int.Parse(s[j]);
                        maxInRow[i] = Math.Max(maxInRow[i], a[i, j]);
                    }
                }
                
                for (int c = 0; c < M; c++)
                    for (int r = 0; r < N; r++)
                        maxInCol[c] = Math.Max(maxInCol[c], a[r, c]);

                string ans = "";
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                        if (a[i, j] != maxInCol[j] && a[i, j] != maxInRow[i])
                        {
                            ans = "NO";
                            break;
                        }
                    if (ans == "NO") break;
                }
                if (ans == "") ans = "YES";

                writer.WriteLine("Case #" + tc + ": " + ans);
            }

            reader.Close();
            writer.Close();
        }
    }
}
