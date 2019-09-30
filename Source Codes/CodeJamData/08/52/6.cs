using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;


namespace Round3B
{
    struct pair
    {
        public int r;
        public int c;

        public pair(int r, int c)
        {
            this.r = r;
            this.c = c;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            FileStream file = new FileStream("B-small-attempt0.in", FileMode.OpenOrCreate, FileAccess.Read);
            StreamReader sr = new StreamReader(file);

            FileStream file2 = new FileStream("out.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(file2);

            String tempStr;
            Int32 numProb;

            tempStr = sr.ReadLine();
            numProb = Int32.Parse(tempStr);

            for (long i = 1; i <= numProb; i++)
            {
                int ans = FindAnswer(sr);
                if(ans == -1)
                    sw.WriteLine("Case #" + i + ": THE CAKE IS A LIE");
                else
                    sw.WriteLine("Case #" + i + ": " + ans);
            }

            sw.Close();
            sr.Close();
            file.Close();
            file2.Close();
        }

        static int FindAnswer(StreamReader sr)
        {
            String tempStr;
            char[] seps = {' '};

            tempStr = sr.ReadLine();
            String[] s = tempStr.Split(seps);

            int rows = Int32.Parse(s[0]);
            int cols = Int32.Parse(s[1]);

            int[,] maze = new int[rows, cols];
            bool[,] touched = new bool[rows, cols];

            int sRow, sCol, gRow, gCol;
            sRow = sCol = gRow = gCol = 0;
            for (int r = 0; r < rows; r++)
            {
                tempStr = sr.ReadLine();
                for (int c = 0; c < cols; c++)
                {
                    if (tempStr[c] == 'O')
                    {
                        sRow = r;
                        sCol = c;
                        maze[r, c] = 0;
                    }
                    else if (tempStr[c] == 'X')
                    {
                        gRow = r;
                        gCol = c;
                        maze[r, c] = 0;
                    }
                    else if (tempStr[c] == '.')
                    {
                        maze[r, c] = 0;
                    }
                    else if (tempStr[c] == '#')
                    {
                        maze[r, c] = -1;
                    }
                    else
                        Console.WriteLine("ERROR");
                }
            }

            ArrayList queue = new ArrayList();
            queue.Add(new pair(sRow, sCol));

            while (queue.Count > 0)
            {
                pair cur = (pair)queue[0];
                queue.Remove(cur);

                if (cur.r == gRow && cur.c == gCol)
                    return maze[cur.r, cur.c];

                if (touched[cur.r, cur.c])
                    continue;

                touched[cur.r, cur.c] = true;

                bool wallClose = false;
                //Look North
                if (cur.r == 0)
                    wallClose = true;
                else
                {
                    int cell = maze[cur.r - 1, cur.c];
                    if (cell == -1)
                        wallClose = true;
                    else if (cell == 0)
                    {
                        maze[cur.r - 1, cur.c] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r - 1, cur.c));
                    }
                    else
                    {
                        if (maze[cur.r, cur.c] + 1 < maze[cur.r - 1, cur.c])
                            maze[cur.r - 1, cur.c] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r - 1, cur.c));
                    }
                }

                //Look West
                if (cur.c == 0)
                    wallClose = true;
                else
                {
                    int cell = maze[cur.r, cur.c - 1];
                    if (cell == -1)
                        wallClose = true;
                    else if (cell == 0)
                    {
                        maze[cur.r, cur.c - 1] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r, cur.c - 1));
                    }
                    else
                    {
                        if (maze[cur.r, cur.c] + 1 < maze[cur.r, cur.c - 1])
                            maze[cur.r, cur.c - 1] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r, cur.c - 1));
                    }
                }

                //Look South
                if (cur.r + 1 == rows)
                    wallClose = true;
                else
                {
                    int cell = maze[cur.r + 1, cur.c];
                    if (cell == -1)
                        wallClose = true;
                    else if (cell == 0)
                    {
                        maze[cur.r + 1, cur.c] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r + 1, cur.c));
                    }
                    else
                    {
                        if (maze[cur.r, cur.c] + 1 < maze[cur.r + 1, cur.c])
                            maze[cur.r + 1, cur.c] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r + 1, cur.c));
                    }
                }

                //Look East
                if (cur.c + 1 == cols)
                    wallClose = true;
                else
                {
                    int cell = maze[cur.r, cur.c + 1];
                    if (cell == -1)
                        wallClose = true;
                    else if (cell == 0)
                    {
                        maze[cur.r, cur.c + 1] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r, cur.c + 1));
                    }
                    else
                    {
                        if (maze[cur.r, cur.c] + 1 < maze[cur.r, cur.c + 1])
                            maze[cur.r, cur.c + 1] = maze[cur.r, cur.c] + 1;
                        queue.Add(new pair(cur.r, cur.c + 1));
                    }
                }

                //Add the wall teleport spots
                if (wallClose)
                {
                    int tRow, tCol;

                    //Look North
                    tRow = cur.r;
                    tCol = cur.c;

                    while (tRow > 0)
                    {
                        if (maze[tRow - 1, tCol] == -1)
                            break;
                        tRow--;
                    }
                    if (!(cur.r == tRow && cur.c == tCol))
                    {
                        if (maze[tRow, tCol] == 0)
                            maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        else
                        {
                            if (maze[cur.r, cur.c] + 1 < maze[tRow, tCol])
                                maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        }
                        queue.Add(new pair(tRow, tCol));
                    }

                    //Look West
                    tRow = cur.r;
                    tCol = cur.c;

                    while (tCol > 0)
                    {
                        if (maze[tRow, tCol-1] == -1)
                            break;
                        tCol--;
                    }
                    if (!(cur.r == tRow && cur.c == tCol))
                    {
                        if (maze[tRow, tCol] == 0)
                            maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        else
                        {
                            if (maze[cur.r, cur.c] + 1 < maze[tRow, tCol])
                                maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        }
                        queue.Add(new pair(tRow, tCol));
                    }

                    //Look South
                    tRow = cur.r;
                    tCol = cur.c;

                    while (tRow < rows-1)
                    {
                        if (maze[tRow + 1, tCol] == -1)
                            break;
                        tRow++;
                    }
                    if (!(cur.r == tRow && cur.c == tCol))
                    {
                        if (maze[tRow, tCol] == 0)
                            maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        else
                        {
                            if (maze[cur.r, cur.c] + 1 < maze[tRow, tCol])
                                maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        }
                        queue.Add(new pair(tRow, tCol));
                    }

                    //Look East
                    tRow = cur.r;
                    tCol = cur.c;

                    while (tCol < cols-1)
                    {
                        if (maze[tRow, tCol+1] == -1)
                            break;
                        tCol++;
                    }
                    if (!(cur.r == tRow && cur.c == tCol))
                    {
                        if (maze[tRow, tCol] == 0)
                            maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        else
                        {
                            if (maze[cur.r, cur.c] + 1 < maze[tRow, tCol])
                                maze[tRow, tCol] = maze[cur.r, cur.c] + 1;
                        }
                        queue.Add(new pair(tRow, tCol));
                    }
                }
            }

            return -1;

        }

    }
}
