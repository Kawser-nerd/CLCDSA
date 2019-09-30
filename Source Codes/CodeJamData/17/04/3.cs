using System;
using System.Collections.Generic;

namespace FashionShow
{
    class CellInfo
    {
        public char modelType;
        public int row;
        public int col;
    }

    class CellFlag
    {
        public bool forbid_P;
        public bool forbid_X;
        public bool forbid_O;

        public int Value()
        {
            if (!forbid_O)
            {
                return 2;
            }

            if (!forbid_P || ! forbid_X)
            {
                return 1;
            }

            return 0;
        }
    }

    class FashionShow
    {
        static int gridSize;
        static char[,] initialCells;
        static char[,] cells;
        static CellFlag[,] flags;
        //static int[,] values;

        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());

            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample         
                string[] values = Console.ReadLine().Split(' ');
                gridSize = int.Parse(values[0]);

                int initialModels = int.Parse(values[1]);

                initialCells = new char[gridSize, gridSize];

                for (int i = 0; i < gridSize; i++)
                {
                    for (int j = 0; j < gridSize; j++)
                    {
                        initialCells[i, j] = '.';
                    }
                }

                for (int i = 0; i < initialModels; i++)
                {
                    values = Console.ReadLine().Split(' ');
                    char modelType = values[0][0];
                    int row = int.Parse(values[1]) - 1;
                    int col = int.Parse(values[2]) - 1;
                    initialCells[row, col] = modelType;
                }

                SolveTheProblem(sp + 1);

            }
        }

        static int TotalScore()
        {
            int score = 0;
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    if (cells[i, j] == 'o')
                    {
                        score += 2;
                    }
                    else if (cells[i, j] == 'x' || cells[i, j] == '+')
                    {
                        score++;
                    }
                }
            }
            return score;
        }

        static void MarkCell(int row, int col, char sign)
        {
            cells[row, col] = sign;

            flags[row, col].forbid_X = true;
            flags[row, col].forbid_P = true;

            if (sign == 'o')
            {
                flags[row, col].forbid_O = true;
            }

            if (sign != '+') 
            {
                // all other signs in row/ cols must be +
                for (int i = 0; i < gridSize; i++)
                {
                    if (i != col)
                    {
                        flags[row, i].forbid_X = true;
                        flags[row, i].forbid_O = true;
                    }

                    if (i != row)
                    {
                        flags[i, col].forbid_X = true;
                        flags[i, col].forbid_O = true;
                    }
                }
            }

            if (sign != 'x')
            {
                int offset = col - row;
                // all other signs in diagonals must be x
                for (int i = 0; i < gridSize; i++)
                {
                    int j = i + offset;
                    if (j >= 0 && j < gridSize && (i != row || j != col))
                    {
                        flags[i, j].forbid_P = true;
                        flags[i, j].forbid_O = true;
                    }

                    j = col + (col - j);
                    if (j >= 0 && j < gridSize && (i != row || j != col))
                    {
                        flags[i, j].forbid_P = true;
                        flags[i, j].forbid_O = true;
                    }
                }
            }
        }

        static void MarkCell_OPX(int i, int j)
        {
            if (!flags[i, j].forbid_O)
            {
                MarkCell(i, j, 'o');
            }
            else if (!flags[i, j].forbid_P)
            {
                MarkCell(i, j, '+');
            }
            else if (!flags[i, j].forbid_X)
            {
                MarkCell(i, j, 'x');
            }
        }

        static void AddMoreSigns()
        {
            int d = gridSize;
            while (d > 0)
            {
                int offset = (gridSize - d) / 2;
                for (int i = 0; i < d; i++)
                {
                    MarkCell_OPX(offset, offset + i);
                    MarkCell_OPX(offset + i, offset + d - 1);
                    MarkCell_OPX(offset + d - 1, offset + i);
                    MarkCell_OPX(offset + i, offset);
                }

                d -= 2;
            }
        }

        static void ArrangeModels()
        {
            // Initialize variables
            cells = new char[gridSize, gridSize];
            flags = new CellFlag[gridSize, gridSize];
            //values = new int[gridSize, gridSize];

            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    cells[i, j] = '.';
                    flags[i, j] = new CellFlag();
                    //values[i, j] = (gridSize * 2 - 2) * 2 + gridSize
                }
            }
            
            // Process initial cells
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    if (initialCells[i, j] != '.')
                    {
                        MarkCell(i, j, initialCells[i, j]);
                    }
                }
            }

            // Modify to get higher score
            AddMoreSigns();
        }

        static int ExtractResult(out CellInfo[] modifications)
        {
            // Calculate number of score
            int score = TotalScore();

            // Extract the modification
            List<CellInfo> modList = new List<CellInfo>();
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    if (cells[i, j] != initialCells[i, j])
                    {
                        modList.Add(new CellInfo()
                        {
                            modelType = cells[i, j],
                            row = i,
                            col = j
                        });
                    }
                }
            }

            modifications = modList.ToArray();

            return score;
        }

        static void SolveTheProblem(int sp)
        {
            // Calculation
            ArrangeModels();

            CellInfo[] modifications;
            int score = ExtractResult(out modifications);

            // Print results
            Console.WriteLine("Case #{0}: {1} {2}", sp, score, modifications.Length);

            //if (sp == 4)
            //{
            //    PrintDebug();
            //}

            for (int i = 0; i < modifications.Length; i++)
            {
                Console.WriteLine("{0} {1} {2}", modifications[i].modelType,
                    modifications[i].row + 1, modifications[i].col + 1);
            }
        }

        static void PrintDebug()
        {
            Console.WriteLine("INITIAL: ");
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    Console.Write("{0} ", initialCells[i, j]);
                }
                Console.WriteLine();
            }

            Console.WriteLine("FINAL: ");
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    Console.Write("{0} ", cells[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}
