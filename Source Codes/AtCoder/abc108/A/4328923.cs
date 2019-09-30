using System;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int imp = int.Parse(Console.ReadLine());
            if(imp%2==0){
                Console.Write((imp/2)*(imp/2));
            }
            else
            {
                Console.Write((imp/2)*(imp/2+1));
            }
        }
    }
}