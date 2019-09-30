using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

namespace GoogleCodeJam
{
    class Program
    {
        readonly StreamReader reader = new StreamReader("../../Input.txt");
        readonly StreamWriter writer = new StreamWriter("../../Output.txt");
        string bufferedLine;
        int bufferedLineIndex;

        static IEnumerable<int> ReadInts(string data)
        {
            return data.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
        }

        string ReadToken()
        {
            if (bufferedLine == null)
                bufferedLine = reader.ReadLine();
            while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            while (bufferedLineIndex >= bufferedLine.Length)
            {
                bufferedLine = reader.ReadLine();
                bufferedLineIndex = 0;
                while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                    bufferedLineIndex++;
            }
            int index = bufferedLineIndex;
            while (bufferedLineIndex < bufferedLine.Length && !char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            return bufferedLine.Substring(index, bufferedLineIndex - index);
        }

        int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            var program = new Program();
            stopwatch.Start();
            program.Run();
            stopwatch.Stop();
            program.reader.Close();
            program.writer.Close();
            Console.WriteLine("Elapsed: " + stopwatch.Elapsed);
        }

        void Run()
        {
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                var stopwatch = new Stopwatch();
                int D = ReadInt(), K = ReadInt();
                int[] numbers = ReadInts(reader.ReadLine()).ToArray();
                stopwatch.Start();
                var res = Calc(D, K, numbers);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res == -1 ? "I don't know." : res.ToString());
            }
        }

        List<int> primes;

        void GetPrimes()
        {
            if (primes != null)
                return;
            primes = new List<int>();
            bool[] notPrime = new bool[1000000];
            for (int i = 2; i < notPrime.Length; i++)
            {
                if (!notPrime[i])
                {
                    primes.Add(i);
                    if (i > notPrime.Length / i) continue;
                    for (int k = i * i; k < notPrime.Length; k+=i)
                    {
                        notPrime[k] = true;
                    }
                }
            }
        }

        int Pow(long a, int n, int p)
        {
            long r = 1;
            // a0^n0 = r * a^n
            while (n != 0)
            {
                if (n % 2 == 0)
                {
                    n /= 2;
                    a *= a;
                    a %= p;
                }
                else
                {
                    n--;
                    r *= a;
                    r %= p;
                }
            }
            return (int) r;
        }

        int Div(int a, int b, int p)
        {
            if (a == 0)
                return 0;
            long res = a * Pow(b, p - 2, p);
            return (int) (res % p);
        }

        int Next(int[] numbers, int p)
        {
            foreach (int i in numbers)
            {
                if (i >= p)
                    return -1;
            }
            int d1 = numbers[1] - numbers[0] + p;
            int d2 = numbers[2] - numbers[1] + p;
            d1 %= p;
            d2 %= p;
            long A = Div(d2, d1, p);
            long B = numbers[1] - A * numbers[0];
            if (B >= 0)
                B %= p;
            else
                B = (p - (-B) % p) % p;
            for (int i = 1; i < numbers.Length; i++)
            {
                if (numbers[i] != (numbers[i - 1] * A + B) % p)
                {
                    return -1;
                }
            }
            return (int) ((numbers[numbers.Length - 1] * A + B) % p);
        }

        int Calc(int D, int K, int[] numbers)
        {
            if (K <= 1)
                return -1;
            if (K == 2 && numbers[0] == numbers[1])
                return numbers[1];
            if (K == 2)
                return -1;
            GetPrimes();
            int upper = int.Parse("1" + new string('0', D));
            int next = -1;
            foreach (int p in primes)
            {
                if (p > upper)
                    break;
                int next1 = Next(numbers, p);
                if (next1 == -2)
                    return -1;
                if (next1 != -1)
                {
                    if (next == -1 || next == next1)
                        next = next1;
                    else
                        return -1;
                }
            }
            return next;
        }
    }
}