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
            int[] num = io.ReadLineToIntArray();
            int[] target = io.ReadLineToIntArray();

            if (num[0] >= num[1])
            {
                Console.Write(0);
            }
            else
            {

                int movecount = num[1] - num[0];

                target = target.OrderBy(t => t).ToArray();
                int[] dif = new int[num[1] - 1];

                for (int i = 0; i < target.Count() - 1; i++)
                {
                    dif[i] = Math.Abs(target[i] - target[i + 1]);
                }

                dif = dif.OrderBy(d => d).ToArray();

                int ans = 0;

                for (int i = 0; i < movecount; i++)
                {
                    ans += dif[i];
                }

                Console.Write(ans);

                Console.ReadKey();
            }
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