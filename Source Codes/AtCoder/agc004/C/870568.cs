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
        this.Height = inpt[0];
        this.Width = inpt[1];

        this.SetMap();

        for(int i=0; i<this.Height; i++) {
            string row = Reader.ReadLine();
            for(int j=0; j<this.Width; j++) {
                if(row[j] == '#') {
                    this.RedMap[i,j] = true;
                    this.BlueMap[i,j] = true;
                }
            }
        }

        this.PrintMap(this.RedMap);
        Console.WriteLine(string.Empty);
        this.PrintMap(this.BlueMap);

    }

    private void PrintMap(bool[,] map) {
        StringBuilder str = new StringBuilder();
        for(int i=0; i<map.GetLength(0); i++) {
            for(int j=0; j<map.GetLength(1); j++) {
                if(map[i,j]) {
                    str.Append('#');
                } else {
                    str.Append('.');
                }
            }
            str.AppendLine(string.Empty);
        }
        Console.Write(str.ToString());
    }

    private void SetMap() {
        this.BlueMap = new bool[this.Height, this.Width];
        this.RedMap = new bool[this.Height, this.Width];

        for(int i=0; i<this.Height; i++) {
            for(int j=0; j<this.Width; j++) {
                if(i%2 == 0) {
                    if(j<this.Width - 1) {
                        this.BlueMap[i,j] = true;
                    }
                } else if(j==0) {
                    this.BlueMap[i,j] = true;
                }
                if(i%2 != 0 && j > 0) {
                    this.RedMap[i,j] = true;
                } else if(j == this.Width - 1) {
                    this.RedMap[i,j] = true;
                }
            }
        }
    }

    private bool[,] BlueMap;
    private bool[,] RedMap;

    private int Height;
    private int Width;


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

5 5
.....
.#.#.
.....
.#.#.
.....

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