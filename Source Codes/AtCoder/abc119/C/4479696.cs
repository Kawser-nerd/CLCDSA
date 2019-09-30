using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Roop(int N, int i, int[] takelen, int[] takenum,int[] target,ref int min)
        {
            if (N > i)
            {
                for(int j = 0; j < 4; j++)
                {
                    takenum[i] = j;
                    Roop(N, i+1, takelen,takenum,target,ref min);
                }
            }
            else if (takenum.Any(t => t == 0) && takenum.Any(t => t == 1) && takenum.Any(t => t == 2))
            {
                int MP = GetMP(N, takelen, takenum, target);
                if (MP < min)
                {
                    min = MP;
                }
            }
        }

        static int GetMP(int N, int[] takelen, int[] takenum, int[] target)
        {
            int MP = 0;
            int[] temp = { 0, 0, 0 };
            for(int i = 0; i < N; i++)
            {
                if (takenum[i] != 3)
                {
                    temp[takenum[i]] += takelen[i];
                }
            }
            for(int i = 0; i < 3; i++)
            {
                if (takenum.Where(t => t == i).Count() > 1)
                {
                    MP += (takenum.Where(t => t == i).Count() - 1) * 10;
                }
                MP +=Math.Abs(temp[i] - target[i+1]);
            }

            return MP;
        }

        static void Main()
        {
            IO io = new IO();

            //????

            int[] target = io.ReadLineToIntArray();
            int N = target[0];
            int[] takelen = new int[N];
            for(int i = 0; i < N; i++)
            {
                takelen[i] = io.ReadLineToInt();
            }
            int[] takenum = new int[N];

            int min = int.MaxValue;

            Roop(N, 0, takelen, takenum,target,ref min);

            Console.Write(min);

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