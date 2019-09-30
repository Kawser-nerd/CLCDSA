using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemCSmall
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var topicCount = int.Parse(Console.ReadLine());
                var topics = new List<Tuple<string, string>>();

                for (var topicIndex = 0; topicIndex < topicCount; topicIndex++)
                {
                    var line = Console.ReadLine();
                    var words = line.Split(' ');
                    var firstWord = words[0];
                    var lastWord = words[1];
                    topics.Add(Tuple.Create(firstWord, lastWord));
                }

                var result = TrySolve(topics, new List<Tuple<string, string>>(), 0);

                Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }

        static int? TrySolve(
            List<Tuple<string, string>> topics,
            List<Tuple<string, string>> originalTopics,
            int position)
        {
            if (position == topics.Count)
                return IsSolution(topics, originalTopics) ? topics.Count - originalTopics.Count : (int?)null;

            var nonOriginalResult = TrySolve(topics, originalTopics, position + 1);
            var originalResult = TrySolve(topics, originalTopics.Concat(new[] { topics[position] }).ToList(), position + 1);
            return nonOriginalResult > originalResult ? nonOriginalResult : originalResult ?? nonOriginalResult;
        }

        static bool IsSolution(
            List<Tuple<string, string>> topics,
            List<Tuple<string, string>> originalTopics)
        {
            return topics.All(topic => originalTopics.Any(originalTopic => originalTopic.Item1 == topic.Item1) &&
                originalTopics.Any(originalTopic => originalTopic.Item2 == topic.Item2));
        }

        static int RemoveNonOriginalTopics(
            List<Tuple<string, string>> topics,
            HashSet<string> firstWordsProcessed,
            HashSet<string> lastWordsProcessed)
        {
            var oldTopicCount = topics.Count;
            topics.RemoveAll(topic => firstWordsProcessed.Contains(topic.Item1) && lastWordsProcessed.Contains(topic.Item2));
            return oldTopicCount - topics.Count;
        }
    }

    public static class DictionaryExtensions
    {
        public static TValue GetValueOrDefault<TKey, TValue>(this IDictionary<TKey, TValue> dictionary, TKey key)
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            TValue result;
            return dictionary.TryGetValue(key, out result) ? result : default(TValue);
        }

        public static TValue GetValueOrDefault<TKey, TValue>(this IReadOnlyDictionary<TKey, TValue> dictionary, TKey key)
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            return dictionary.GetValueOrDefaultForReadOnly(key);
        }

        public static TValue GetValueOrDefault<TKey, TValue>(this Dictionary<TKey, TValue> dictionary, TKey key)
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            return dictionary.GetValueOrDefaultForReadOnly(key);
        }

        public static TValue GetValueOrDefaultForReadOnly<TKey, TValue>(
            this IReadOnlyDictionary<TKey, TValue> dictionary,
            TKey key)
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            TValue result;
            return dictionary.TryGetValue(key, out result) ? result : default(TValue);
        }

        public static TValue? GetNullableValueOrNull<TKey, TValue>(this IDictionary<TKey, TValue> dictionary, TKey key)
            where TValue : struct
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            TValue result;
            return dictionary.TryGetValue(key, out result) ? result : (TValue?)null;
        }

        public static TValue? GetNullableValueOrNull<TKey, TValue>(this IReadOnlyDictionary<TKey, TValue> dictionary, TKey key)
            where TValue : struct
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            return dictionary.GetNullableValueOrNullForReadOnly(key);
        }

        public static TValue? GetNullableValueOrNull<TKey, TValue>(this Dictionary<TKey, TValue> dictionary, TKey key)
            where TValue : struct
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            return dictionary.GetNullableValueOrNullForReadOnly(key);
        }

        public static TValue? GetNullableValueOrNullForReadOnly<TKey, TValue>(
            this IReadOnlyDictionary<TKey, TValue> dictionary,
            TKey key)
            where TValue : struct
        {
            if (dictionary == null)
                throw new ArgumentNullException(nameof(dictionary));

            TValue result;
            return dictionary.TryGetValue(key, out result) ? result : (TValue?)null;
        }
    }
}
