using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static int F(int n)
        {
            if (n % 2 == 0)
            {
                return n / 2;
            }
            else
            {
                return 3 * n + 1;
            }
        }

        static void Main()
        {
            IO io = new IO();

            //????
            int s = io.ReadLineToInt();
            int ans = 0;

            List<int> a = new List<int>();
            a.Add(s);

            while (true)
            {
                int b = F(a.Last());
                if (a.Any(A => A == b))
                {
                    ans = a.Count + 1;
                    break;
                }

                a.Add(b);
            }

            Console.Write(ans);
            Console.ReadKey();
        }
    }

    //IO??????
    public class IO
    {
        //string???
        public string ReadLineToString()
        {
            return Console.ReadLine();
        }

        //int???
        public int ReadLineToInt()
        {
            return int.Parse(Console.ReadLine());
        }

        //????????????????string[]?????
        public string[] ReadLineToStringArray()
        {
            return Console.ReadLine().Split(' ').ToArray();
        }


        //???????????????int[]?????
        public int[] ReadLineToIntArray()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }

        //????????????????List<string>?????
        public List<string> ReadLineToStringList()
        {
            return Console.ReadLine().Split(' ').ToList();
        }

        //???????????????List<int>?????
        public List<int> ReadLineToIntList()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        }

    }

}