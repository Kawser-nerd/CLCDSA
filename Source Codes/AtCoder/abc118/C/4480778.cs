using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            IO io = new IO();

            //????
            int N = io.ReadLineToInt();
            List<int> lifes = io.ReadLineToIntList();

            while (lifes.Distinct().Count() != 1)
            {
                lifes.RemoveAll(l => l == 0);
                lifes = lifes.Distinct().ToList();
                int min = lifes.Min();

                for (int i = 0; i < lifes.Count(); i++)
                {
                    if (lifes[i] != min)
                    {
                        lifes[i] = lifes[i] % min;
                    }

                }

            }

            Console.Write(lifes.Min());

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