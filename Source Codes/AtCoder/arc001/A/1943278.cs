using System;
class Program
{
    static void Main(string[] args)
    {
        // ?????
        int N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        int[] counters ={0, 0, 0, 0};
        foreach(char c in s){
            int i = (int)char.GetNumericValue(c);
            counters[i-1] += 1;
        }
        int max = 0;
        int min = N;

        foreach(int cnt in counters)
        {
            max = Math.Max(max, cnt);
            min = Math.Min(min, cnt);
        }
        Console.WriteLine(max + " " + min);
    }
}