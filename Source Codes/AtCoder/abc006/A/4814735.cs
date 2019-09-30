using System;
using System.Linq;
class Program
{
    static void Main()
    {
int a = int.Parse(Console.ReadLine());
            if (a%3==0||a.ToString().Contains("3"))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        
        
        Console.ReadLine();
    }
}