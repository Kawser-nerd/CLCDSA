using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    public class Program
    {
        // TODO set properties for your challenge
        private const bool ShowResultInOneLine = true;
        public const bool EachCaseHasSameLineCount = true;

        public static void Main(string[] args)
        {
            // search and read ijnputfile
            var file = Directory.GetFiles("../../../WorkingDir", "*.in").FirstOrDefault();
            if (string.IsNullOrEmpty(file)) throw new FileNotFoundException("No Inputfile found");

            var lines = File.ReadAllLines(file);

            var result = ProcessAll(lines);

            File.WriteAllText(file + ".result", result);
            new FileInfo(file).MoveTo(file + ".processed");
        }

        /// <summary>
        /// Processes a inputfile and generates the output for all the cases
        /// </summary>
        /// <param name="lines"></param>
        /// <returns></returns>
        public static string ProcessAll(string[] lines)
        {
            // Anzahl der Tests steht immer in der ersten Zeile
            var caseCount = int.Parse(lines[0]);

            // Testfälle splitten
            var cases = CreateCases(lines, caseCount);

            var sbResult = new StringBuilder();

            var counter = 1;
            foreach (var job in cases)
            {
                var result = ExcecuteSingleCase(job);

                sbResult.Append("Case #" + counter++ + ":");

                if (ShowResultInOneLine)
                {
                    sbResult.Append(" " + result);
                }
                else
                {
                    sbResult.AppendLine();
                    sbResult.Append(result);
                }
                sbResult.AppendLine();
            }
            return sbResult.ToString();
        }

        /// <summary>
        /// Runs one input case to get the correct output for it
        /// </summary>
        public static string ExcecuteSingleCase(string input)
        {
            var parts = input.Split(' ');

            var r = int.Parse(parts[0]);
            var c = int.Parse(parts[1]);
            var n = int.Parse(parts[2]);

            if (r * c - n >= n)
            {
                return "0";
            }

            /* if (Math.Min(r, c) == 1)
             {
                 var largeSide = Math.Max(r, c);

                 n -= (int)(n/2);

                 if(largeSide % 2 == 0) return n.ToString();

                 return (,);
             }*/

            var largeSide = Math.Max(r, c);
            var smallSide = Math.Min(r, c);

            var emptyStart = CalculateResultStartingWithEmptyCorner(smallSide, largeSide, n);
            var filledStart = CalculateResultStartingWithFilledCorner(smallSide, largeSide, n);

            return Math.Min(emptyStart, filledStart).ToString();
        }

        public static int CalculateResultStartingWithFilledCorner(int smallSide, int largeSide, int n)
        {
            var result = 0;
            // First Cell filled
            n -= (int)Math.Round(((double)smallSide * largeSide / 2), MidpointRounding.AwayFromZero); // place N in the rooms between
            // => every N in an empty corner couses 2 unhappy
            var freeCornerApartments = (smallSide % 2 == 1 && largeSide % 2 == 1) ? 0 : 2;
            if (smallSide == 1) freeCornerApartments /= 2;
            result += Math.Min(Math.Max(0, n), freeCornerApartments) * (smallSide == 1 ? 1 : 2);
            n -= freeCornerApartments;
            // => every N on the outer walls couses 3 unhappy
            var freeWallApartments = smallSide == 1 ? (n + freeCornerApartments) : (int)(2 * (smallSide + largeSide) - 3) / 2;
            freeWallApartments -= freeCornerApartments;
            //((int)r / 2) + ((int)c / 2) * 2;
            result += Math.Min(Math.Max(0, n), freeWallApartments) * (smallSide == 1 ? 2 : 3);
            n -= freeWallApartments;
            // => every N on the inner field couses 4 unhappy
            result += Math.Max(0, n) * 4;
            return Math.Max(0, result);
        }

        public static int CalculateResultStartingWithEmptyCorner(int smallSide, int largeSide, int n)
        {
            var result = 0;
            // First Cell empty
            n -= (int)smallSide * largeSide / 2; // place N in the rooms between
            // => every N in an empty corner couses 2 unhappy
            var freeCornerApartments = (smallSide % 2 == 1 && largeSide % 2 == 1) ? 4 : 2;
            if (smallSide == 1) freeCornerApartments /= 2;
            result += Math.Min(n, freeCornerApartments) * (smallSide == 1 ? 1 : 2);
            n -= freeCornerApartments;
            // => every N on the outer walls couses 3 unhappy
            var freeWallApartments = smallSide == 1 ? (n+freeCornerApartments) : (int)(2 * (smallSide + largeSide) - 3) / 2;
            freeWallApartments -= freeCornerApartments;
            result += Math.Min(Math.Max(0, n), freeWallApartments) * (smallSide == 1 ? 2 : 3);
            n -= freeWallApartments;
            // => every N on the inner field couses 4 unhappy
            result += Math.Max(0, n) * 4;
            return Math.Max(0, result);
        }

        public static IEnumerable<String> CreateCases(string[] caseLines, int caseCount)
        {
            if (EachCaseHasSameLineCount)
            {
                var linesPerCase = (caseLines.Length - 1) / caseCount;
                return CreateCases(caseLines, (x) => linesPerCase, caseCount);
            }

            /* First Line determines linecount for each case
             * -> This line isn't included in the resulting cases
             * Example: First line contains Linecount  */
            return CreateCases(caseLines, (x) => int.Parse(x) + 1, caseCount);

            /* Second or the combination of the first two lines determines the linecount for each case
             * -> the two lines are included in the resulting cases
             * Example: second line contains following linecount + the first and second line itself */
            return CreateCases(caseLines, (fst, snd) => int.Parse(snd) + 2, caseCount);
        }

        /// <summary>
        /// First Line determines linecount for each case
        /// </summary>
        public delegate int DetermineCaseLineLength(string firstCaseLine);

        /// <summary>
        /// Second or the combination of the first two lines determines the linecount for each case
        /// Example here: https://code.google.com/codejam/contest/32016/dashboard#s=p1
        /// </summary>
        public delegate int DetermineCaseLineLengthFromSndLine(string fstLine, string sndLine);

        /// <summary>
        /// splitts the input into single cases
        /// the first line doesn't belong to the input for a case
        /// </summary>
        public static IEnumerable<String> CreateCases(string[] caseLines, DetermineCaseLineLength detLength, int caseCount)
        {
            var curLine = 1; // 1 wegen der Zeile mit der Anzahl der Tests

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var lineCount = detLength(caseLines[curLine]);
                var count = 0;

                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (++count < lineCount)
                    {
                        curSb.AppendLine();
                    }
                }
                while (count < lineCount);

                yield return curSb.ToString();
            }
        }

        /// <summary>
        /// splitts the input into single cases
        /// the first and second line belong to the input for a case
        /// </summary>
        public static IEnumerable<String> CreateCases(string[] caseLines, DetermineCaseLineLengthFromSndLine detLength, int caseCount)
        {
            var curLine = 1; //1 => Skip the line with the Testcaseammount

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var lineCount = detLength(caseLines[curLine++], caseLines[curLine++]);

                curLine -= 2; // Both lines need to be included

                var count = 0;

                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (++count < lineCount)
                    {
                        curSb.AppendLine();
                    }
                }
                while (count < lineCount);

                yield return curSb.ToString();
            }
        }
    }
}
