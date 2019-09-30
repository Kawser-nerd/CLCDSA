using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round2
{
    public class C
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                Console.Error.WriteLine(testcase);

                int N = int.Parse(Console.ReadLine().Trim());
                var sentences = Enumerable.Repeat(0, N).Select(_ => Console.ReadLine().Trim().Split()).ToArray();

                var wordToIndex = new Dictionary<string, int>();
                foreach (var sentence in sentences)
                {
                    foreach (var word in sentence)
                    {
                        if (!wordToIndex.ContainsKey(word))
                        {
                            wordToIndex.Add(word, wordToIndex.Count);
                        }
                    }
                }

                Func<string[], int[]> sentenceToIntArray =
                    (sentence) => sentence.Select(word => wordToIndex[word]).OrderBy(x => x).ToArray();

                var english = sentenceToIntArray(sentences[0]);
                var french = sentenceToIntArray(sentences[1]);
                var rests = sentences.Skip(2).Select(sentenceToIntArray).ToArray();

                int res = int.MaxValue;
                for (int i = 0; i < (1 << (rests.Length)); i++)
                {
                    var e = new int[wordToIndex.Count];
                    foreach (var x in english) { e[x]++; }
                    var f = new int[wordToIndex.Count];
                    foreach (var x in french) { f[x]++; }

                    for (int j = 0; j < rests.Length; j++)
                    {
                        foreach (var x in rests[j])
                        {
                            if ((i & (1 << j)) != 0) { e[x]++; }
                            else { f[x]++; }
                        }
                    }

                    int temp = 0;
                    for (int k = 0; k < wordToIndex.Count; k++)
                    {
                        if (e[k] > 0 && f[k] > 0) { temp++; }
                    }
                    res = Math.Min(res, temp);
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(res);
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
