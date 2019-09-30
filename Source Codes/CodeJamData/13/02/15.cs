using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace km.gcj.gcj2013.qual
{
    class Program_A
    {
        /// <summary> プログラムのスタートポイント </summary>
        /// <param name="args"> 第一引数に入力ファイルを指定 </param>
        static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args)
        {
            //throw new NotImplementedException();
            Problem p = Problem.createProblem(args);
            if (p == null) {
                return;
            }

            // 試行回数を取得し、ループする。
            long repeat = p.getNextLineAsInt64Array()[0];
            for (int i = 0; i < repeat; i++)
            {

                // MainLoop
                long[] nm = p.getNextInt64s().ToArray();
                int n = (int)nm[0];
                int m = (int)nm[1];
                var board = new List<long[]>();
                for (int j = 0; j < n; j++)
                {
                    board.Add(p.getNextLineAsInt64Array());
                }

                p.WriteAnswerFullLine(CheckResult(board,n,m));
            }
         }
        private static String CheckResult(List<long[]> board,int n,int m){
            long[] rowMax = new long[n];
            long[] colMax = new long[m];
            for (int row = 0; row < n; row++)
			{
                rowMax[row] = board[row].Max();
			}
            for (int col = 0; col < m; col++)
			{
			    colMax[col] = board.Select(x => x[col]).Max();
			}

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
			    {
                    if (board[i][j] < rowMax[i] && board[i][j] < colMax[j])
                	{
                        return "NO";
                	}
			    }
            }
            return "YES";
        }
    }
}
