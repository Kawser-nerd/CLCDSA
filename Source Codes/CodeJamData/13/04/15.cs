using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationProblemD
{
    using System.Diagnostics;
    using System.IO;

    class Program
    {
        private static string inputFilePath = @"C:\Users\Kai\Downloads\D-large.in";
        //private static string inputFilePath = @"C:\temp\input.txt";

        static void Main(string[] args)
        {
            Console.SetOut(new StreamWriter("C:/temp/output.txt"));

            var input = ReadInput();
            var output = Compute(input);
            PrintOutput(output);

            Console.Out.Flush();
            //Console.ReadLine();
        }

        private static void PrintOutput(Output output)
        {
            for (int i = 0; i < output.Results.Count; i++)
            {
                Console.WriteLine(
                    "Case #{0}: {1}",
                    i + 1,
                    output.Results[i].Sequence == null ? "IMPOSSIBLE" : string.Join(" ", output.Results[i].Sequence));
            }
        }

        private static Output Compute(Input input)
        {
            var output = new Output();

            foreach (var c in input.Cases)
            {
                output.Results.Add(Compute(c));
            }

            return output;
        }

        private static Result Compute(TestCase input)
        {
            //if (input.Number == 17)
            //{
            //    Debugger.Break();
            //}

            var sequence = Recurse(new List<int>(input.Keys), input.Chests);

            return new Result { Sequence = sequence };
        }

        private static List<int> Recurse(List<int> keys, List<Chest> chests)
        {
            if (chests.All(c => c.IsOpen))
            {
                return new List<int>();
            }

            // early termination conditions
            var requiredKeys = chests.Where(c => !c.IsOpen).Select(c => c.KeyToOpen);
            var requiredKeyCount = requiredKeys.GroupBy(k => k).Select(g => new
                {
                    g.Key,
                    Count = g.Count()
                });

            var remainingKeys = new List<int>(keys);
            remainingKeys.AddRange(chests.Where(c => !c.IsOpen).SelectMany(c => c.KeysInside));
            var remainingKeyCount = remainingKeys.GroupBy(k => k).ToDictionary(g => g.Key, g => g.Count());

            // not enough keys of a certain type remaining
            if (requiredKeyCount.Any(keyCount => !remainingKeyCount.ContainsKey(keyCount.Key) || remainingKeyCount[keyCount.Key] < keyCount.Count))
            {
                return null;
            }

            // deadlock detection
            var unopenRemaining = chests.Where(c => !c.IsOpen).ToList();
            var tempKeys = new List<int>(keys);

            while (true)
            {
                var canProbablyOpen = unopenRemaining.Where(c => tempKeys.Contains(c.KeyToOpen)).ToList();
                tempKeys.AddRange(canProbablyOpen.SelectMany(c => c.KeysInside));
                unopenRemaining.RemoveAll(c => canProbablyOpen.Contains(c, ChestComparer.Instance));

                if (canProbablyOpen.Count == 0 && unopenRemaining.Count > 0)
                {
                    return null;
                }
                else if (unopenRemaining.Count == 0)
                {
                    break;
                }
            }

            foreach (var chest in chests.Where(c => !c.IsOpen && keys.Contains(c.KeyToOpen)))
            {
                keys.Remove(chest.KeyToOpen);
                chest.IsOpen = true;
                keys.AddRange(chest.KeysInside);

                var sequence = Recurse(keys, chests);

                if (sequence != null)
                {
                    var returnList = new List<int>();
                    returnList.Add(chest.Number);
                    returnList.AddRange(sequence);

                    return returnList;
                }

                chest.IsOpen = false;
                keys.RemoveRange(keys.Count - chest.KeysInside.Length, chest.KeysInside.Length);
                keys.Add(chest.KeyToOpen);
            }

            return null;
        }

        //private static List<int> Recurse2(List<int> keys, List<Chest> chests, int? negativeKey)
        //{
        //    if (chests.All(c => c.IsOpen))
        //    {
        //        return new List<int>();
        //    }

        //    foreach (var chest in chests.Where(c => !c.IsOpen))
        //    {
        //        if (keys.Contains(chest.KeyToOpen))
        //        {
        //            ChooseAndRecurse();
        //        }
        //        else
        //        {
        //            // can only do this if there's an unopened chest with the right key
        //            foreach (
        //                var previousChest in chests.Where(c => !c.IsOpen && c != chest && c.KeysInside.Contains(chest.KeyToOpen)))
        //            {
                        
        //            }
        //        }
        //    }

        //    return null;
        //}

        //private static List<int> ChooseAndRecurse(List<int> keys, List<Chest> chests, Chest chest, int? negativeKey)
        //{
        //    // remove and we can pick any predecesor
        //    keys.Remove(chest.KeyToOpen);
        //    chest.IsOpen = true;
        //    var keysToAdd = new List<int>(chest.KeysInside);
        //    if (negativeKey != null) keysToAdd.Remove(negativeKey.Value);

        //    keys.AddRange(keysToAdd);

        //    var sequence = Recurse2(keys, chests, null);

        //    if (sequence != null)
        //    {
        //        var returnList = new List<int>();
        //        returnList.Add(chest.Number);
        //        returnList.AddRange(sequence);

        //        return returnList;
        //    }

        //    chest.IsOpen = false;
        //    keys.RemoveRange(keys.Count - keysToAdd.Count, keysToAdd.Count);
        //    keys.Add(chest.KeyToOpen);

        //    return null;
        //}

        private static Input ReadInput()
        {
            var input = new Input();

            var inputFile = File.ReadLines(inputFilePath).ToList();
            input.Cases = new List<TestCase>();

            inputFile.RemoveAt(0);
            while (inputFile.Count > 0)
            {
                var testCase = new TestCase();

                var tokens = inputFile[0].Split(' ');
                var K = Convert.ToInt32(tokens[0]);
                var N = Convert.ToInt32(tokens[1]);
                inputFile.RemoveAt(0);

                testCase.Chests = new List<Chest>(N);

                tokens = inputFile[0].Split(' ');
                testCase.Keys = tokens.Select(t => Convert.ToInt32(t)).ToArray();
                inputFile.RemoveAt(0);

                for (int i = 0; i < N; i++)
                {
                    tokens = inputFile[0].Split(' ');
                    inputFile.RemoveAt(0);

                    testCase.Chests.Add(new Chest
                        {
                            Number = i + 1,
                            KeyToOpen = Convert.ToInt32(tokens[0]),
                            KeysInside = tokens.Skip(2).Select(t => Convert.ToInt32(t)).ToArray()
                        });
                }

                input.Cases.Add(testCase);
            }

            return input;
        }
    }

    internal class ChestComparer : IEqualityComparer<Chest>
    {
        private static readonly IEqualityComparer<Chest> instance = new ChestComparer(); 

        public static IEqualityComparer<Chest> Instance
        {
            get
            {
                return instance;
            }
        } 

        public bool Equals(Chest x, Chest y)
        {
            return x.Number == y.Number;
        }

        public int GetHashCode(Chest obj)
        {
            return obj.Number;
        }
    }

    internal class Output
    {
        public Output()
        {
            Results = new List<Result>();
        }

        public IList<Result> Results { get; set; }
    }

    internal class Input
    {
        public IList<TestCase> Cases { get; set; }
    }

    internal class TestCase
    {
        private static int count = 1;

        public TestCase()
        {
            Number = count++;
        }

        public int[] Keys { get; set; }
        public List<Chest> Chests { get; set; }
        public int Number { get; set; }
    }

    internal class Chest
    {
        public int Number { get; set; }

        public int KeyToOpen { get; set; }

        public int[] KeysInside { get; set; }

        public bool IsOpen { get; set; }
    }

    internal class Result
    {
        public List<int> Sequence { get; set; }
    }
}