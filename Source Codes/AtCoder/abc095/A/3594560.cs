using System;
using System.Linq;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //?????????
            string S = Console.ReadLine();
            int noodle = 700; int topping = 0;
            for (int i =0;i<3;i++){
                if(S[i] == 'o'){
                    topping += 100;
                }
            }
            Console.WriteLine(noodle + topping);
        }
    }
}