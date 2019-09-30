using System;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] array = new int[s[1]];
        int count = 0;
        for (int i = 0; i < s[0]; i ++) {
            if (count == s[1]) count = 0;
            array[count] ++;
            count ++;
        }
        Console.WriteLine(array[0]-array[s[1]-1]);
    }
}