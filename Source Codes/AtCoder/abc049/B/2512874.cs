using System;

class B {
    public static void Main() {
        var line = Console.ReadLine().Split();
        var h = int.Parse(line[0]);
        for (int i = 0; i < h; ++i) {
            var s = Console.ReadLine();
            Console.WriteLine(s);
            Console.WriteLine(s);
        }
    }
}