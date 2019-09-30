using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace KillerWord
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFileName = args[0];
            string outputFileName = "res.txt";

            string[] inputsLine = File.ReadAllLines(inputFileName);



            int nbProblem = int.Parse(inputsLine[0]);

            string[] formatedRes = new string[nbProblem];
            int currentPos = 1;
            for (int i = 0; i < nbProblem; i++)
            {
                List<char[]> sortedAlphabets;
                List<string> possibleWords;
                ParseProblem(inputsLine, ref currentPos, out sortedAlphabets, out possibleWords);



                string tempFormat = string.Join(" ", sortedAlphabets.Select(o => Solve(o, possibleWords)));
                formatedRes[i] = string.Format("Case #{0}: {1}", i + 1, tempFormat);

            }


            File.WriteAllLines(outputFileName, formatedRes);

        }

        static void ParseProblem(string[] inputsLine, ref int currentPosition, out List<char[]> sortedAlphabets, out List<string> possibleWords)
        {
            int nbWords, nbAlphabets;
            var line1 = inputsLine[currentPosition].Split(' ');
            nbWords = int.Parse(line1[0]);
            nbAlphabets = int.Parse(line1[1]);

            possibleWords = new List<string>();
            for (int i = 0; i < nbWords; i++)
            {
                possibleWords.Add(inputsLine[currentPosition + 1 + i]);
            }
            sortedAlphabets = new List<char[]>();
            for (int j = 0; j < nbAlphabets; j++)
            {
                sortedAlphabets.Add(inputsLine[currentPosition + 1 + nbWords + j].Trim().ToCharArray());
            }
            currentPosition = currentPosition + 1 + nbWords + nbAlphabets;

        }


        static string Solve(char[] sortedAlphabet, List<string> possibleWords)
        {
            int currentMaxPoint = -1;
            int currentBestIndex = -1;
            for (int i = 0; i < possibleWords.Count; i++)
            {
                int point = Point(possibleWords[i], sortedAlphabet, possibleWords);
                if (point > currentMaxPoint)
                {
                    currentMaxPoint = point;
                    currentBestIndex = i;
                }
            }
            return possibleWords[currentBestIndex];
        }




        static int Point(string word, char[] sortedAlphabet, List<string> possibleWords)
        {
            char[] knownWord = new char[word.Count()];
            for (int i = 0; i < word.Count(); i++)
            {
                knownWord[i] = '.';
            }
            return Point(word, knownWord, sortedAlphabet, 0, possibleWords, new List<char>());
        }

        static int Point(string word, char[] knownWord, char[] sortedAlphabet, int positionAlphabet, List<string> possibleWords, List<char> foundChar)
        {
            int pointTaken = 0;
            var cleanedDico = GetCleanSet(knownWord, possibleWords, foundChar);
            if (cleanedDico.Count == 0)
            {
                throw new Exception();
            }
            if (cleanedDico.Count == 1)
            {
                return 0;
            }
            char c = sortedAlphabet[positionAlphabet];
            if (cleanedDico.Any(o => o.Contains(c)))
            {
                if (word.Contains(c))
                {
                    for (int i = 0; i < word.Count(); i++)
                    {
                        if (word.ElementAt(i) == c)
                        {
                            knownWord[i] = c;
                        }
                    }
                    foundChar.Add(c);
                }
                else
                {
                    cleanedDico = cleanedDico.Where(o => !o.Contains(c)).ToList();
                    pointTaken = 1;
                }
            }
            return pointTaken + Point(word, knownWord, sortedAlphabet, positionAlphabet + 1, cleanedDico,foundChar);
        }


        static List<string> GetCleanSet(char[] knownWord, List<string> possibleWords, List<char> foundChar)
        {
            int count = knownWord.Count();
            var t1 = possibleWords.Where(o => o.Count() == count);

            List<string> res = new List<string>();
            foreach (var item in t1)
            {
                bool ok = true;
                for (int i = 0; i < count; i++)
                {
                    char cknown = knownWord.ElementAt(i);
                    char ctested = item.ElementAt(i);
                    ok = ok &&( (cknown == '.' && !foundChar.Contains(ctested)) || (cknown==ctested));
                }
                if (ok)
                {
                    res.Add(item);
                }
            }
            return res;
        }

    }
}
