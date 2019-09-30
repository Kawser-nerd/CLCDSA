using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Bsp1
{
    class Program
    {
        private const string _fileIn = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp1\Bsp1\A-large.in";
        private const string _fileOut = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp1\Bsp1\A-large.out";

        static void Main(string[] args)
        {
            int caseCount = 1;
            StreamReader sr = new StreamReader(_fileIn);
            StreamWriter sw = new StreamWriter(_fileOut);

            char[][] picture;
            
            sr.ReadLine();

            string line;
            string[] splittedLine;
            int rows, columns;

            bool impossible;

            while (!sr.EndOfStream)
            {
                impossible = false;
                line = sr.ReadLine();
                splittedLine = line.Split(' ');

                rows = int.Parse(splittedLine[0]);
                columns = int.Parse(splittedLine[1]);

                picture = new char[rows][];

                for (int i = 0; i < rows; i++)
                {
                    picture[i] = sr.ReadLine().ToCharArray();
                }

                for (int i = 0; i < rows && !impossible; i++)
                {
                    for (int j = 0; j < columns && !impossible; j++)
                    {
                        if (picture[i][j] == '#')
                        {
                            if (j < columns - 1 && i < rows - 1 &&
                                picture[i][j + 1] == '#' && picture[i + 1][j] == '#' &&
                                picture[i + 1][j + 1] == '#')
                            {
                                picture[i][j] = '/';
                                picture[i][j + 1] = '\\';
                                picture[i + 1][j] = '\\';
                                picture[i + 1][j + 1] = '/';
                            }
                            else
                                impossible = true;
                        }
                    }
                }

                sw.WriteLine("Case #{0}:", caseCount++);

                if (impossible)
                    sw.WriteLine("Impossible");
                else
                {
                    for (int i = 0; i < rows; i++)
                    {
                        sw.WriteLine(new string(picture[i]));
                    }
                }
            }

            sw.Close();
        }
    }
}
