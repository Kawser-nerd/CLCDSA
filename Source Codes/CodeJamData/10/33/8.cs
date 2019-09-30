using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace filefixit
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFile = args[0];
            var outputFile = args[1];

            using (var inputStream = new StreamReader(inputFile))
            using (var outputStream = new StreamWriter(outputFile, false))
            {
                var cases = int.Parse(inputStream.ReadLine());

                for (var caseNo = 1; caseNo <= cases; caseNo++)
                {
                    var inputData = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var width = inputData[1];
                    var height = inputData[0];

                    var board = new bool?[width,height];
                    for (var i = 0; i < height; i++)
                    {
                        var line = inputStream.ReadLine();
                        for (var j = 0; j < width / 4; j++)
                        {
                            var hex = line[j];
                            var value = (hex >= '0' && hex <= '9') ? hex - '0' : hex - 'A' + 10;
                            board[j * 4 + 0, i] = (value & 0x8) != 0;
                            board[j * 4 + 1, i] = (value & 0x4) != 0;
                            board[j * 4 + 2, i] = (value & 0x2) != 0;
                            board[j * 4 + 3, i] = (value & 0x1) != 0;
                        }
                    }

                    var results = new List<Result>();

                    var maxBoard = width;
                    if (width > height)
                        maxBoard = height;

                    for (var i = maxBoard; i >= 1; i--)
                    {
                        var count = CutoutBoards(board, width, height, i);
                        if (count > 0)
                            results.Add(new Result() { Size = i, Count = count });
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNo, results.Count);
                    foreach (var result in results)
                        outputStream.WriteLine("{0} {1}", result.Size, result.Count);
                }
            }

        }

        public static int CutoutBoards(bool?[,] board, int width, int height, int size)
        {
            var result = 0;
            for (var startingY = 0; startingY <= height - size; startingY++)
                for (var startingX = 0; startingX <= width - size; startingX++)
                {
                    if (board[startingX, startingY].HasValue)
                    {
                        var validBoard = true;
                        var currentStartingBit = board[startingX, startingY].Value;
                        for (var y = startingY; y < startingY + size; y++)
                        {
                            var validLine = true;
                            for (var x = startingX; x < startingX + size; x++)
                            {
                                if (!board[x, y].HasValue)
                                {
                                    validLine = false;
                                    break;
                                }
                                if (x == startingX)
                                {
                                    if (board[x, y].Value != currentStartingBit)
                                    {
                                        validLine = false;
                                        break;
                                    }
                                }
                                else
                                {
                                    if (board[x, y].Value == board[x - 1, y].Value)
                                    {
                                        validLine = false;
                                        break;
                                    }
                                }
                            }
                            if (!validLine)
                            {
                                validBoard = false;
                                break;
                            }
                            currentStartingBit = !currentStartingBit;
                        }

                        if (validBoard)
                        {
                            result++;
                            for (var y = startingY; y < startingY + size; y++)
                            {
                                for (var x = startingX; x < startingX + size; x++)
                                {
                                    board[x, y] = null;
                                }
                            }
                        }
                    }
                }
            return result;
        }

        public class Result
        {
            public int Size;
            public int Count;
        }
    }
}
