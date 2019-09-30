using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace Bacteria__Small_
{
    class Program
    {
        private static int[,] board;
        private static int[,] mas;
        private static int NM = 201;

        private static long Solve()
        {
            long result = 0;

            while (true)
            {
                bool f = true;
                for (int i = 0; i < NM; ++i)
                    for (int j = 0; j < NM; ++j)
                        if (board[i, j] == 1) f = false;
                if (f) return result;

                for (int i = 1; i < NM; ++i)
                    board[i, 0] = board[0, i] = 0;
                for (int i = 1; i < NM; ++i)
                    for (int j = 1; j < NM; ++j)
                        if (board[i - 1, j] == 1 && board[i, j - 1] == 1 && board[i, j] == 0) mas[i, j] = 1;
                        else if (board[i - 1, j] == 0 && board[i, j - 1] == 0 && board[i, j] == 1) mas[i, j] = 0;
                        else mas[i, j] = board[i, j];
                for (int i = 1; i < NM; ++i)
                    for (int j = 1; j < NM; ++j)
                        board[i, j] = mas[i, j];
                ++result;
            }
        }

        static void Main(string[] args)
        {



            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("c.txt");
            var writer = new StreamWriter("c_out.txt");

            var testNumber = long.Parse(reader.ReadLine());
            for (long test = 1; test <= testNumber; ++test)
            {
                board = new int[NM,NM];
                mas = new int[NM, NM];
                var r = long.Parse(reader.ReadLine());
                while (r-->0)
                {
                    string[] input = reader.ReadLine().Split(' ');
                    var x1 = long.Parse(input[0]);
                    var y1 = long.Parse(input[1]);
                    var x2 = long.Parse(input[2]);
                    var y2 = long.Parse(input[3]);
                    for (var i=x1;i<=x2;++i)
                        for (var j=y1;j<=y2;++j)
                            board[i, j] = 1;
                    
                }
                Console.WriteLine(test);
                var result = Solve();
                writer.WriteLine("Case #{0}: {1}", test, result);


            }

            reader.Close();
            writer.Close();
        }
    }
}
