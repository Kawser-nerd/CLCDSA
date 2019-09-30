using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]A - 2???????? ( The longest distance )

            var items = GetItemsFromReadLines<int>().ToList();

            //????????????
            var distances = CalcDistances(items).ToList();

            //?????????
            var longestDistance = distances.Max();

            Console.WriteLine(longestDistance);
        }

        static IEnumerable<double> CalcDistances(List<List<int>> items)
        {
            for(int i = 0; i < items.Count; i++)
            {
                int x1 = items[i][0];
                int y1 = items[i][1];

                for(int j = 0; j < items.Count; j++)
                {
                    if (j != i)
                    {
                        int x2 = items[j][0];
                        int y2 = items[j][1];

                        //????????2????????
                        double d = Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2));
                        yield return d;
                    }
                }
            }
        }

        static IEnumerable<List<T>> GetItemsFromReadLines<T>(int count = 0, char separator = ' ')
        {
            //[summary]??????????????List<T>??????????

            //???????????????1?????"count"????
            if (count == 0)
            {
                string line = Console.ReadLine().TrimEnd();
                count = int.Parse(line);
            }
            
            for(int i = 0; i < count; i++)
            {
                //??????1?????
                string line = Console.ReadLine().TrimEnd();

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