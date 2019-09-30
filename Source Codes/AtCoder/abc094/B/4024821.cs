using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int N = int.Parse(s[0]);
            int M = int.Parse(s[1]);
            int X = int.Parse(s[2]);

            int[] array = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            int Cost=0;
            for(int i = X;i<N;i++){
                if(array.Contains(i)==true){
                    Cost++;
                }
            }
            int cost =0;
            for(int j = X;0<j;j--){
                if(array.Contains(j)==true){
                    cost++;
                }
            }

            Console.WriteLine(
                Cost>cost? cost:Cost
            );
        }
    }
}