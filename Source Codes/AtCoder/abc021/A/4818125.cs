using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        int input=int.Parse(Console.ReadLine());
        int[] array1 = { 8,4,2,1};
        int[] array2 =new int[0];

        for(int a = 0; a < array1.Length; a++)
        {
            int length = array2.Length;
            int num = input / array1[a];
            input =input % array1[a];
            Array.Resize(ref array2,length+num);
            for(int b = 0; b < num; b++)
            {
                array2[b + length] = array1[a];
            }
        }
        Console.WriteLine(array2.Length);
        foreach(int element in array2)
        {
            Console.WriteLine(element);
        }
        //string a = Console.ReadLine();
        //Console.WriteLine(a==1?"ABC":"chokudai");
        Console.ReadLine();
    }
}