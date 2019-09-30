using System;
 
class Program
{
    static void Main(string [] args)
    {
        var n = int.Parse(Console.ReadLine());
        
        Exec(string.Empty, n);
    }
    
    static void Exec(string str, int depth)
    {
        if (depth == 0)
        {
            Console.WriteLine(str);
        }
        else
        {
            Exec(str + "a", depth - 1);
            Exec(str + "b", depth - 1);
            Exec(str + "c", depth - 1);
        }
    }
}