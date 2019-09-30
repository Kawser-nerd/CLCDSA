using System;
using System.Linq;

class A{
    static void Main(){
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

        if(input[0] % input[1] == 0)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}