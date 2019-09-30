using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//Andrzeju, to jeszcze prościutkie zadanko i niby jestem zakwalifikowany
//ale wiesz, że muszę mieć więcej punktów od Ciebie :-p

namespace dancing
{
    class Program
    {
        class Score
        {
            public Score(params int[] scores)
            {
                Scores = scores.ToArray();
            }

            public int[] Scores;
            public bool IsAllowed
            {
                get
                {
                    return MaxScore - MinScore <= 2;
                }
            }
            public bool IsSurprising
            {
                get
                {
                    return MaxScore - MinScore == 2;
                }
            }
            public int MinScore
            {
                get
                {
                    return Scores.Min();
                }
            }
            public int MaxScore
            {
                get
                {
                    return Scores.Max();
                }
            }
            public int TotalScore
            {
                get
                {
                    return Scores.Sum();
                }
            }

        }

        static void Main(string[] args)
        {
            var allScores = new List<Score>();
            for (var first = 0; first <= 10; first++)
                for (var second = 0; second <= 10; second++)
                    for (var third = 0; third <= 10; third++)
                        allScores.Add(new Score(first, second, third));

            var allowedScores = allScores.Where(s => s.IsAllowed).ToList();

            var maxScoresNotSurprising = new int[31];
            var maxScoresSurprising = new int[31];
            for (var i = 0; i < maxScoresNotSurprising.Length; i++)
            {
                maxScoresNotSurprising[i] = allowedScores.Where(s => s.TotalScore == i && !s.IsSurprising).Max(s => s.MaxScore);
                maxScoresSurprising[i] = allowedScores.Where(s => s.TotalScore == i).Max(s => s.MaxScore);
            }

            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var input = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var googlers = input[0];
                    var surprisingResults = input[1];
                    var minimumScore = input[2];
                    var totalPoints = input.Skip(3).ToArray();
                    var result = 0;

                    foreach (var totalPoint in totalPoints)
                    {
                        if (maxScoresNotSurprising[totalPoint] >= minimumScore)
                            result++;
                        else if (surprisingResults > 0 && maxScoresSurprising[totalPoint] >= minimumScore)
                        {
                            result++;
                            surprisingResults--;
                        }
                    }

                    outputStream.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }
    }
}
