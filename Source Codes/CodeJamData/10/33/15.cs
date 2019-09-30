using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1C
{
    public class ChessBoards
    {
        int M;
        int N;

        Dictionary<int, int> results;

        string result = String.Empty;

        private List<bool> ToBinary(char input)
        {
            bool f = false;
            bool t = true;

            var list = new List<bool>();

            int num = 0;

            switch (input)
            {
                case 'A':
                    num = 10; break;
                case 'B':
                    num = 11; break;
                case 'C':
                    num = 12; break;
                case 'D':
                    num = 13; break;
                case 'E':
                    num = 14; break;
                case 'F':
                    num = 15; break;
                default:
                    num = Convert.ToInt32(input.ToString()); break;
            }

            if (num >= 8) 
            {
                list.Add(true); 
                num -= 8;
            }
                else list.Add(false);

            if (num >= 4)
            {
                list.Add(true);
                num -= 4;
            }
            else list.Add(false);

            if (num >= 2)
            {
                list.Add(true);
                num -= 2;
            }
            else list.Add(false);

            if (num >= 1)
            {
                list.Add(true);
            }
            else list.Add(false);

            return list;

        }

        private bool Check(bool?[][] subgrid)
        {
            // if there's a null
            if (subgrid.SelectMany(s => s.Select(s2 => s2)).Any(e => e == null))
                return false;

            bool start = Convert.ToBoolean(subgrid[0][0]);
            bool expected;

            foreach (var row in subgrid)
            {
                expected = start;

                foreach (var cell in row)
                {
                    if (cell.Value != expected)
                        return false;
                    expected  = !expected;
                }

                start = !start;
            }

            return true;
        }

        private bool FindInGrid(int size, ref bool?[][] grid)
        {
            bool?[][] subgrid = new bool?[size][];
            for (int y = 0; y <= (this.M - size); y++)
            {
                for (int x = 0; x <= (this.N - size); x++)
                {
                    //populate the subgrid;
                    for (int s = 0; s < size; s++)
                    {
                        subgrid[s] = new bool?[size];
                        for (int s2 = 0; s2 < size; s2++)
                            subgrid[s][s2] = grid[y + s][x + s2];
                    }

                    bool found = this.Check(subgrid);

                    if (found)
                    {
                        //purge the board ;
                        for (int s = 0; s < size; s++)
                        {
                            subgrid[s] = new bool?[size];
                            for (int s2 = 0; s2 < size; s2++)
                                grid[y + s][x + s2] = null;
                        }
                        return true;
                    }
                }
            }

            return false;
        }

        public ChessBoards(ref List<string> inputFile)
        {
            var line = inputFile.First().Split(' ');
            inputFile.RemoveAt(0);

            this.M = Int32.Parse(line[0]);
            this.N = Int32.Parse(line[1]);


            bool?[][] grid2 = new bool?[this.M][];//,this.N];


            for (int i = 0; i < this.M; i++)
            {
                var line2 = inputFile.First().ToArray();
                inputFile.RemoveAt(0);

                List<bool> row = new List<bool>();

                line2.ToList().ForEach(c => row.AddRange(this.ToBinary(c)));

                grid2[i] = new bool?[this.N];

                for (int j = 0; j < row.Count; j++)
                {
                    grid2[i][j] = row[j];
                }
            }

            int maxSize = Math.Min(this.M, this.N);
            results = new Dictionary<int, int>();

            for (int size = maxSize; size > 0; size--)
            {
                int found = 0;
                while (this.FindInGrid(size, ref grid2))
                {
                    found++;
                    if (results.Any(r => r.Key == size))
                    {
                        results[size] = found;
                    }
                    else
                    {
                        results.Add(size, found);
                    }
                }
            }
        }

        public string Result
        {
            get
            {
                var lines = this.results.Select(r => String.Join(" ", r.Key, r.Value));
                var flatLines = String.Join(Environment.NewLine, lines);

                return this.results.Count.ToString() + Environment.NewLine + flatLines;
            }
        }
    }
}
