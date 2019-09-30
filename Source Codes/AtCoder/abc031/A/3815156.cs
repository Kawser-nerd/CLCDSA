using System;
using System.Linq;
using System.Numerics;
using System.Collections;
using System.Collections.Generic;

public class Program {
    static void Main (string[] args) {
        var L = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();
        var A = L[0];
        var B = L[1];
        Console.WriteLine(A < B ? (A+1)*B : (B+1)*A);
    }
}