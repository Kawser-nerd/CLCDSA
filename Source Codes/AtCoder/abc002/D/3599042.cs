using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]D - ??
            var line = ReadLine();
            int n = line[0];    //??????
            int m = line[1];    //??????

            if (m == 0)
            {
                Console.WriteLine("1");
            }
            else
            {
                //"1 2"????????????????
                var relations = GetHumanRelations(m);

                //??????
                var allLawMakers = Enumerable.Range(1, n).ToList();

                for (int i = 0; i < n; i++)
                {
                    //?????????????????????????
                    int num = n - i;

                    //????????????????????????????
                    //(???5??3?????????????: 123,124,125,234,235,345)
                    var lawMakerPairs = MyMath.AllCombinations<int>(allLawMakers, num);

                    foreach(var pair in lawMakerPairs)
                    {
                        bool isHabatsu = IsCreateHabatsu(pair, relations);

                        if (isHabatsu)
                        {
                            Console.WriteLine(num);
                            return;
                        }
                    }
                }
            }
        }

        static bool IsCreateHabatsu(List<int> lawMakerPair, Dictionary<string, string> relations)
        {
            var combinations = MyMath.AllCombinations<int>(lawMakerPair, 2);

            foreach (var c in combinations)
            {
                var s = String.Join(" ", c);

                if (!relations.ContainsKey(s))
                {
                    return false;
                }
            }

            return true;
        }

        static Dictionary<string, string> GetHumanRelations(int m)
        {
            var dic = new Dictionary<string, string>();

            for (int i = 0; i < m; i++)
            {
                string s = Console.ReadLine().TrimEnd();
                dic.Add(s, null);
            }

            return dic;
        } 

        static List<int> ReadLine()
        {
            var line = Console.ReadLine().TrimEnd();
            var array = line.Split(' ');
            var numbers = new List<int>();

            foreach (var s in array)
            {
                int num = int.Parse(s);
                numbers.Add(num);
            }

            return numbers;
        }
    }

    class MyMath
    {
        public static IEnumerable<List<T>> AllCombinations<T>(List<T> source, int n,
                                                       bool isAllowDupication = false)
        {
            //[summary]????????n??????????????
            //"isAllowDupication"?"true"????????????
            //(????????n???????????????????)

            if (n == 1)
            {
                foreach (var s in source)
                {
                    yield return new List<T> { s };
                }

                yield break;
            }
            else
            {
                for (int i = 0; i < source.Count; i++)
                {
                    List<T> clone;

                    if (isAllowDupication)
                    {
                        //????????????????????
                        clone = new List<T>(source);
                        clone.RemoveAt(i);
                    }
                    else
                    {
                        //???????????????????????????
                        clone = new List<T>(source.Skip(i + 1));
                    }

                    //????
                    var items = AllCombinations(clone, n - 1, isAllowDupication);

                    foreach (var item in items)
                    {
                        item.Insert(0, source[i]);
                        yield return item;
                    }
                }
            }
        }
    }
}