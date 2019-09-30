using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace test
{
    class Program
    {
        
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int N, Q;
            N = int.Parse(str[0]);
            Q = int.Parse(str[1]);
            int[] Data = new int[N + 1];
            string[] input;
            for(int a = 0; a < Q; a++)
            {
                input = Console.ReadLine().Split(' ');
                Data[int.Parse(input[0])]++;
                Data[int.Parse(input[1])]++;
            }
 
            for(int a = 0; a <= N; a++)
            {
                if(Data[a] % 2 == 1)
                {
                    Console.WriteLine("NO");
                    break;
                }
                if(a == N)
                {
                    Console.WriteLine("YES");
                    break;
                }
            }
 
        }
    }
}