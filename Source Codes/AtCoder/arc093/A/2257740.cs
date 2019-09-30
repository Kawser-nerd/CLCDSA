using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        public Program() { }
        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            int n = Input.GetIntN;
            var list = Input.GetIntListList(1)[0];
            list.Add(0);
            long allSum = 0;
            int pos = 0;
            for (int i = 0; i < list.Count; i++)
            {
                int next = list[i];
                allSum += Math.Abs(pos - next);
                pos = next;
            }
            for(int i = 0; i < list.Count - 1; i++)
            {
                if(i == 0)
                {
                    Console.WriteLine(allSum + Math.Abs(list[i + 1]) - (Math.Abs(list[i]) + Math.Abs(list[i] - list[i + 1])));
                }
                else
                {
                    Console.WriteLine(allSum + Math.Abs(list[i - 1] - list[i + 1]) - (Math.Abs(list[i] - list[i - 1]) + Math.Abs(list[i] - list[i + 1])));
                }
            }
        }
    }

    public class Input
    {
        public static int GetIntN { get { return int.Parse(Console.ReadLine()); } }
        public static long GetLongN { get { return long.Parse(Console.ReadLine()); } }
        public static List<List<int>> GetIntListList(int n)
        {
            var list = new List<List<int>>();
            for(int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split().Select(int.Parse).ToList();
                list.Add(temp);
            }
            return list;
        }
        public static List<List<long>> GetLongListList(long n)
        {
            var list = new List<List<long>>();
            for (int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split().Select(long.Parse).ToList();
                list.Add(temp);
            }
            return list;
        }
        public static List<Pair<int, int>> ReadPairs(int n)
        {
            List<Pair<int, int>> list = new List<Pair<int, int>>();
            for (int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split().Select(int.Parse).ToList();
                var pair = new Pair<int, int>(temp[0], temp[1]);
                list.Add(pair);
            }
            return list;
        }
        public static List<Pair<long, long>> ReadPairs(long n)
        {
            List<Pair<long, long>> list = new List<Pair<long, long>>();
            for(int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split().Select(long.Parse).ToList();
                var pair = new Pair<long, long>(temp[0], temp[1]);
                list.Add(pair);
            }
            return list;
        }
    }

    public class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
    {
        public T v1;
        public U v2;
        public Pair(T v1, U v2)
        {
            this.v1 = v1;
            this.v2 = v2;
        }
        public int CompareTo(Pair<T, U> a) => v1.CompareTo(a.v1) != 0 ? v1.CompareTo(a.v1) : v2.CompareTo(a.v2);
        public override string ToString() => v1 + " " + v2;
    }
}