using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static BigInteger GetPattern(int all, int pull)
    {
        if(all < pull || pull < 0)
            return 0;
        if(all - pull < pull)
            return GetPattern(all, all - pull);
        BigInteger result = 1;
        foreach(int i in Enumerable.Range(0, pull).Select(x => all - x))
            result *= i;
        foreach(int i in Enumerable.Range(1, pull))
            result /= i;
        return result;
    }
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int row = int.Parse(inputs[0]);
        int column = int.Parse(inputs[1]);
        inputs = Console.ReadLine().Split();
        int x = int.Parse(inputs[0]);
        int y = int.Parse(inputs[1]);
        inputs = Console.ReadLine().Split();
        int desk = int.Parse(inputs[0]);
        int server = int.Parse(inputs[1]);

        int patternA = (row - x + 1) * (column - y + 1);
        BigInteger patternB = 
              GetPattern(x       * y,       desk + server)
            - GetPattern(x * (y - 1), desk + server) * 2
            - GetPattern((x - 1) * y, desk + server) * 2
            + GetPattern((x - 1) * (y - 1), desk + server) * 4
            + GetPattern(x * (y - 2), desk + server)
            + GetPattern((x - 2) * y, desk + server)
            - GetPattern((x - 2) * (y - 1), desk + server) * 2
            - GetPattern((x - 1) * (y - 2), desk + server) * 2
            + (x > 2 && y > 2 ? GetPattern((x - 2) * (y - 2), desk + server) : 0)
            ;
        BigInteger patternC = GetPattern(desk + server, server);
        //Console.WriteLine($"{patternA} {patternB} {patternC}");
        Console.WriteLine(patternA * patternB * patternC % 1000000007);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}