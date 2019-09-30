using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {

        int inputCount = int.Parse(Reader.ReadLine());
        this.Red = new Point[inputCount];
        this.Blue = new Point[inputCount];
        for (int i = 0; i < inputCount; i++) {
            int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            Red[i] = new Point(inpt[0], inpt[1]);
        }
        for (int i = 0; i < inputCount; i++)
        {
            int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
            Blue[i] = new Point(inpt[0], inpt[1]);
        }

        Blue = Blue.OrderBy(a => a.X).ToArray();

        int ans = 0;
        foreach(Point b in Blue) {
            Point[] target = this.Red.Where(a => a.X < b.X && a.Y < b.Y && !a.IsPair).OrderByDescending(a => a.Y).ToArray();
            if(target.Length>0) {
                target[0].IsPair = true;
                ans++;
            }
        }
        Console.WriteLine(ans);
    }

    private Point[] Red;
    private Point[] Blue;

    private class Point {
        public int X;
        public int Y;
        public bool IsPair;
        public Point(int x, int y) {
            this.X = x;
            this.Y = y;
            this.IsPair = false;
        }
    }




    public class Reader
    {
        static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"


2
2 2
3 3
0 0
1 1


";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}