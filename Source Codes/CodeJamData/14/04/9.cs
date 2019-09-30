using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeceitfulWar
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
                    inputStream.ReadLine();
                    var myStartingBlocks = inputStream.ReadLine().Split().Select(s => double.Parse(s)).ToArray();
                    var hisStartingBlocks = inputStream.ReadLine().Split().Select(s => double.Parse(s)).ToArray();

                    var fairScore = PlayBestGame(myStartingBlocks, hisStartingBlocks, true);
                    var unfairScore = PlayBestGame(myStartingBlocks, hisStartingBlocks, false);

                    outputStream.WriteLine("Case #{0}: {1} {2}", caseNumber, unfairScore, fairScore);
                }
            }
        }

        private static int PlayBestGame(IEnumerable<double> myStartingBlocks, IEnumerable<double> hisStartingBlocks, bool fair)
        {
            var myBlocks = new HashSet<double>(myStartingBlocks);
            var hisBlocks = new HashSet<double>(hisStartingBlocks);

            var myScore = 0;

            while (myBlocks.Count > 0)
            {
                double? myBlock = null;
                double? myBlockValueTold = null;
                if (!fair)
                {
                    var hisSmallest = hisBlocks.Min();
                    var canCheat = myBlocks.Any(my => my > hisSmallest);
                    if (canCheat)
                    {
                        myBlock = myBlocks.Where(my => my > hisSmallest).Min();
                        myBlockValueTold = 1.0d;
                    }
                }

                //choose my best brick
                if (!myBlock.HasValue)
                {
                    myBlock = myBlocks.Max();
                    myBlockValueTold = myBlock;
                }
                myBlocks.Remove(myBlock.Value);

                //he chosses his smallest larger than mine if he has one
                //otherwise he chooses his smallest brick to lose
                if (hisBlocks.Any(hisBlock => hisBlock > myBlockValueTold))
                {
                    var hisBlock = hisBlocks.Where(his => his > myBlockValueTold).Min();
                    hisBlocks.Remove(hisBlock);
                }
                else
                {
                    var hisBlock = hisBlocks.Min();
                    hisBlocks.Remove(hisBlock);
                    myScore++;
                }
            }

            return myScore;
        }
    }
}
