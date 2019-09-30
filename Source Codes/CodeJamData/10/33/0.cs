using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace R1C10C
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "C-large";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);
            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                s = f.ReadLine();
                subs = s.Split(' ');
                int rows = int.Parse(subs[0]);
                int cols = int.Parse(subs[1]);
                bool[,] cells = new bool[rows, cols]; //y then x, be consistent!
                for (int j = 0; j < rows; j++)
                {
                    s = f.ReadLine();
                    for (int k = 0; k < cols / 4; k++)
                    {
                        int c = int.Parse( new String (s[k], 1) , System.Globalization.NumberStyles.AllowHexSpecifier);
                        cells[j, k * 4] = c > 7;
                        c = c % 8;
                        cells[j, k * 4 + 1] = c > 3;
                        c = c % 4;
                        cells[j, k * 4 + 2] = c > 1;
                        c = c % 2;
                        cells[j, k * 4 + 3] = c > 0;

                    }
                }
                // get all the data for your case here
                computeCase(i + 1, rows, cols, cells);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
        }
        public static void computeCase(int c, int rows, int cols, bool[,] oldcells)
        {
            int[,] cells = new int[rows, cols];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (oldcells[i, j] == ((i + j) % 2 == 0))
                    {
                        cells[i, j] = 1;
                    }
                    else
                        cells[i, j] = 2;
                }
            }
            int smaller = rows;
            if (rows > cols)
                smaller = cols;
            int[] sizes = new int[smaller];
            int sizeTry = smaller;
            while(sizeTry > 1)
            {
                int y = 0;
                int x = 0;
                while(x < cols - sizeTry + 1 && y < rows - sizeTry + 1)
                {
                    int goal = cells[y,x];
                    int i = y;
                    int j = x;
                    if(goal != 0)
                    {
                        
                        while(i < y + sizeTry && cells[i,j] == goal)
                        {
                            j++;
                            if(j >= x + sizeTry)
                            {
                                j = x;
                                i++;
                            }
                        }
                    }
                    else
                    {
                        j++;
                    }
                    if(i == y + sizeTry)
                    {
                        sizes[sizeTry-1]++;
                        for(int k = y; k < y+sizeTry; k++)
                        {
                            for(int l = x; l < x + sizeTry; l++)
                            {
                                cells[k,l] = 0;
                            }
                        }
                        x += sizeTry;

                    }
                    else
                    {
                        if (j > x)
                            x = j;
                        else
                            x++;
                        
                    }
                    if(x > cols - sizeTry)
                    {
                        x = 0;
                        y++;
                    }
                }
                sizeTry--;
            }
           for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if(cells[i,j] != 0)
                        sizes[0]++;
                }
           }
            int numsizes = 0;
            for(int i = 0; i < sizes.Length; i++)
            {
                if(sizes[i] != 0)
                    numsizes++;
            }
            outLines.Add("Case #" + c.ToString() + ": " + numsizes);
            for(int i = sizes.Length - 1; i >= 0; i--)
            {
                if(sizes[i] != 0)
                {
                    outLines.Add( (i+1) + " " + sizes[i]);
                }
            }

        }
    }
}
