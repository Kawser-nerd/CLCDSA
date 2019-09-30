using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;

namespace CodeJam_1C_2012
{
    public class Problem_A
    {
        static List<long> BoxMarkers = new List<long>();
        static List<Pair> Boxes = new List<Pair>();
        static List<long> ToyMarkers = new List<long>();
        static List<Pair> Toys = new List<Pair>();

        public static void Prob_A(string[] args)
        {
            string inputFile = "C-small-attempt0.in";
           // string inputFile = "A-small-attempt0.in";
            string outputFile = "C-small-result0.out";

            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);

            int TestCases = int.Parse(reader.ReadLine());

            for (int caseCount = 0; caseCount < TestCases; caseCount++)
            {
                Boxes = new List<Pair>();
                Toys = new List<Pair>();
                BoxMarkers.Clear();
                ToyMarkers.Clear();

                string line = reader.ReadLine();
                string[] words = line.Split(' ');

                //output:
                string sout = "Case #" + (caseCount + 1) + ": ";
                writer.Write(sout);
                Console.Write(sout);
                writer.Flush();

                long bestResult = 0;
                long marker = 0;

                int N = int.Parse(words[0]);
                int M = int.Parse(words[1]);

                line = reader.ReadLine();
                words = line.Split(' ');

                for (int i = 0; i < 2 * N; i+=2)
                {
                     Boxes.Add(new Pair(){ Number = long.Parse(words[i]), Type = int.Parse(words[i+1]) })   ;
                     marker += long.Parse(words[i]);
                     BoxMarkers.Add(marker);
                }

                marker = 0;
                line = reader.ReadLine();
                words = line.Split(' ');

                for (int i = 0; i < 2 * M; i += 2)
                {
                    Toys.Add(new Pair() { Number = long.Parse(words[i]), Type = int.Parse(words[i + 1]) });

                    marker += long.Parse(words[i]);
                    ToyMarkers.Add(marker);
                }

                long boxCounter = 0;
                long toyCounter = 0;

                dynamic comb = new ExpandoObject();
                comb.Send = default(long);
                comb.boxCounter = 0;
                comb.toyCounter = 0;
                LinkedList<dynamic> Combinations = new LinkedList<dynamic>();

                Combinations.AddFirst(comb);

                while (Combinations.Count > 0)
                {
                    var combination = Combinations.First.Value;
                    Combinations.RemoveFirst();

                    Pair boxes = GetNextBoxes(combination.boxCounter);
                    Pair toys = GetNextToys(combination.toyCounter);

                    if (boxes.Number == 0 || toys.Number == 0)
                    {
                        bestResult = Math.Max(bestResult, combination.Send);
                        continue;
                    }

                    while (boxes.Type == toys.Type)
                    {
                        long send = Math.Min(boxes.Number, toys.Number);
                        combination.Send += send;
                        combination.boxCounter += send;
                        combination.toyCounter += send;

                        boxes = GetNextBoxes(combination.boxCounter);
                        toys = GetNextToys(combination.toyCounter);

                        if (boxes.Number == 0 || toys.Number == 0)
                        {
                            bestResult = Math.Max(bestResult, combination.Send);
                            break;
                        }
                    }
                    if (boxes.Number == 0 || toys.Number == 0)
                    {
                        bestResult = Math.Max(bestResult, combination.Send);
                        continue;
                    }

                    dynamic throwBox = new ExpandoObject();
                    throwBox.Send = combination.Send;
                    throwBox.boxCounter = combination.boxCounter + boxes.Number;
                    throwBox.toyCounter = combination.toyCounter;

                    dynamic throwToy = new ExpandoObject();
                    throwToy.Send = combination.Send;
                    throwToy.boxCounter = combination.boxCounter ;
                    throwToy.toyCounter = combination.toyCounter + toys.Number;

                    Combinations.AddFirst(throwToy);
                    Combinations.AddFirst(throwBox);

                }
                writer.WriteLine(bestResult);
                Console.WriteLine(bestResult);
                writer.Flush();

            }



            Console.ReadLine();
        }

        public static Pair GetNextBoxes(long boxes)
        {
            int counter = 0;
            while (! (BoxMarkers[counter] > boxes))
            {
                counter++;
                if (counter == BoxMarkers.Count)
                    return new Pair()
                    {
                      Number = 0,
                      Type = 0
                    };
            }

            if (counter > 0)
            {
                return new Pair()
                    {
                        Number = Boxes[counter].Number + BoxMarkers[counter-1] - boxes,
                        Type = Boxes[counter].Type
                    };
            }
            else
                return new Pair()
                {
                    Number = Boxes[counter].Number - boxes,
                    Type = Boxes[counter].Type
                };
        }

        public static Pair GetNextToys(long toys)
        {
            int counter = 0;
            while (!(ToyMarkers[counter] > toys))
            {
                counter++;
                if (counter == ToyMarkers.Count)
                    return new Pair()
                    {
                        Number = 0,
                        Type = 0
                    };
            }

            if (counter > 0)
            {
                return new Pair()
                {
                    Number = Toys[counter].Number + ToyMarkers[counter - 1] - toys,
                    Type = Toys[counter].Type
                };
            }
            else
                return new Pair()
                {
                    Number = Toys[counter].Number - toys,
                    Type = Toys[counter].Type
                };
        }

        public class Pair
        {
            public long Number { get; set; }
            public int Type { get; set; }
        }
    }
}
