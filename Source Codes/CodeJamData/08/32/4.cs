using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1c._2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    int casesCount = int.Parse(reader.ReadLine());
                    for (int i = 0; i < casesCount; i++)
                    {
                        List<int> digits = reader.ReadLine().ToCharArray().Select(c => int.Parse(c.ToString())).ToList();

                        long result = FindResult(digits);

                        writer.WriteLine("Case #{0}: {1}", i + 1, result);
                    }
                }
            }
        }

        private static long FindResult(List<int> digits)
        {
            List<Dictionary<ModuloCount, long>> results = new List<Dictionary<ModuloCount, long>>();
            results.Add(new Dictionary<ModuloCount, long>());
            for (int i = 0; i < digits.Count; i++)
            {
                Dictionary<ModuloCount, long> newResult = new Dictionary<ModuloCount, long>();

                for (int j = i; j >= 0; j--)
                {
                    List<int> startNumber = digits.GetRange(digits.Count - 1 - i, j + 1);
                    ModuloCount startModulo = new ModuloCount(startNumber);
                    Process(startModulo, results[i - j], newResult);
                }

                results.Add(newResult);
            }

            long result = 0;
            foreach (var entry in results[results.Count - 1])
            {
                if (entry.Key.IsUgly())
                    result += entry.Value;
            }
            return result;
        }

        private static void Process(ModuloCount startModulo, Dictionary<ModuloCount, long> previousResult, Dictionary<ModuloCount, long> newResult)
        {
            foreach (var entry in previousResult)
            {
                ModuloCount newAddModulo = startModulo.Add(entry.Key);
                newResult.Increment(newAddModulo, entry.Value);
                ModuloCount newSubModulo = startModulo.Subtract(entry.Key);
                newResult.Increment(newSubModulo, entry.Value);
            }

            if (previousResult.Count == 0)
            {
                newResult.Increment(startModulo, 1);
            }
        }

    }

        public class ModuloCount
        {
            public int mod2;
            public int mod3;
            public int mod5;
            public int mod7;

            public ModuloCount(List<int> digits)
            {
                for (int i = 0; i < digits.Count; i++)
                {
                    mod2 = mod2 * 10;
                    mod2 += digits[i];
                    mod2 = mod2 % 2;

                    mod3 = mod3 * 10;
                    mod3 += digits[i];
                    mod3 = mod3 % 3;

                    mod5 = mod5 * 10;
                    mod5 += digits[i];
                    mod5 = mod5 % 5;

                    mod7 = mod7 * 10;
                    mod7 += digits[i];
                    mod7 = mod7 % 7;

                }
            }

            public ModuloCount(int digit)
            {
                mod2 = digit % 2;
                mod3 = digit % 3;
                mod5 = digit % 5;
                mod7 = digit % 7;
            }

            private ModuloCount()
            {
            }

            public ModuloCount Add(ModuloCount rest)
            {
                ModuloCount result = new ModuloCount();
                result.mod2 = (this.mod2 + rest.mod2) % 2;
                result.mod3 = (this.mod3 + rest.mod3) % 3;
                result.mod5 = (this.mod5 + rest.mod5) % 5;
                result.mod7 = (this.mod7 + rest.mod7) % 7;
                return result;
            }

            public ModuloCount Subtract(ModuloCount rest)
            {
                ModuloCount result = new ModuloCount();
                result.mod2 = (this.mod2 - rest.mod2 + 2) % 2;
                result.mod3 = (this.mod3 - rest.mod3 + 3) % 3;
                result.mod5 = (this.mod5 - rest.mod5 + 5) % 5;
                result.mod7 = (this.mod7 - rest.mod7 + 7) % 7;
                return result;
            }

            public override bool Equals(object obj)
            {
                ModuloCount other = (ModuloCount)obj;
                return mod2 == other.mod2 && mod3 == other.mod3 && mod5 == other.mod5 && mod7 == other.mod7;
            }

            public override int GetHashCode()
            {
                return mod2 ^ mod3 ^ mod5 ^ mod7;
            }

            public bool IsUgly()
            {
                return mod2 == 0 || mod3 == 0 || mod5 == 0 || mod7 == 0;
            }
        }

    public static class Extenders
    {
        public static void Increment(this Dictionary<ModuloCount, long> dictionary, ModuloCount modulo, long value)
        {
            if (!dictionary.ContainsKey(modulo))
                dictionary.Add(modulo, value);
            else
                dictionary[modulo] = dictionary[modulo] + value;
        }
    }
}
