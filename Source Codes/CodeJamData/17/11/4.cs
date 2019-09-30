using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class R1A_1_Solution
{
    static void Main()
    {
        //----------------------------------------------------------------------
        const string INPUT_FILE = @"..\..\..\data\data\input.txt";
        const string OUTPUT_FILE = @"..\..\..\data\data\output.txt";
        //----------------------------------------------------------------------
        StreamReader sr = new StreamReader(INPUT_FILE);
        StreamWriter sw = new StreamWriter(OUTPUT_FILE);
        DateTime started = DateTime.Now;
        //----------------------------------------------------------------------
        int T = int.Parse(sr.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] ss = sr.ReadLine().Split((char[])null, StringSplitOptions.RemoveEmptyEntries).ToArray();
            int R = int.Parse(ss[0]);
            int C = int.Parse(ss[1]);
            char[][] cake = new char[R][];
            for (int r = 0; r < R; r++)
                cake[r] = sr.ReadLine().Trim().ToArray();

            int R0 = -1;

            for (int r = 0; r < R; r++)
                if (cake[r].Any(p => p != '?')) {
                    R0 = r;
                    break;
                }

            int rx = R0;
            while (rx < R)
            {
                int c0 = -1;
                for (int c = 0; c < C; c++)
                    if (cake[rx][c] != '?')
                    {
                        c0 = c;
                        break;
                    }
                for (int c = 0; c < c0; c++)
                    cake[rx][c] = cake[rx][c0];

                char A = cake[rx][c0];
                int cx = c0 + 1;
                while (cx < C)
                {
                    if (cake[rx][cx] == '?')
                        cake[rx][cx] = A;
                    else
                        A = cake[rx][cx];
                    cx++;
                }

                rx++;
                while (rx < R && cake[rx].All(p => p == '?'))
                {
                    Array.Copy(cake[rx - 1], cake[rx], C);
                    rx++;
                }
            }
            for (int r = 0; r < R0; r++)
                Array.Copy(cake[R0], cake[r], C);

            sw.WriteLine("Case #{0}:", t + 1);
            for (int r = 0; r < R; r++)
                sw.WriteLine(new string(cake[r]));
        }
        //----------------------------------------------------------------------
        sr.Close();
        sw.Close();
        //----------------------------------------------------------------------
        Console.WriteLine();
        Console.WriteLine("Elapsed: {0} ms", (int)DateTime.Now.Subtract(started).TotalMilliseconds);
        Console.ReadLine();
        //----------------------------------------------------------------------
    }
}
