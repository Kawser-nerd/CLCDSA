using System;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var initialWord = Console.ReadLine();

                var startPart = new StringBuilder();
                var endPart = new StringBuilder();
                var maxLetterLeft = initialWord.OrderByDescending(aLetter => aLetter).First();
                for (var letterIndex = initialWord.Length - 1; letterIndex >= 0; letterIndex--)
                {
                    var letter = initialWord[letterIndex];

                    if (letter == maxLetterLeft)
                    {
                        startPart.Append(letter);
                        if (letterIndex > 0)
                            maxLetterLeft = initialWord.Take(letterIndex).OrderByDescending(aLetter => aLetter).First();
                    }
                    else
                    {
                        endPart.Insert(0, letter);
                    }
                }
                var result = startPart.ToString() + endPart;

                Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }
    }
}
