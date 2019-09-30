using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Problem5
    {
        private const string INPUT = "B-large.in";
        private const string OUTPUT = "B-large.out";

        static void Main(string[] args)
        {
            var input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT).ToList();
            var output = new List<string>();
            int i = 1;
            int count = 0;
            while(i < input.Count)
            {
                int numLevels = Convert.ToInt32(input[i]);
                output.Add("Case #" + ++count + ": " + GetResult(input.Skip(i + 1).Take(numLevels)));
                i += numLevels + 1;
                Console.WriteLine(i);
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);
        }

        private static string GetResult(IEnumerable<string> input)
        {
            var levels = new List<Level>();
            foreach (var level in input)
            {
                var split = level.Split().Select(n => Convert.ToInt32(n)).ToList();
                var levelObj = new Level()
                {
                    OneStarRating = split[0],
                    TwoStarRating = split[1]
                };
                levels.Add(levelObj);
            }

            int numberOfTurns = 0;
            int numberOfStars = 0;
            while (levels.Count > 0)
            {
                var winableTwoStarLevel = levels.Where(n => !n.GotTwoStarRating && n.TwoStarRating <= numberOfStars).FirstOrDefault();
                if (winableTwoStarLevel != null)
                {
                    winableTwoStarLevel.GotTwoStarRating = true;
                    if (winableTwoStarLevel.GotOneStarRating)
                    {
                        numberOfStars += 1;
                    }
                    else
                    {
                        numberOfStars += 2;
                    }

                    if (winableTwoStarLevel.GotTwoStarRating)
                    {
                        levels.Remove(winableTwoStarLevel);
                    }
                    
                    numberOfTurns++;
                }
                else
                {
                    var winableOneStarLevel = levels.Where(n => !n.GotOneStarRating && n.OneStarRating <= numberOfStars).OrderByDescending(n => n.TwoStarRating).FirstOrDefault();
                    if (winableOneStarLevel != null)
                    {
                        winableOneStarLevel.GotOneStarRating = true;
                        if (winableOneStarLevel.GotOneStarRating && winableOneStarLevel.GotTwoStarRating)
                        {
                            levels.Remove(winableOneStarLevel);
                        }
                        numberOfStars += 1;
                        numberOfTurns++;
                    }
                    else
                    {
                        return "Too Bad";
                    }
                }
            }
            return numberOfTurns.ToString();
        }

        private class Level
        {
            public int OneStarRating { get; set; }
            public bool GotOneStarRating { get; set; }
            public int TwoStarRating { get; set; }
            public bool GotTwoStarRating { get; set; }
        }


    }
}
