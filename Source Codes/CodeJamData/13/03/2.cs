using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace Fair_and_Square
{
    class Fair_And_Square_Smart
    {
        private static bool IsPalindrome(BigInteger n)
        {
            string s = n.ToString();

            for (int i = 0; i < s.Length / 2; i++)
            {
                if (s[i] != s[s.Length - i - 1]) return false;
            }

            return true;
        }

        private static List<BigInteger> GetSquares(List<BigInteger>[] numbers)
        {
            List<BigInteger> squares = new List<BigInteger>();

            for (int i = 0; i < numbers.Length; i++)
            {
                foreach (BigInteger n in numbers[i])
                {
                    squares.Add(n * n);
                }
            }

            return squares;
        }

        private static int GetCount(List<BigInteger> squares, BigInteger a, BigInteger b)
        {
            int count = 0;
            foreach (BigInteger n in squares)
            {
                if ((n >= a) && (n <= b)) count++;
            }

            return count;
        }

        private static BigInteger Pow10(int pow)
        {
            return BigInteger.Pow(new BigInteger(10), pow);
        }

        private static void AddNumber(BigInteger number, List<BigInteger>[] numbers, int length)
        {
            if (IsPalindrome(number))
            {
                BigInteger square = number * number;
                if (IsPalindrome(square))
                {
                    numbers[length].Add(number);
                }
            }
        }

        private static void AddNumberSeries(long baseDigit, List<BigInteger>[] numbers, int length)
        {
            BigInteger number = new BigInteger(baseDigit) * Pow10(length - 1) + new BigInteger(baseDigit);  // X...X

            AddNumber(number, numbers, length);

            for (int insertLength = 1; insertLength <= length - 2; insertLength++)
            {
                for (int i = 0; i < numbers[insertLength].Count; i++)
                {
                    BigInteger numberToInsert = numbers[insertLength][i];

                    BigInteger newNumber = number + numberToInsert * Pow10((length - insertLength) / 2);
                    AddNumber(newNumber, numbers, length);
                }
            }
        }

        private static List<BigInteger>[] Generate()
        {
            List<BigInteger>[] numbers = new List<BigInteger>[101];
            for (int i = 0; i < numbers.Length; i++)
            {
                numbers[i] = new List<BigInteger>();
            }

            numbers[1].AddRange(new BigInteger[] { 1, 2, 3 });

            for (int length = 2; length <= 51; length++)   // included; 51 is the length of original number to square
            {
                AddNumberSeries(1, numbers, length);
                AddNumberSeries(2, numbers, length);
            }

            return numbers;
        }


        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"C:\Work\Trainings\Code Jam\2013 Qualification\C. Fair and Square\";
                string filenameIn = "C-large-2.in";
                string filenameOut = "C-large-2.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                List<BigInteger>[] numbers = Generate();
                List<BigInteger> squares = GetSquares(numbers);

                for (int t = 0; t < testCount; t++)
                {
                    string[] splitted = sr.ReadLine().Split(' ');

                    BigInteger A = BigInteger.Parse(splitted[0]);
                    BigInteger B = BigInteger.Parse(splitted[1]);

                    string message = GetCount(squares, A, B).ToString();
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
