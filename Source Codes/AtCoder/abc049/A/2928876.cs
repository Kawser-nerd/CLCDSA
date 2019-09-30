using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var vowel = new List<string>(){
            "a","i","u","e","o"
        };
        var c = Console.ReadLine();
        Console.WriteLine(vowel.Contains(c) ? "vowel" : "consonant");
    }
}