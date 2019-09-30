using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			if (File.Exists("output.txt"))
				File.Delete("output.txt");
			using (var sr = new StreamReader(File.OpenRead("input.txt")))
			{
				using (var sw = new StreamWriter(File.OpenWrite("output.txt")))
				{
					var t = long.Parse(sr.ReadLine());
					for (var i = 0; i < t; i++)
					{
						var parts = sr.ReadLine().Split(' ');
						var kb = sr.ReadLine();
						var word = sr.ReadLine();
						Solve(sw, i + 1, long.Parse(parts[0]), long.Parse(parts[1]), long.Parse(parts[2]), kb, word);
					}
				}
			}
		}

		static void Solve(StreamWriter sw, long runId, long K, long L, long S, string kb, string word)
		{
			List<long> results = new List<long>();
			Solve("", kb, S, word, results);
			var dict = results.GroupBy(r => r).ToDictionary(g => (decimal)g.Key, g => (decimal)g.Count());
			var res = (decimal)results.Max() - (decimal)results.Sum() / (decimal)results.Count;
			//var max = (decimal)results.Max();
			//decimal res = 0;
			//foreach (var k in dict.Keys)
			//{
			//    if (k == 0)
			//        continue;
			//    res += (max - k) * dict[k] / total;
			//}

			res = Math.Round(res, 6);
			sw.WriteLine(string.Format(@"Case #{0}: {1}", runId, res.ToString(CultureInfo.InvariantCulture)));
		}
		static void Solve(string seq, string kb, long len, string word, List<long> results)
		{
			if (seq.Length == len)
			{
				var index = seq.IndexOf(word);
				long count = 0;
				while (index > -1)
				{
					count++;
					index = seq.IndexOf(word, index + 1);
				}
				results.Add(count);
			}
			else
			{
				for (var i = 0; i < kb.Length; i++)
				{
					Solve(seq + kb[i], kb, len, word, results);
				}
			}
		}

		//static void Solve(StreamWriter sw, long runId, long K, long L, long S, string kb, string word)
		//{
		//    var kbInfo = kb.GroupBy(k => k).ToDictionary(g => g.Key, g => g.Count());

		//    decimal wordChance = 0;
		//    foreach(var c in word) {
		//        wordChance *= (decimal)kbInfo[c] / (decimal)K;
		//    }
			
		//    int overlapPos = GetOverlapPos(word);
		//    bool couldOverlap = overlapPos > -1;
		//    bool couldOverlapInf = couldOverlap && GetOverlapPos(word + word.Substring(0, overlapPos + 1)) > -1;

		//    decimal overChance = 0;
		//    for (var ci = overlapPos + 1; ci < word.Length; ci++)
		//    {
		//        overChance *= (decimal)kbInfo[word[ci]] / (decimal)K;
		//    }

		//    decimal wordLength = word.Length;
		//    decimal overlapLength = word.Length - overlapPos - 1;

		//    decimal wordCount = 0;
		//    decimal overlapCount = 0;

		//    decimal totalChance = 0;
		//    while (true)
		//    {
		//        if (wordCount * wordLength > S)
		//            break;

		//        wordCount += 1;

		//        if (!couldOverlap) {
		//            totalChance += 
		//        }
		//    }
		//}

		//static int GetOverlapPos(string word)
		//{
		//    var last = word.Last();
		//    var index = 0;
		//    while (index > -1)
		//    {
		//        index = word.IndexOf(last, index);
		//        if (index == word.Length - 1)
		//            break;
		//        bool not = false;
		//        for (var i = 0; i <= index; i++)
		//        {
		//            if (word[word.Length - 1 - i] != word[index - i])
		//            {
		//                not = true;
		//                break;
		//            }
		//        }
		//        if (not)
		//            continue;
		//        return index;
		//    }
		//    return -1;
		//}
	}
}
