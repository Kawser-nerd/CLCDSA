using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;
public class CodeForces
{
#if TEST
    // To set this go to Project -> Properties -> Build -> General -> Conditional compilation symbols: -> enter 'TEST' into text box.
    const bool testing = false;
#else
const bool testing = false;
#endif

    static void program(TextReader input)
    {
        var k = int.Parse(input.ReadLine());
        var data = input.ReadLine().Split(' ').Select(long.Parse).ToList();
        var res = 2;
        long minPos = 2;
        long maxPos = 2;
        for(var i = k - 1; i >= 0; i--)
        {
            var cur = data[i];
            var minI = (long)Math.Ceiling((double)minPos / cur);
            if(minI == 0)
            {
                minI++;
            }
            if(minI*cur > maxPos)
            {
                Console.WriteLine(-1);
                return;
            }
            var maxI = (maxPos / cur);
            minPos = minI * cur;
            maxPos = maxI * cur + cur - 1;
        }
        Console.WriteLine(minPos + " " + maxPos);
    }

    public static void Main(string[] args)
    {
        if (!testing)
        { // set testing to false when submiting to codeforces
            program(Console.In); // write your program in 'program' function (its your new main !)
            return;
        }

        Console.WriteLine("Test Case(1) => expected :");
        Console.WriteLine("2\n");
        Console.WriteLine("Test Case(1) => found    :");
        program(new StringReader("4 3\n2 1 1\n"));
        Console.WriteLine();

        Console.WriteLine("Test Case(2) => expected :");
        Console.WriteLine("1\n");
        Console.WriteLine("Test Case(2) => found    :");
        program(new StringReader("3 9\n1 1 3\n"));
        Console.WriteLine();

        Console.WriteLine("Test Case(3) => expected :");
        Console.WriteLine("2147483648\n");
        Console.WriteLine("Test Case(3) => found    :");
        program(new StringReader("12345678 87654321\n43043751 1000000000 53798715\n"));
        Console.WriteLine();

    }
}