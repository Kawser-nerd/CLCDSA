using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_0B
    {
        const string fileName = "B-large";
        const string inputFile = fileName + ".in";
        const string outputFile = fileName + ".out";
        StreamReader reader = new StreamReader(inputFile);
        StreamWriter writer = new StreamWriter(outputFile);

        public GCJ2013_0B()
        {
            char[] sep = { ' ' };
            string result;
            int N, M;
            int[][] grid = new int[100][];
            int[] rowMax = new int[100];
            int[] colMax = new int[100];
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < 100; i++)
                grid[i] = new int[100];
            for (int i = 0; i < T; i++)
            {
                string[] s = reader.ReadLine().Split(sep);
                N = Int32.Parse(s[0]);
                M = Int32.Parse(s[1]);
                result = "YES";
                for (int j = 0; j < N; j++) rowMax[j] = 0;
                for (int j = 0; j < M; j++) colMax[j] = 0;
                for (int j = 0; j < N; j++)
                {
                    s = reader.ReadLine().Split(sep);
                    for (int k = 0; k < M; k++)
                    {
                        grid[j][k] = Int32.Parse(s[k]);
                    }
                }
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < M; k++)
                    {
                        if (grid[j][k] > rowMax[j]) rowMax[j] = grid[j][k];
                        if (grid[j][k] > colMax[k]) colMax[k] = grid[j][k];
                    }
                }
                for (int j = 0; j < N && result.Equals("YES"); j++)
                {
                    for (int k = 0; k < M; k++)
                    {
                        if (grid[j][k] < rowMax[j] && grid[j][k] < colMax[k])
                        {
                            result = "NO";
                            break;
                        }
                    }
                }
                writer.WriteLine(String.Format("Case #{0}: {1}", (i+1), result));
            }
            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_0B();
        }
    }
}
