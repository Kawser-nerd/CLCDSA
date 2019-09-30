using System;
class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        if( N % 10 == 9 || N / 10 == 9){
            Console.WriteLine("Yes");
        }else{
            Console.WriteLine("No");
        }
    }
}