using System;
class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int sum = new int();
        for(int i=0; i<N; i++){
            string[] s = Console.ReadLine().Split(' ');
            int l = int.Parse(s[0]);
            int r = int.Parse(s[1]);
            sum += r-l+1;
        }
        Console.WriteLine("{0}", sum);
    }
}