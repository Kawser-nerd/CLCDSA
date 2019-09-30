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
            for (int i = 0; i < input.Count(); ++i)
            {
                nums.Add( int.Parse(input[i]) );
            }
            nums.Sort();
            int b = -1;
            int maxNum = 0;
            for( int i = 0; i < input.Count(); ++i)
            {
                if( b == nums[i])
                {
                    continue;
                }
                b = nums[i];
                int res = 1;
                for( int x = i + 1; x < input.Count(); ++x)
                {                   
                    if ( nums[x] >= b + 3 )
                    {
                        break;
                    }
                    res++;
                }
                if(res > maxNum)
                {
                    maxNum = res;
                }
            }
            Console.WriteLine(maxNum);
        }
    }

}