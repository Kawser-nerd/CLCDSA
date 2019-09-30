using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var stack = new Stack<string>();
        for (int i = 0; i < n; i++)
        {
            stack.Push(Console.ReadLine());
        }

        var words = new List<string>(stack);
        while (stack.Count != 1)
        {
            var last = stack.Pop();
            var second = stack.Pop();
            if (last[0] != second[second.Length - 1] || words.Where(x => x == last).Count() != 1)
            {
                Console.WriteLine("No");
                return;
            }

            stack.Push(second);
        }

        Console.WriteLine("Yes");
    }
}