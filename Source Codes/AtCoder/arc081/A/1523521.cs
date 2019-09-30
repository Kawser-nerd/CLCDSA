using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProCon
{

    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            string[] input = Console.ReadLine().Split(' ');
            List<int> nums = new List<int>();
            for( int i = 0; i < input.Count(); ++i)
            {
                nums.Add(int.Parse(input[i]));
            }
            nums.Sort();
            nums.Reverse();
            int nMax = 1000000001;
            int nMax2 = 1000000001;
            bool ismax = false;
            bool isc = false;
            foreach (int i in nums)
            {
                if( nMax == i && !ismax)
                {
                    ismax = true;
                }
                else if( !ismax)
                {
                    nMax = i;
                }
                else if( nMax2 == i)
                {
                    isc = true;
                    break;
                }
                else
                {
                    nMax2 = i;
                }
            }
            if( isc)
            {
                long nas = (long)nMax * (long)nMax2;
                Console.WriteLine(nas);
            }
            else
            {
                Console.WriteLine(0);
            }
        }
    }

}