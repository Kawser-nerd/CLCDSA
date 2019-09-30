using System;

namespace test1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] array = new int[n];
            if(n < 3)
            {
                array[n - 1] = 0;
                goto fin;
            }
            array[0] = 0;
            array[1] = 0;
            array[2] = 1;

            for(int i = 3; i < n;i++)
            {
                array[i] = (array[i - 3] + array[i - 2] + array[i - 1])%10007;
            }
            
            fin:
            Console.WriteLine(array[n - 1]);
        }
    }
}