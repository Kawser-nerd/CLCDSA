using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - 2???????? ( The longest distance )
            int n = int.Parse(Console.ReadLine());

            //N???????
            var coordinates = ReadLines<int>(n).ToList();

            //2???????????
            double maxDistance = GetMaxDistance(coordinates);

            Console.WriteLine(maxDistance);
        }

        static double GetMaxDistance(List<List<int>> coordinates)
        {
            double max = 0;

            for(int i = 0; i < coordinates.Count - 1; i++)
            {
                int x0 = coordinates[i][0];
                int y0 = coordinates[i][1];

                for (int j = i + 1; j < coordinates.Count; j++)
                {
                    int x1 = coordinates[j][0];
                    int y1 = coordinates[j][1];

                    double d = CalcDistance(x0, y0, x1, y1);

                    if (d > max)
                    {
                        max = d;
                    }
                }
            }

            return max;
        }

        static double CalcDistance(int x0, int y0, int x1, int y1)
        {
            double d = Math.Pow(x0 - x1, 2) + Math.Pow(y0 - y1, 2);
            return Math.Sqrt(d);
        }

        static IEnumerable<List<T>> ReadLines<T>(int count = 0, char separator = ' ')
        {
            //[summary]??????????????List<T>??????????

            //???????????????1?????"count"????
            if (count == 0)
            {
                string line = Console.ReadLine().TrimEnd();
                count = int.Parse(line);
            }

            for (int i = 0; i < count; i++)
            {
                //??????1?????
                string line = Console.ReadLine().TrimEnd();

                //char?????1???????
                if (typeof(T) == typeof(char))
                {
                    var list = line.ToCharArray().ToList();
                    yield return (List<T>)(object)list;
                }
                else
                {
                    //???????"separator"????
                    var list = line.Split(separator).ToList();

                    //int??????????
                    if (typeof(T) == typeof(int))
                    {
                        var numbers = list.ConvertAll(int.Parse);
                        yield return (List<T>)(object)numbers;
                    }
                    else
                    {
                        yield return (List<T>)(object)list;
                    }
                }
            }
        }
    }
}