using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var line = Console.ReadLine();
                var displayedScores = line.Split(' ');
                var displayedCoderScore = displayedScores[0];
                var displayedJammerScore = displayedScores[1];

                var result = GetInterestingScores(displayedCoderScore, displayedJammerScore, 0)
                    .OrderBy(scores => Math.Abs(long.Parse(scores.Item1) - long.Parse(scores.Item2)))
                    .ThenBy(scores => scores.Item1)
                    .ThenBy(scores => scores.Item2)
                    .First();

                Console.WriteLine("Case #{0}: {1} {2}", caseNumber, result.Item1, result.Item2);
            }
        }

        static IEnumerable<Tuple<string, string>> GetInterestingScores(
            string coderDisplayedScore,
            string jammerDisplayedScore,
            int startPosition)
        {
            if (startPosition == coderDisplayedScore.Length)
            {
                yield return Tuple.Create(coderDisplayedScore, jammerDisplayedScore);
            }
            else if (coderDisplayedScore[startPosition] == '?')
            {
                if (jammerDisplayedScore[startPosition] == '?')
                {
                    foreach (var result in GetInterestingScores(
                            ReplaceDigit(coderDisplayedScore, startPosition, '0'),
                            ReplaceDigit(jammerDisplayedScore, startPosition, '0'),
                            startPosition + 1))
                        yield return result;
                    yield return Tuple.Create(
                        GetMinScore(ReplaceDigit(coderDisplayedScore, startPosition, '1')),
                        GetMaxScore(ReplaceDigit(jammerDisplayedScore, startPosition, '0')));
                    yield return Tuple.Create(
                        GetMaxScore(ReplaceDigit(coderDisplayedScore, startPosition, '0')),
                        GetMinScore(ReplaceDigit(jammerDisplayedScore, startPosition, '1')));
                }
                else
                {
                    if (jammerDisplayedScore[startPosition] != '0')
                    {
                        yield return Tuple.Create(
                            GetMaxScore(ReplaceDigit(
                                coderDisplayedScore, 
                                startPosition, 
                                GetPreviousDigit(jammerDisplayedScore[startPosition]))),
                            GetMinScore(jammerDisplayedScore));
                    }

                    foreach (var result in GetInterestingScores(
                            ReplaceDigit(coderDisplayedScore, startPosition, jammerDisplayedScore[startPosition]),
                            jammerDisplayedScore,
                            startPosition + 1))
                        yield return result;

                    if (jammerDisplayedScore[startPosition] != '9')
                    {
                        yield return Tuple.Create(
                            GetMinScore(ReplaceDigit(
                                coderDisplayedScore,
                                startPosition,
                                GetNextDigit(jammerDisplayedScore[startPosition]))),
                            GetMaxScore(jammerDisplayedScore));
                    }
                }
            }
            else if (jammerDisplayedScore[startPosition] == '?')
            {
                if (coderDisplayedScore[startPosition] != '0')
                {
                    yield return Tuple.Create(
                        GetMinScore(coderDisplayedScore),
                        GetMaxScore(ReplaceDigit(
                            jammerDisplayedScore, 
                            startPosition, 
                            GetPreviousDigit(coderDisplayedScore[startPosition]))));
                }

                foreach (var result in GetInterestingScores(
                        coderDisplayedScore,
                        ReplaceDigit(jammerDisplayedScore, startPosition, coderDisplayedScore[startPosition]),
                        startPosition + 1))
                    yield return result;

                if (coderDisplayedScore[startPosition] != '9')
                {
                    yield return Tuple.Create(
                        GetMaxScore(coderDisplayedScore),
                        GetMinScore(ReplaceDigit(
                            jammerDisplayedScore, 
                            startPosition, 
                            GetNextDigit(coderDisplayedScore[startPosition]))));
                }
            }
            else
            {
                if (coderDisplayedScore[startPosition] < jammerDisplayedScore[startPosition])
                {
                    yield return Tuple.Create(GetMaxScore(coderDisplayedScore), GetMinScore(jammerDisplayedScore));
                }
                else if (coderDisplayedScore[startPosition] > jammerDisplayedScore[startPosition])
                {
                    yield return Tuple.Create(GetMinScore(coderDisplayedScore), GetMaxScore(jammerDisplayedScore));
                }
                else
                {
                    foreach (var result in GetInterestingScores(coderDisplayedScore, jammerDisplayedScore, startPosition + 1))
                        yield return result;
                }
            }
        }

        static string GetMinScore(string displayedScore)
        {
            return displayedScore.Replace('?', '0');
        }

        static string GetMaxScore(string displayedScore)
        {
            return displayedScore.Replace('?', '9');
        }

        static string ReplaceDigit(string value, int position, char newDigit)
        {
            if (value[position] != '?')
                throw new InvalidOperationException();

            var builder = new StringBuilder(value);
            builder[position] = newDigit;
            return builder.ToString();
        }

        static char GetPreviousDigit(char digit)
        {
            digit--;
            return digit;
        }

        static char GetNextDigit(char digit)
        {
            digit++;
            return digit;
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
