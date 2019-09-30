using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gcj2017Qual {
    /// <summary>
    /// Problem D. Fashion Show
    /// </summary>
    /// <remarks>
    /// N M
    /// N := 縦横の長さ
    /// M := 初期配置の数
    /// [x,+,o] Ri Ci
    /// x,+,o := The type of the model
    /// Ri Ci := Position
    /// 
    /// 1 <= N <= 100
    /// 1 <= Ci <= N
    /// 0 <= M <= N^2
    /// 
    /// == SMALL ==
    /// Ri == 1
    /// == LARGE ==
    /// 1<= Ri <= N
    /// </remarks>
    class ProgramD {

        const char BISHOP = '+';
        const char ROOK = 'x';
        const char QUEEN = 'o';


        private static void Solve(Problem p) {
            // 読込
            var line = p.getNexts().Select(int.Parse).ToArray();
            int N = line[0];
            int M = line[1];
            List<Model> models = new List<Model>();
            for (int i = 0; i < M; i++) {
                models.Add(new Model(p.getNexts().ToArray()));
            }

            // 初期配置作成
            Board board = new Board(N);
            foreach (var model in models) {
                board[model.Row,model.Col] = model.Type;
            }

            List<Model> result = new List<Model>();

            // 1行目の配置
            for (int column = 1; column <= N; column++) {
                if (board.CanPutQueen(1, column)) {
                    board[1, column] = QUEEN;
                    result.Add(new Model(QUEEN, 1, column));
                }
                else if (board.CanPutBISHOP(1, column)) {
                    board[1, column] = BISHOP;
                    result.Add(new Model(BISHOP, 1, column));
                }
            }
            // 最下行の配置
            for (int column = 1; column <= N; column++) {
                if (board.CanPutQueen(N, column)) {
                    board[N, column] = QUEEN;
                    result.Add(new Model(QUEEN, N, column));
                }
                else if (board.CanPutBISHOP(N, column)) {
                    board[N, column] = BISHOP;
                    result.Add(new Model(BISHOP, N, column));
                }
            }
            // 空きマスをROOKで埋め尽くす（QUEENは？）
            for (int row = 1; row <= N; row++) {
                for (int column = 1; column <= N; column++) {
                    if (board.CanPutQueen(row, column)) {
                        board[row, column] = QUEEN;
                        result.Add(new Model(QUEEN, row, column));
                    }
                    if (board.CanPutROOK(row, column)) {
                        board[row, column] = ROOK;
                        result.Add(new Model(ROOK, row, column));
                    }
                }
            }
            // 空きマスをBISHOPで埋め尽くす
            for (int row = 1; row <= N; row++) {
                for (int column = 1; column <= N; column++) {
                    if (board.CanPutBISHOP(row, column)) {
                        board[row, column] = BISHOP;
                        result.Add(new Model(BISHOP, row, column));
                    }
                }
            }

            // 解答
            p.WriteAnswerFullLine($"{board.StylePoint} {result.Count}");
            foreach (var model in result) {
                p.WriteAnswerSubLine($"{model.Type} {model.Row} {model.Col}");
            }
            board.Show();
        }

        /// <summary>
        /// - 行または列に2人以上のModelが居る場合、+以外が2名以上居てはならない。
        /// - 対角に2人以上のModelが居る場合、x以外が2名以上居てはならない。
        /// - 既に配置されたモデルは+,xからoにUpgradeする場合に限り許される。
        /// </summary>
        class Model {
            public Model(string[] args) {
                Type = args[0][0];
                Row = int.Parse(args[1]);
                Col = int.Parse(args[2]);
            }
            public Model(char type, int row, int col) {
                Type = type;
                Row = row;
                Col = col;
            }
            /// <remarks>
            /// +,x := 1Point
            /// o := 2Points
            /// </remarks>
            public char Type { get; set; }
            public int Row { get; set; }
            public int Col { get; set; }
        }

        /// <summary>
        /// 会場
        /// </summary>
        class Board {
            public int Size { get; }
            private char[] Cells { get; }

            public Board(int size) {
                Size = size;
                Cells = new char[size*size];
            }

            /// <summary>点数算出</summary>
            public int StylePoint {
                get {
                    return Cells.Sum(c => c == QUEEN ? 2 : c == ROOK ? 1 : c == BISHOP ? 1 : 0);
                }
            }
            /// <summary>インデクサ</summary>
            public char this[int row,int col] {
                get { return Cells[(row - 1) * Size + (col - 1)]; }
                set { Cells[(row - 1) * Size + (col - 1)] = value; }
            }

            public void Show() {
                for (int i = 0; i < Size; i++) {
                    for (int j = 0; j < Size; j++) {
                        Console.Write(Cells[i * Size + j] == '\0' ? '.' : Cells[i * Size + j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine("==========");
            }

            public bool CanPutQueen(int row, int col) {
                row--; col--;
                int current = row * Size + col;
                if (Cells[current] == 'o') return false;
                for (int x = 0; x < Size; x++) {
                    if (row * Size + x != current && (Cells[row * Size + x] == QUEEN || Cells[row * Size + x] == ROOK)) return false;
                    if (x * Size + col != current && (Cells[x * Size + col] == QUEEN || Cells[x * Size + col] == ROOK)) return false;
                    if (col == x) continue;
                    if (0 <= row - (col - x) && row - (col - x) < Size) {
                        if (Cells[(row - (col - x)) * Size + x] == QUEEN || Cells[(row - (col - x)) * Size + x] == BISHOP) return false;
                    }
                    if (0 <= row + (col - x) && row + (col - x) < Size) {
                        if (Cells[(row + (col - x)) * Size + x] == QUEEN || Cells[(row + (col - x)) * Size + x] == BISHOP) return false;
                    }
                }

                return true;
            }

            public bool CanPutBISHOP(int row, int col) {
                row--; col--;
                int current = row * Size + col;
                if (Cells[current] != '\0') return false;
                for (int x = 0; x < Size; x++) {
                    if (col == x) continue;
                    if (0 <= row - (col-x) && row - (col - x) < Size) {
                        if (Cells[(row - (col - x)) * Size + x] == QUEEN || Cells[(row - (col - x)) * Size + x] == BISHOP) return false;
                    }
                    if (0 <= row + (col - x) && row + (col - x) < Size) {
                        if (Cells[(row + (col - x)) * Size + x] == QUEEN || Cells[(row + (col - x)) * Size + x] == BISHOP) return false;
                    }
                }

                return true;
            }

            public bool CanPutROOK(int row, int col) {
                row--; col--;
                int current = row * Size + col;
                if (Cells[current] != '\0') return false;
                for (int x = 0; x < Size; x++) {
                    if (row * Size + x != current && (Cells[row * Size + x] == QUEEN || Cells[row * Size + x] == ROOK)) return false;
                    if (x * Size + col != current && (Cells[x * Size + col] == QUEEN || Cells[x * Size + col] == ROOK)) return false;
                }

                return true;
            }
        }


        static System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
        static void Main(string[] args) {
            sw.Start();

            Logic(args);

            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }

        private static void Logic(string[] args) {
            Problem p = Problem.createProblem(args);
            if (p == null) return;

            long repeat = p.getNextInt64s().First();

            for (int i = 0; i < repeat; i++) {
                Solve(p);
            }
        }

    }
}
