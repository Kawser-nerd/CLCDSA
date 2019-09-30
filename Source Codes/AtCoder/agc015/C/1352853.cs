using System;
    using System.Linq;
    using System.Collections.Generic;
    using System.Text.RegularExpressions;
    using System.Text;
    using System.Net;

     
    public class Program
    {
        public void Proc() {
            int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();

            this.Height = inpt[0];
            this.Width = inpt[1];

            this.Map = new bool[this.Height, this.Width];
            this.BlockCount = new int[this.Height, this.Width];
            this.TateCount = new int[this.Height, this.Width];
            this.YokoCount = new int[this.Height, this.Width];

            int queryCount = inpt[2];

            for(int i=0; i<this.Height; i++) {
                string tmp = Reader.ReadLine();
                for(int j=0; j<this.Width; j++) {
                    int cntBlock = 0;
                    int cntYoko = 0;
                    int cntTate = 0;
                    if(tmp[j] == '1') {
                        this.Map[i,j] = true;
                        cntBlock = 1;
                        if(i>0&&this.Map[i-1, j]) {
                            cntTate = 1;
                        }
                        if(j>0&&this.Map[i,j-1]) {
                            cntYoko = 1;
                        }
                    }
                    if(i>0) {
                        cntBlock+=this.BlockCount[i-1, j];
                        cntYoko+=this.YokoCount[i-1,j];
                        cntTate+=this.TateCount[i-1,j];
                    }
                    if(j>0) {
                        cntBlock+=this.BlockCount[i,j-1];
                        cntYoko+=this.YokoCount[i,j-1];
                        cntTate+=this.TateCount[i,j-1];
                    }
                    if(i>0&&j>0) {
                        cntBlock-=this.BlockCount[i-1,j-1];
                        cntYoko-=this.YokoCount[i-1,j-1];
                        cntTate-=this.TateCount[i-1,j-1];
                    }
                    this.BlockCount[i,j] = cntBlock;
                    this.YokoCount[i,j] = cntYoko;
                    this.TateCount[i,j] = cntTate;
                }
            }
            StringBuilder ans = new StringBuilder();
            for(int i=0; i<queryCount; i++) {
                int[] rect = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)-1).ToArray();
                ans.AppendLine(GetAns(rect[0], rect[1], rect[2], rect[3]).ToString());
            }
            Console.Write(ans.ToString());
        }

        private int GetAns(int y1, int x1, int y2, int x2) {
            int cntBlock = BlockCount[y2, x2];
            int cntYoko = YokoCount[y2, x2];
            int cntTate = TateCount[y2, x2];
            if(y1>0) {
                cntBlock -= BlockCount[y1-1, x2];
                cntYoko -= YokoCount[y1-1,x2];
                cntTate -= TateCount[y1, x2];
            }
            if(x1>0) {
                cntBlock -= BlockCount[y2, x1-1];
                cntYoko -= YokoCount[y2, x1];
                cntTate -= TateCount[y2, x1-1];
            }
            if(y1>0&&x1>0) {
                cntBlock+=BlockCount[y1-1, x1-1];
                cntYoko+=YokoCount[y1-1,x1];
                cntTate+=TateCount[y1,x1-1];
            }
            return cntBlock-(cntYoko+cntTate);
        } 
        private int Height;
        private int Width;

        private bool[,] Map;
        private int[,] BlockCount;
        private int[,] YokoCount;
        private int[,] TateCount;

        public class Reader {
            public static bool IsDebug = false;
            private static System.IO.StringReader SReader;
            private static string InitText = @"




3 4 4
1101
0110
1101
1 1 3 4
1 1 3 1
2 2 3 4
1 2 2 4






";
            public static string ReadLine() {
                if(IsDebug) {
                    if(SReader == null) {
                        SReader = new System.IO.StringReader(InitText.Trim());
                    }
                    return SReader.ReadLine();
                } else {
                    return Console.ReadLine();
                }
            }
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