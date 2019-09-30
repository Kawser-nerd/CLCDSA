using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForRecords
{
    class Program
    {
        static void Main(string[] args)
        {
            Practice practice = new Practice();
            int[] resultCase = practice.Change();
            foreach(int num in resultCase)
            {
                if(num == resultCase[0])
                {
                    continue;
                }
                Console.WriteLine(num);
            }
        }
        
    }

    class Practice
    {
        private int[] cdCase;
        private int times;
        public Practice()
        {
            string[] input = Console.ReadLine().Split(' ');
            cdCase = new int[int.Parse(input[0]) + 1];
            times = int.Parse(input[1]);
        }

        private void InCd()
        {
            for(int i = 0; i < cdCase.Length; i++)
            {
                cdCase[i] = i;
            }
        }

        public int[] Change()
        {
            InCd();
            for(int i = 0; i < times; i++)
            {
                int nextListening = int.Parse(Console.ReadLine());
                for(int j = 0; j < cdCase.Length; j++)
                {
                    if(cdCase[j] == nextListening)
                    {
                        int box = cdCase[0];
                        cdCase[0] = cdCase[j];
                        cdCase[j] = box;
                    }
                }
            }
            return cdCase;
        }
    }
}