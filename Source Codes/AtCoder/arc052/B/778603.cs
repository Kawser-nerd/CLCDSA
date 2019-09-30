using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;



class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();

        int ensuiCount = inpt[0];
        int queryCount = inpt[1];

        for(int i=0; i<ensuiCount; i++) {
            this.EnsuiList.Add(new Ensui(Reader.ReadLine()));
        }

        StringBuilder ans = new StringBuilder();
        for(int i=0; i<queryCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();
            Ensui e = this.EnsuiList.FirstOrDefault(a=>a.InRange(inpt[0], inpt[1]));
            ans.AppendLine(this.EnsuiList.Sum(a=>a.GetPart(inpt[0], inpt[1])).ToString("#0.###################"));
        }
        Console.Write(ans.ToString());
        

    }

    private List<Ensui> EnsuiList = new List<Ensui>();

    public class Ensui {
        public int X;
        public int R;
        public int H;

        public double TotalTaiseki;

        public double TeihenMenseki;

        public Ensui(string initStr) {
            int[] inpt = initStr.Split(' ').Select(a=>int.Parse(a)).ToArray();
            this.X = inpt[0];
            this.R = inpt[1];
            this.H = inpt[2];

            this.TeihenMenseki = this.R * this.R * Math.PI;
            this.TotalTaiseki = this.TeihenMenseki * this.H / 3;
        }

        public bool InRange(int x1, int x2) {
            int minX = Math.Min(x1, x2);
            int maxX = Math.Max(x1, x2);
            if(maxX <= this.X) {
                return false;
            }
            if(minX >= this.X + this.H) {
                return false;
            }
            return true;
        }

        public double GetPart(int x1, int x2) {
            int minX = Math.Min(x1, x2);
            int maxX = Math.Max(x1, x2);
            if(maxX <= X) {
                return 0;
            }
            if(minX >= X + H) {
                return 0;
            }

            double taiseki1 = this.TotalTaiseki;

            if(minX > X) {
                double rate = (X + H - minX) / (double)H;
                taiseki1 = (this.TeihenMenseki *(rate * rate)) * ((X + H) - minX) / 3;
            }
            double taiseki2 = 0;
            if(maxX < this.X + H) {
                double rate = (X + H - maxX) / (double)H;
                taiseki2 = (this.TeihenMenseki * (rate * rate))*(X + H - maxX) / 3;
            }
            return taiseki1 - taiseki2;
        }
    }


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"


10 10
3 3 3
2 1 1
5 2 3
1 5 6
2 9 3
4 6 12
11 18 5
4 15 25
0 2 3
1 1 7
0 1
0 2
0 10
3 10
0 100
3 8
1 5
2 9
3 4
6 9




";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}