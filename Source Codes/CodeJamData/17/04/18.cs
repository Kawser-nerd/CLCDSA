using System;
using System.Collections.Generic;
using System.IO;

namespace CodeJam2017
{
    public class QR_D
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                string[] data = input.ReadLine().Split(' ');
                int n = Int32.Parse(data[0]);
                int m = Int32.Parse(data[1]);

                var stage = new Stage(n);

                for (int i = 0; i < m; i++)
                    stage.Add(Model.Parse(input.ReadLine()));

                stage.Improve();

                output.WriteLine("Case #{0}: {1} {2}", z, stage.Score, stage.Moves.Count);

                foreach (Model model in stage.Moves)
                    output.WriteLine(model);
            }
        }

        private class Model
        {
            public static Model Parse(string raw)
            {
                string[] data = raw.Split(' ');

                if (data[0].Length != 1)
                    throw new ArgumentException("Model type is invalid: " + data[0]);

                return new Model(data[0][0], Int32.Parse(data[1]), Int32.Parse(data[2]));
            }

            public Model(char type, int row, int col)
            {
                if ("+xo".IndexOf(type) < 0)
                    throw new ArgumentOutOfRangeException("type");

                if (row < 1)
                    throw new ArgumentOutOfRangeException("row");

                if (col < 1)
                    throw new ArgumentOutOfRangeException("col");

                this.type = type;
                this.row = row;
                this.col = col;
            }

            private char type;
            private int row;
            private int col;

            public char Type
            {
                get { return type; }
            }

            public int Row
            {
                get { return row; }
            }

            public int Col
            {
                get { return col; }
            }

            public override string ToString()
            {
                return String.Format("{0} {1} {2}", type, row, col);
            }
        }

        private class Stage
        {
            public Stage(int size)
            {
                this.size = size;
                models = new char[size + 1, size + 1];
                rows = new bool[size + 1];
                cols = new bool[size + 1];
                diag = new bool[size * 2 + 1];
                back = new bool[size * 2 + 1];

                for (int i = 1; i <= size; i++)
                    for (int j = 1; j <= size; j++)
                        models[i, j] = '.';
            }

            private int size;
            private char[,] models;
            private bool[] rows;
            private bool[] cols;
            private bool[] diag;
            private bool[] back;
            private int score = 0;
            private List<Model> moves = new List<Model>();

            public void Add(Model model)
            {
                char current = models[model.Row, model.Col];

                if (current != '.')
                {
                    if (current == model.Type)
                        return;

                    if (model.Type != 'o')
                        throw new ArgumentException(String.Format("The model is already in the position {0} : {1}", model.Row, model.Col));

                    score--;
                }

                models[model.Row, model.Col] = model.Type;
                score += (model.Type == 'o') ? 2 : 1;
                moves.Add(model);

                if (model.Type != '+')
                {
                    rows[model.Row] = true;
                    cols[model.Col] = true;
                }

                if (model.Type != 'x')
                {
                    diag[model.Row - model.Col + size] = true;
                    back[model.Row + model.Col] = true;
                }
            }

            private void Try(int r, int c)
            {
                if (models[r, c] == 'o')
                    return;

                char type = '.';

                if ((!rows[r] && !cols[c] || (models[r, c] == 'x')) && (!diag[r - c + size] && !back[r + c] || (models[r, c] == '+')))
                {
                    type = 'o';
                }
                else if (!rows[r] && !cols[c] && (models[r, c] == '.'))
                {
                    type = 'x';
                }
                else if (!diag[r - c + size] && !back[r + c] && (models[r, c] == '.'))
                {
                    type = '+';
                }

                if (type != '.')
                    Add(new Model(type, r, c));
            }

            public void Improve()
            {
                moves.Clear();

                for (int r = 1; r <= size; r++)
                    for (int c = 1; c <= size; c++)
                        Try((r % 2 == 0) ? size - r / 2 + 1 : (r + 1) / 2, c);
            }

            public int Score
            {
                get { return score; }
            }

            public List<Model> Moves
            {
                get { return moves; }
            }

            public void Print(TextWriter output)
            {
                for (int i = 1; i <= size; i++)
                {
                    for (int j = 1; j <= size; j++)
                        output.Write(models[i, j]);

                    output.WriteLine();
                }
            }
        }
    }
}
