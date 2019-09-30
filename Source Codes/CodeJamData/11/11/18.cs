using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;

namespace CodeJam
{
    class Program
    {
        static string downloadFolderPath = @"c:\Users\yonie\Downloads\";

        [STAThread]
        static void Main(string[] args)
        {
            string inputFilePath = GetNewestInputFile("*.in");

            if (!File.Exists(inputFilePath))
                return;

            TextReader reader = new StreamReader(inputFilePath);

            int T = Int32.Parse(reader.ReadLine());
            List<object> results = new List<object>(T);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                results.Add(SolveFreeCell(reader));
                Console.WriteLine(String.Format("Case #{0}: {1}", caseNumber, results[caseNumber - 1]));
            }

            WriteOutFile(inputFilePath, results);
            Console.ReadKey();
        }

        private static object SolveHangman(TextReader reader)
        {
            string[] line = reader.ReadLine().Split();
            int N = int.Parse(line[0]);
            int M = int.Parse(line[1]);

            List<string> D = new List<string>(N);
            for (int i = 0; i < N; i++)
            {
                D.Add(reader.ReadLine());
            }

            List<string> L = new List<string>(M);
            for (int i = 0; i < M; i++)
            {
                L.Add(reader.ReadLine());
            }

            string[] res = new string[M];

            for (int i = 0; i < M; i++)
            {
                Console.WriteLine("List: " + L[i]);
                char[] l = L[i].ToCharArray();
                int maxPoints = int.MinValue;
                for (int j = 0; j < N; j++)
                {
                    int points = CalcPoints(D[j], l, new List<string>(D));
                    //Console.WriteLine(D[j] + ": " + points);

                    if (points > maxPoints)
                    {
                        maxPoints = points;
                        res[i] = D[j];
                    }
                }
                Console.WriteLine("Result: " + res[i]);
            }

            string result = res[0];

            for (int i = 1; i < M; i++)
            {
                result += " " + res[i];
            }

            return result;
        }

        private static int CalcPoints(string wordToChoose, char[] listToUse, List<string> D)
        {
            int points = 0;

            int wordLength = wordToChoose.Length;

            D.RemoveAll(w => w.Length != wordLength);

            while (D.Count > 1)
            {
                foreach (var letter in listToUse)
                {
                    bool shouldGuessLetter = D.Any(w => w.IndexOf(letter) > -1);

                    if (shouldGuessLetter)
                    {
                        if (wordToChoose.IndexOf(letter) > -1)
                        {
                            // letter appears in word
                            EliminateWordsWithLetterInDifferentPlaces(wordToChoose, D, letter);
                        }
                        else
                        {
                            points++;
                            EliminateWordsThatHasLetter(D, letter);
                        }
                        if (D.Count == 1)
                            break;
                    }
                }
            }
            return points;
        }

        private static void EliminateWordsThatHasLetter(List<string> D, char letter)
        {
            D.RemoveAll(w => w.IndexOf(letter) > -1);
        }

        private static void EliminateWordsWithLetterInDifferentPlaces(string wordToChoose, List<string> D, char letter)
        {
            List<int> indicesInWord = new List<int>(GetIndicesOf(wordToChoose, letter));
            D.RemoveAll(w => !IndicesOfEquals(indicesInWord, w, letter));
        }

        private static IEnumerable<int> GetIndicesOf(string wordToChoose, char letter)
        {
            int startIndex = 0;
            int indexOf = wordToChoose.IndexOf(letter, startIndex);

            while (indexOf > -1)
            {
                startIndex = indexOf + 1;
                yield return indexOf;
                indexOf = wordToChoose.IndexOf(letter, startIndex);
            }

            yield break;
        }

        private static bool IndicesOfEquals(List<int> indicesInWord, string w1, char letter)
        {
            List<int> indicesInOtherWord = new List<int>(GetIndicesOf(w1, letter));
            if (indicesInOtherWord.Count != indicesInWord.Count)
                return false;
            for (int i = 0; i < indicesInWord.Count; i++)
            {
                if (indicesInWord[i] != indicesInOtherWord[i])
                    return false;
            }
            return true;
        }

        private static object SolveFreeCell(TextReader reader)
        {
            string[] line = reader.ReadLine().Split();
            long N = long.Parse(line[0]);
            //N = 34571239485;
            int PD = int.Parse(line[1]);
            int PG = int.Parse(line[2]);

            int need2s, need5s;
            if (PD % 4 == 0)
                need2s = 0;
            else if (PD % 2 == 0)
                need2s = 1;
            else
                need2s = 2;

            if (PD % 25 == 0)
                need5s = 0;
            else if (PD % 5 == 0)
                need5s = 1;
            else
                need5s = 2;

