using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var inputs = Console.ReadLine().Split(' ').Select(c=>int.Parse(c)).ToArray();
            var absX = inputs[2] - inputs[0];
            var absY = inputs[3] - inputs[1];
            var result = new List<char>();
            result.AddRange(Enumerable.Range(0, absY).Select(_ => 'U'));
            result.AddRange(Enumerable.Range(0, absX).Select(_ => 'R'));
            result.AddRange(Enumerable.Range(0, absY).Select(_ => 'D'));
            result.AddRange(Enumerable.Range(0, absX).Select(_ => 'L'));
            result.Add('L');
            result.Add('U');
            result.AddRange(Enumerable.Range(0, absY).Select(_ => 'U'));
            result.AddRange(Enumerable.Range(0, absX).Select(_ => 'R'));
            result.Add('R');
            result.Add('D');
            result.Add('R');
            result.Add('D');
            result.AddRange(Enumerable.Range(0, absY).Select(_ => 'D'));
            result.AddRange(Enumerable.Range(0, absX).Select(_ => 'L'));
            result.Add('L');
            result.Add('U');
            Console.WriteLine(string.Join("", result));
        }
    }