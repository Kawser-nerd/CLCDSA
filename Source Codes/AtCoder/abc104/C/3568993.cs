using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static int d;
        static int g;

        static void Main(string[] args)
        {
            //[summary]C - All Green
            var line = ReadLine<int>().ToList();
            d = line[0];
            g = line[1] / 100;

            //????????????,?????????????????
            //(????????100???????1/100????)
            var questions = new List<Question>();

            for(int i = 1; i <= d; i++)
            {
                var question = new Question(i);
                questions.Add(question);
            }

            //????????????????????????????
            int count = (int)Math.Pow(2, d);
            var binaryNumStrs = GetBinaryNumberStrings(count).ToList();

            var counts = CountSolvedQuestions(questions, binaryNumStrs).ToList();
            Console.WriteLine(counts.Min());
        }

        static IEnumerable<int> CountSolvedQuestions(List<Question> questions,
                                                   List<string> binaryNumStrs)
        {
            foreach(var numStr in binaryNumStrs)
            {
                int score = 0;
                int count = 0;
                var indexes = Enumerable.Range(0, d).ToList();

                for (int i = 0; i < d; i++)
                {
                    var c = numStr[i];

                    if (c == '1')
                    {
                        score += questions[i].Score;
                        count += questions[i].Count;

                        indexes.Remove(i);
                    }
                }

                if (score >= g)
                {
                    yield return count;
                }
                else
                {
                    indexes.Reverse();

                    foreach(var index in indexes)
                    {
                        int questionCount = questions[index].Count;
                        int rank = questions[index].Rank;

                        for(int i = 1; i < questionCount; i++)
                        {
                            score += rank;
                            count++;

                            if (score >= g)
                            {
                                yield return count;
                            }
                        }
                    }
                }
            }
        }

        static IEnumerable<string> GetBinaryNumberStrings(int count)
        {
            //[summary]????????????2???????????

            int max = count - 1;
            decimal d = ConvertNumeralSystem(max, 2);
            int digit = d.ToString().Length;

            for(int i = 0; i < count; i++)
            {
                d = ConvertNumeralSystem(i, 2);
                string s = d.ToString().PadLeft(digit, '0');
                yield return s;
            }
        }

        static decimal ConvertNumeralSystem(decimal sourceNumber, int n)
        {
            //[summary]10??????n?????
            //??????????????????????
            //http://manabi.matiralab.com/binary/

            var list = new List<decimal>();
            decimal num = sourceNumber;

            //?????"n"?????????????
            while (num >= n)
            {
                decimal mod = num % n;
                list.Add(mod);

                num = Math.Floor(num / n);
            }

            list.Add(num);

            //???????????????
            list.Reverse();

            //List?????????????
            string s = string.Join("", list);
            return decimal.Parse(s);
        }

        static IEnumerable<T> ReadLine<T>()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            
            foreach (var s in array)
            {
                int num = int.Parse(s);
                yield return (T)(object)num;
            }
        }
    }

    class Question
    {
        public int Rank { set; get; }
        public int Count { set; get; }
        public int Score { set; get; }
        
        public Question(int rank)
        {
            var line = Console.ReadLine();
            var array = line.Split(' ');

            Rank = rank;
            Count = int.Parse(array[0]);

            int bonus = int.Parse(array[1]) / 100;
            Score = rank * Count + bonus;
        }
    }
}