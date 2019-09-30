using System;

class B {
    public static void Main() {
        var line = Console.ReadLine().Split();
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var answer = k;
        for (int i = 1; i < n; ++i) answer *= k - 1;
        Console.WriteLine(answer);
    }
}