            bool possible = false;
            for (long i = 1; i <= N; i++)
            {
                bool gamesWonInteger = false;
                if (((i % 4 == 0) || (i % 2 == 0 && need2s <= 1) || need2s == 0)
                    && ((i % 25 == 0) || (i % 5 == 0 && need5s <= 1) || need5s == 0))
                    gamesWonInteger = true;

                if (gamesWonInteger)
                {
                    //long playedToday = i;
                    //long wonToday = i * PD / 100;
                    //long lostToday = playedToday - wonToday;
                    if ((PD < 100 && PG < 100 && PD > 0 && PG > 0)
                         || (PG == 100 && PD == 100) || (PG == 0 && PD == 0))
                    {
                        possible = true;
                    }
                    break;
                }
            }

            return possible ? "Possible" : "Broken";
        }

        private static string GetNewestInputFile(string pattern)
        {
            DirectoryInfo dir = new DirectoryInfo(downloadFolderPath);
            string newestInputFile = "";
            DateTime newestInputTime = DateTime.MinValue;
            foreach (var inputFile in dir.GetFiles(pattern))
            {
                if (inputFile.LastWriteTime > newestInputTime)
                {
                    newestInputFile = inputFile.FullName;
                    newestInputTime = inputFile.LastWriteTime;
                }
            }
            return newestInputFile;
        }

        private static void WriteOutFile(string inputFilePath, List<object> results)
        {
            string outputFilePath = Path.Combine(
                Path.GetDirectoryName(inputFilePath),
                Path.GetFileNameWithoutExtension(inputFilePath) + ".out");

            int i = 0;

            while (File.Exists(outputFilePath))
            {
                outputFilePath = Path.Combine(
                    Path.GetDirectoryName(inputFilePath),
                    Path.GetFileNameWithoutExtension(inputFilePath) + (++i) + ".out");
            }

            using (TextWriter writer = new StreamWriter(outputFilePath))
            {
                int c = 1;
                foreach (object result in results)
                {
                    writer.WriteLine(String.Format("Case #{0}: {1}", c++, result));
                }
            }

            Console.WriteLine("Read file: " + inputFilePath);
            Console.WriteLine("Wrote file: " + outputFilePath + " (path in clipboard)");
            Clipboard.SetText(outputFilePath);
        }

        private static object SolveWatersheds(TextReader reader)
        {
            string res = "\n";
            string[] l = reader.ReadLine().Split();
            int H = int.Parse(l[0]);
            int W = int.Parse(l[1]);

            int[,] map = new int[H, W];
            for (int i = 0; i < H; i++)
            {
                string[] l2 = reader.ReadLine().Split();
                for (int j = 0; j < W; j++)
                {
                    map[i, j] = int.Parse(l2[j]);
                }
            }


            Point[,] parent = new Point[H, W];
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    int min = int.MaxValue;
                    int val = map[y, x];
                    int pY = y - 1;
                    int pX = x;

                    min = TryDirection(H, W, map, parent, y, x, min, y - 1, x);
                    min = TryDirection(H, W, map, parent, y, x, min, y, x - 1);
                    min = TryDirection(H, W, map, parent, y, x, min, y, x + 1);
                    min = TryDirection(H, W, map, parent, y, x, min, y + 1, x);
                }
            }

            List<Point>[,] children = new List<Point>[H, W];

            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    Point p = FindParent(x, y, parent);
                    if (children[p.Y, p.X] == null)
                        children[p.Y, p.X] = new List<Point>();
                    children[p.Y, p.X].Add(new Point(x, y));
                }
            }

            char[,] result = new char[H, W];
            char curLetter = 'a';
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    if (parent[y, x] == null)
                    {
                        foreach (var child in children[y, x])
                        {
                            result[child.Y, child.X] = curLetter;
                        }
                        curLetter++;
                    }
                }
            }


            return res + string.Format("{0} {1}", H, W);
        }

        private static Point FindParent(int x, int y, Point[,] parent)
        {
            if (parent[y, x] == null)
                return new Point(x, y);

            return FindParent(parent[y, x].Y, parent[y, x].X, parent);
        }

        private static int TryDirection(int H, int W, int[,] map, Point[,] parent, int y, int x, int min, int pY, int pX)
        {
            if (pY >= 0 && pY < H
                && pX >= 0 && pX < W
                && map[pY, pX] < map[y, x]
                && map[pY, pX] < min)
            {
                min = map[pY, pX];
                parent[y, x] = new Point(pX, pY);
            }
            return min;
        }


    }

    class Point
    {

        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }
        public int X { get; set; }
        public int Y { get; set; }
    }
}
