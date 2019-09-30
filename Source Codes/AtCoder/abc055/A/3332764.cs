using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int kazu = int.Parse(ReadLine());
        WriteLine(kazu*800-(kazu/15*200));
    }
}