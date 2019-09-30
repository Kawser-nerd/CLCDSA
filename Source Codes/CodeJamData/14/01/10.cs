using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var firstAnswer = int.Parse(inputStream.ReadLine());
                    var firstBoard = ReadBoard(inputStream);
                    var secondAnswer = int.Parse(inputStream.ReadLine());
                    var secondBoard = ReadBoard(inputStream);

                    var firstCandidates = firstBoard[firstAnswer - 1];
                    var secondCanditates = secondBoard[secondAnswer - 1];

                    var validCards = firstCandidates.Where(first => secondCanditates.Any(second => first == second)).ToArray();

                    String result;
                    if (validCards.Length == 0)
                        result = "Volunteer cheated!";
                    else if (validCards.Length > 1)
                        result = "Bad magician!";
                    else
                        result = validCards[0].ToString();

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                }
            }
        }

        static int[][] ReadBoard(StreamReader input)
        {
            var result = new int[4][];
            for (var i = 0; i < 4; i++)
            {
                result[i] = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
            }
            return result;
        }
    }
}
