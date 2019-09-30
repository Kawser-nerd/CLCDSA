using System;

class Atcoder109
{
    public static void Main()
    {
        string[] input0 = Console.ReadLine().Split(' ');
        string[] input1 = Console.ReadLine().Split(' ');
        string[] input2 = Console.ReadLine().Split(' ');
        string[] input3 = Console.ReadLine().Split(' ');

        Console.WriteLine("{0} {1} {2} {3}", input3[3], input3[2], input3[1], input3[0]);
        Console.WriteLine("{0} {1} {2} {3}", input2[3], input2[2], input2[1], input2[0]);
        Console.WriteLine("{0} {1} {2} {3}", input1[3], input1[2], input1[1], input1[0]);
        Console.WriteLine("{0} {1} {2} {3}", input0[3], input0[2], input0[1], input0[0]);
    }
}