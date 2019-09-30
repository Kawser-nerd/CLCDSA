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
const bool testing = true;
#else
    const bool testing = false;
#endif

    private static int Next()
    {
        int c;
        int res = 0;
        do
        {
            c = reader.Read();
            if (c == -1)
                return res;
        } while (c < '0' || c > '9');
        res = c - '0';
        while (true)
        {
            c = reader.Read();
            if (c < '0' || c > '9')
                return res;
            res *= 10;
            res += c - '0';
        }
    }
    private static readonly StreamReader reader = new StreamReader(Console.OpenStandardInput(1024 * 10), Encoding.ASCII, false, 1024 * 10);
    private static readonly StreamWriter writer = new StreamWriter(Console.OpenStandardOutput(1024 * 10), Encoding.ASCII, 1024 * 10);

    static void program(TextReader input)
    {
        //var t = int.Parse(input.ReadLine());
        //for(var T = 0; T < t; T++)
        //{
            var data = input.ReadLine().Split(' ').Select(long.Parse).ToList();
        var n = data[0];
        var m = data[1];
        Console.WriteLine((1900 * m + (n - m) * 100) * Math.Pow(2, m));
        //}
        
        
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
        program(new StringReader("abacaba\n"));
        Console.WriteLine();

        Console.WriteLine("Test Case(2) => expected :");
        Console.WriteLine("1\n");
        Console.WriteLine("Test Case(2) => found    :");
        program(new StringReader("zzzzz\n"));
        Console.WriteLine();

        Console.WriteLine("Test Case(3) => expected :");
        Console.WriteLine("3\n");
        Console.WriteLine("Test Case(3) => found    :");
        program(new StringReader("abcde\n"));
        Console.WriteLine();

    }
}