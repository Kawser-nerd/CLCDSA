using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static readonly string[] Digits = 
        {
            "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
        };

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var letters = Console.ReadLine();
                var lettersLeft = letters
                    .GroupBy(letter => letter)
                    .ToDictionary(grouping => grouping.Key, grouping => grouping.Count());
                var digitsFound = new List<char>();

                ProcessDigit(lettersLeft, 0, 'Z', digitsFound);
                ProcessDigit(lettersLeft, 2, 'W', digitsFound);
                ProcessDigit(lettersLeft, 4, 'U', digitsFound);
                ProcessDigit(lettersLeft, 8, 'G', digitsFound);
                ProcessDigit(lettersLeft, 6, 'X', digitsFound);
                ProcessDigit(lettersLeft, 3, 'R', digitsFound);
                ProcessDigit(lettersLeft, 1, 'O', digitsFound);
                ProcessDigit(lettersLeft, 7, 'S', digitsFound);
                ProcessDigit(lettersLeft, 5, 'F', digitsFound);
                ProcessDigit(lettersLeft, 9, 'I', digitsFound);

                digitsFound.Sort();
                var result = new string(digitsFound.ToArray());

                Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }

        static void ProcessDigit(Dictionary<char, int> lettersLeft, int digit, char uniqueLetter, List<char> digitsFound)
        {
            var digitCount = lettersLeft.GetValueOrDefault(uniqueLetter);

            digitsFound.AddRange(Enumerable.Repeat(digit.ToString().Single(), digitCount));

            foreach (var digitLetter in Digits[digit])
            {
                lettersLeft[digitLetter] = lettersLeft.GetValueOrDefault(digitLetter) - digitCount;
            }
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
