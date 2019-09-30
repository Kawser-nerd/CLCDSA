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
            Find find = new Find();
            Console.WriteLine(find.Calculation());
        }
    }

    class Find
    {
        private int length;
        private string input;
        int result;

        private int Serch()
        {
            int i = 0;
            while(i < length)
            {
                switch (input[i])
                {
                    case 'A':
                        result += 4;
                        break;
                     case 'B':
                        result += 3;
                        break;
                    case 'C':
                        result += 2;
                        break;
                    case 'D':
                        result += 1;
                        break;
                }
                i++;
               
            }
            return result;
        }
        private string Input()
        {
            length = int.Parse(Console.ReadLine());
            return Console.ReadLine();
        }

        public double Calculation()
        {
            input = Input();
            int result = Serch();
            return ((double)result) / (double)length;
        }
    }
}