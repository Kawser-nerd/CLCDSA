using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1C_Pogo
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inps = new StreamReader("data_in.txt");
            StreamWriter outps = new StreamWriter("data_out.txt");
            int T = int.Parse(inps.ReadLine());
            for (int t = 0; t < T; ++t)
            {
                string line = inps.ReadLine();
                string[] lineEl = line.Split(' ');
                int x = int.Parse(lineEl[0]);
                int y = int.Parse(lineEl[1]);
                string res = Resolve(x,y);
                outps.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            inps.Close();
            outps.Close();
        }

        public class Coord
        {
            public int X;
            public int Y;
            public override int GetHashCode()
            {
                return (int)(X + 100000000L * Y);
            }
        }

        public class Cell : Coord
        {
            public Cell ParentCell;
            public char DirectionFromParent;

        }

        private static string Resolve(int x, int y)
        {
            StringBuilder res = new StringBuilder();
            //Dictionary<Coord, Cell> ground = new Dictionary<Coord, Cell>();
            //int curX = 0, curY = 0;
            //while (true)
            //{
            //}
            int doneMoves = 0;
            if (x > 0)
            {
                // move x right
                for (int i = 0; i < x; ++i)
                    res.Append("WE");
                doneMoves = x;
            }
            else if (x < 0)
            {
                // move x left
                for (int i = 0; i < -x; ++i)
                    res.Append("EW");
                doneMoves = -x;
            }
            if (y > 0)
            {
                // move y up
                for (int i = 0; i < y; ++i)
                    res.Append("SN");
            }
            else if (y < 0)
            {
                // move y down
                for (int i = 0; i < -y; ++i)
                    res.Append("NS");
            }


            return res.ToString();
        }
    }
}
