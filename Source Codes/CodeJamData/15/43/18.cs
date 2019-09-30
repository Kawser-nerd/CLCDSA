using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_2_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var N = int.Parse(Console.ReadLine());
                var dict = new Dictionary<string, int>();
                var sentences = new List<int>[N];
                for (int i = 0; i < N; i++)
                {
                    var sentence = new List<int>();
                    foreach (var word in Console.ReadLine().Split())
                    {
                        int code;
                        if (!dict.TryGetValue(word, out code))
                        {
                            dict[word] = code = dict.Count;
                        }
                        sentence.Add(code);
                    }
                    sentences[i] = sentence;
                }

                var spaceSize = 1L;
                for (int i = 0; i < N - 2; i++)
                {
                    spaceSize *= 2;
                }

                var min = int.MaxValue;
                for (long e = 0; e < spaceSize; e++)
                {
                    var langs = new bool[dict.Count, 2];
                    foreach (var word in sentences[0])
                        langs[word, 0] = true;
                    foreach (var word in sentences[1])
                        langs[word, 1] = true;
                    var le = e;
                    for (int i = 0; i < N - 2; i++)
                    {
                        var lang = le % 2;
                        le >>= 1;
                        foreach (var word in sentences[i + 2])
                            langs[word, lang] = true;
                    }
                    var bi = 0;
                    for (int i = 0; i < dict.Count; i++)
                    {
                        if (langs[i, 0] && langs[i, 1])
                            bi++;
                    }
                    if (bi < min)
                        min = bi;
                }

                Console.WriteLine("Case #{0}: {1}", testN, min);
            }
        }
    }
}
