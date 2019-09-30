using System;
using System.Linq;
class Program
{
    static void Main()
    {
        //int[] input = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
        //int a=int.Parse(Console.ReadLine());
        //string a = Console.ReadLine();
        int[] input=new int[3] ;
        for (int a = 0; a < input.Length; a++)
        {
            input[a] = int.Parse(Console.ReadLine());
        }
        int[] input2 = new int[3];
        Array.Copy(input,input2,input.Length);
        while (true)
        {
            int count = 0;
            for(int a = 0; a < input2.Length - 1; a++)
            {
                if (input2[a] < input2[a + 1])
                {
                    count++;
                    int temp = input2[a];
                    input2[a] = input2[a + 1];
                    input2[a + 1] = temp;

                }
            }
            if (count == 0) break;
        }
        for (int a = 0; a < input.Length; a++)
        {
            Console.WriteLine(Array.IndexOf(input2,input[a]) + 1);
        }
        //Console.WriteLine(input[0]%input[1]==0?"YES":"NO");
        Console.ReadLine();
    }
}