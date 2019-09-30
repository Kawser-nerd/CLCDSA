using System;
using System.Linq;
class Program{
    static void Main(){
        int[] hw = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int c = 0;
        for (int i = 0 ;i < hw[0] ;i++){
            char[] a = Console.ReadLine().ToCharArray();
            c += a.Count(s => s == '#');
        }
        string ans = (c == hw[0] + hw[1] - 1) ? "Possible" : "Impossible";
        Console.WriteLine(ans);
    }
}