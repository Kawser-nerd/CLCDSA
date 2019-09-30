using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace KillerWord
{
    class B
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= cases; i++)
            {
                Console.Write(string.Format("Case #{0}: ", i));
                new B().Solve();
            }
        }

        private int PlayGame(List<string> words, string guess, string solution)
        {
            var eliminated = new bool[words.Count];
            var options = words.Count;
            var score = 0;

            for (int i = 0; i < words.Count; i++)
                if (words[i].Length != solution.Length)
                {
                    eliminated[i] = true;
                    options--;
                }

            for (int j = 0; j < guess.Length && options > 1; j++)
            {
                char letter = guess[j];

                var tryLetter = false;
                for (int i = 0; i < words.Count; i++)
                    if (!eliminated[i])
                        if (words[i].Contains(letter))
                        {
                            tryLetter = true;
                            break;
                        }

                if (!tryLetter)
                    continue;

                var reveal = new List<int>();
                for (int k = 0; k < solution.Length; k++)
                    if (solution[k] == letter)
                        reveal.Add(k);

                if (reveal.Count > 0)
                {
                    for (int i = 0; i < words.Count; i++)
                        if (!eliminated[i])
                            foreach (var p in reveal)
                                if (words[i][p] != letter)
                                {
                                    eliminated[i] = true;
                                    options--;
                                    break;
                                }
                    for (int i = 0; i < words.Count; i++)
                        if (!eliminated[i])
                            for (int k = 0; k < solution.Length; k++)
                                if (solution[k] != letter && words[i][k] == letter)
                                {
                                    eliminated[i] = true;
                                    options--;
                                    break;
                                }
                }
                else
                {
                    score++;
                    for (int i = 0; i < words.Count; i++)
                        if (!eliminated[i])
                            if (words[i].Contains(letter))
                            {
                                eliminated[i] = true;
                                options--;
                            }
                }
            }

            return score;
        }

        private string BestWord(List<string> words, string guess)
        {
            var bestWord = "";
            var bestScore = -1;
            for (int i = 0; i < words.Count; i++)
            {
                var score = PlayGame(words, guess, words[i]);
                if (score > bestScore)
                {
                    bestScore = score;
                    bestWord = words[i];
                }
            }

            return bestWord;
        }

        private void Solve()
        {
            var v = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToList();
            
            var w = v[0];
            var g = v[1];

            var words = new List<string>();
            for (int i = 0; i < w; i++)
                words.Add(Console.ReadLine());

            var result = new List<string>();
            for (int i = 0; i < g; i++)
                result.Add(BestWord(words, Console.ReadLine()));

            Console.WriteLine(string.Join(" ", result.ToArray()));
        }
    }
}
