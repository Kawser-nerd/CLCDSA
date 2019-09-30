using System;

namespace ABC018A
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = int.Parse(Console.ReadLine());
            var B = int.Parse(Console.ReadLine());
            var C = int.Parse(Console.ReadLine());

            int a = 0; int b = 0; int c = 0;

            if(A > B)
            {
                b++;
            }
            else
            {
                a++;
            }

            if(B > C)
            {
                c++;
            }
            else
            {
                b++;
            }
            
            if(C > A)
            {
                a++;
            }
            else
            {
                c++;
            }

            Console.WriteLine(a+1);
            Console.WriteLine(b+1);
            Console.WriteLine(c+1);

        }
    }
}