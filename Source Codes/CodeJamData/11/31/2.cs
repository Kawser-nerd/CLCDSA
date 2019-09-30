using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            Stream inputFileStream = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            TextReader inputReader = new StreamReader(inputFileStream);

            Stream outputFileStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            TextWriter outputWriter = new StreamWriter(outputFileStream);


            string caseNumberString = inputReader.ReadLine();
            int caseNumber = int.Parse(caseNumberString.Trim());
            for (int caseIndex = 1; caseIndex <= caseNumber; ++caseIndex)
            {
                string settingString = inputReader.ReadLine();
                int rowNumber = int.Parse(settingString.Trim().Split(' ')[0]);
                int columnNumber = int.Parse(settingString.Trim().Split(' ')[1]);

                int blueTileNumber = 0;

                char[,] tileMapping = new char[rowNumber, columnNumber];
                for (int i = 0; i < rowNumber; ++i)
                {
                    string tileRowString = inputReader.ReadLine();
                    for (int j = 0; j < columnNumber; ++j)
                    {
                        char currentTile = tileRowString[j];
                        if (currentTile == '#')
                        {
                            ++blueTileNumber;
                        }

                        tileMapping[i, j] = currentTile;
                    }
                }

                // Tile Replace
                while (blueTileNumber > 0)
                {
                    int currentStartTileRow = -1;
                    int currentStartTileColumn = -1;

                    for (int i = 0; i < rowNumber; ++i)
                    {
                        for (int j = 0; j < columnNumber; ++j)
                        {
                            if (tileMapping[i, j] == '#' && IsLeftTopBlueTile(tileMapping, i, j, rowNumber, columnNumber))
                            {
                                currentStartTileRow = i;
                                currentStartTileColumn = j;
                                break;
                            }
                        }
                        if (currentStartTileRow != -1)
                            break;
                    }

                    if (currentStartTileRow == -1)
                    {
                        // No tile to replace
                        break;
                    }

                    if (currentStartTileRow == rowNumber - 1 || currentStartTileColumn == columnNumber - 1)
                    {
                        // Cannot Replace - Side Tile
                        break;
                    }

                    if (tileMapping[currentStartTileRow + 1, currentStartTileColumn] != '#' ||
                        tileMapping[currentStartTileRow, currentStartTileColumn + 1] != '#' ||
                        tileMapping[currentStartTileRow + 1, currentStartTileColumn + 1] != '#')
                    {
                        // Connot Replace - Isolated Tile
                        break;
                    }

                    tileMapping[currentStartTileRow, currentStartTileColumn] = '/';
                    tileMapping[currentStartTileRow + 1, currentStartTileColumn] = '\\';
                    tileMapping[currentStartTileRow, currentStartTileColumn + 1] = '\\';
                    tileMapping[currentStartTileRow + 1, currentStartTileColumn + 1] = '/';
                    blueTileNumber -= 4;
                }

                // Print Result
                outputWriter.WriteLine(string.Format("Case #{0}:", caseIndex));
                if (blueTileNumber == 0)
                {
                    for (int i = 0; i < rowNumber; ++i)
                    {
                        for (int j = 0; j < columnNumber; ++j)
                        {
                            outputWriter.Write(tileMapping[i, j]);
                        }
                        outputWriter.WriteLine();
                    }
                }
                else
                {
                    // Impossible
                    outputWriter.WriteLine("Impossible");
                }
            }


            outputWriter.Close();
            outputFileStream.Close();
            inputReader.Close();
            inputFileStream.Close();
        }


        static bool IsLeftTopBlueTile(char[,] tileMapping, int i, int j, int rowNumber, int columnNumber)
        {
            bool isLeftBlueTile = false;
            if (j == 0 || tileMapping[i, j - 1] != '#')
            {
                isLeftBlueTile = true;
            }

            bool isTopBlueTile = false;
            if (i == 0 || tileMapping[i - 1, j] != '#')
            {
                isTopBlueTile = true;
            }

            return isLeftBlueTile && isTopBlueTile;
        }
    }
}
