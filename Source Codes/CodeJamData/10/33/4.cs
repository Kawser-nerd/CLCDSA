using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class KubaC : AbstractSolver
    {

        private BoardElement[,]board ;
        private int N,M;
        protected override object Solve(System.IO.StreamReader input)
        {
            M = NextInt();
            N = NextInt();
            board = new BoardElement[M, N];

            
            for (int i = 0; i < M; i++)
            {
                string line = NextLine();
                int pos = 0;
                for (int x = 0; x < N / 4; x++)
                {
                    int[] els = elementsFromLetter(line[x]);
                    for (int k = 0; k < 4; k++)
                    {
                        board[i, pos] = new BoardElement(els[k] == 0);
                        pos++;
                    }
                }
            }
            

            for (int i = 0; i < M; i++)
            {
                board[i, N - 1].rightIndex = 1;
                for (int j = N - 2; j >= 0; j--)
                {
                    var current = board[i, j];
                    var next = board[i, j+1];
                    if (current.white != next.white)
                    {
                        current.rightIndex = next.rightIndex + 1;
                    }
                    else
                    {
                        current.rightIndex = 1;
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                board[M - 1, i].lowIndex = 1;
                for (int j = M - 2; j >= 0; j--)
                {
                    var current = board[j, i];
                    var next = board[j+1, i];
                    if (current.white != next.white)
                    {
                        current.lowIndex = next.lowIndex + 1;
                    }
                    else
                    {
                        current.lowIndex= 1;
                    }
                }
            }

            int maxBoard = Math.Max(M, N);

            int allFields = M * N; 
            int[] boards = new int[maxBoard+1];

            for (int boardSize = maxBoard; boardSize > 1; boardSize-- )
            {
                for (int x=0; x<=M-boardSize; x++)
                    for (int y = 0; y <= N-boardSize; y++)
                    {
                        if (canBuildBoard(x, y, boardSize))
                        {
                            //Console.WriteLine("Can biuld {0},{1} of size {2}", x, y, boardSize);
                            buildBoard(x, y, boardSize);
                            boards[boardSize]++;
                            allFields -= boardSize * boardSize;
                        }
                    }
                if (boards[boardSize] > 0 && boardSize > 1)
                {
                    //drawBoard();
                }
            }


            StringBuilder sb = new StringBuilder();
            boards[1] = allFields;
            int count = 0;
            for (int i = maxBoard; i >= 1; i--)
            {
                if (boards[i] > 0)
                {
                    sb.Append(string.Format("{2}{0} {1}", i, boards[i], Environment.NewLine));
                    count++;
                }
            }
            return ""+count+sb.ToString();
        }

        private void buildBoard(int x, int y, int size)
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                {
                    board[x + i, y + j].active = false;
                    board[x + i, y + j].rightIndex = board[x + i, y + j].lowIndex = 0;
                }


            //starting points are 
            //x-1, y      we iterate lowing the x
            //x-1, y+1
            //x-1, y+1 
            if (x > 0)
            {
                for (int y0 = y; y0 < size + y; y0++)
                {
                    int x0 = x - 1;
                    while (x0 >= 0 && board[x0, y0].lowIndex > 1)
                    {
                        board[x0, y0].lowIndex = board[x0 + 1, y0].lowIndex + 1; ;
                        x0--;
                    }
                }
            }

            if (y > 0)
            {
                for (int x0 = x; x0 < size + x; x0++)
                {
                    int y0 = y - 1;
                    while (y0 >= 0 && board[x0, y0].rightIndex > 1)
                    {
                        board[x0, y0].rightIndex = board[x0, y0 + 1].rightIndex + 1;
                        y0--;
                    }
                }
            }

        }

        private bool canBuildBoard(int x, int y, int size)
        {
            if (!board[x, y].active) return false;
            if (board[x, y].lowIndex < size) return false;
            for (int i = 0; i < size; i++)
            {
                if (board[x + i, y].rightIndex < size)
                {
                    return false;
                }
            }
            return true;
        }

        private void drawBoard()
        {
            for (int i = 0; i < M; i++)
            {
                for (int k = 0; k < N; k++)
                {
                    Console.Write(board[i,k]);
                }
                Console.WriteLine();
            }
        }
        #region Letters
        int[] T0 = new int[] { 0, 0, 0, 0 };
        int[] T1 = new int[] { 0, 0, 0, 1 };
        int[] T2 = new int[] { 0, 0, 1, 0 };
        int[] T3 = new int[] { 0, 0, 1, 1 };
        int[] T4 = new int[] { 0, 1, 0, 0 };
        int[] T5 = new int[] { 0, 1, 0, 1 };
        int[] T6 = new int[] { 0, 1, 1, 0 };
        int[] T7 = new int[] { 0, 1, 1, 1 };
        int[] T8 = new int[] { 1, 0, 0, 0 };
        int[] T9 = new int[] { 1, 0, 0, 1 };
        int[] TA = new int[] { 1, 0, 1, 0 };
        int[] TB = new int[] { 1, 0, 1, 1 };
        int[] TC = new int[] { 1, 1, 0, 0 };
        int[] TD = new int[] { 1, 1, 0, 1 };
        int[] TE = new int[] { 1, 1, 1, 0 };
        int[] TF = new int[] { 1, 1, 1, 1 };

        int[] elementsFromLetter(char ch)
        {
            switch (ch)
            {
                case '0': return T0;
                case '1': return T1;
                case '2': return T2;
                case '3': return T3;
                case '4': return T4;
                case '5': return T5;
                case '6': return T6;
                case '7': return T7;
                case '8': return T8;
                case '9': return T9;
                case 'A': return TA;
                case 'B': return TB;
                case 'C': return TC;
                case 'D': return TD;
                case 'E': return TE;
                case 'F': return TF;
            }
            throw new Exception("Unknown hex number");
        }
        #endregion
    }


    class BoardElement
    {
        public bool white;
        public bool active;
        public int rightIndex;
        public int lowIndex;

        public BoardElement(bool white)
        {
            this.white = white;
            this.active = true;
        }
        public override string ToString()
        {
            
            var result = "";

            if (!active)
            {
                result = ".";
            }
            else
            {
                result =(white ? "O" : "x");
            }
            return result;// +"(" + rightIndex + ")";
        }
    }
}
