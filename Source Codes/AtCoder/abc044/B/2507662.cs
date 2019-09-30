using System;

class B {
    public static void Main() {
        var a = 0;
        foreach (var i in Console.ReadLine()) a ^= 1 << (i - 'a');
        Console.WriteLine(a == 0 ? "Yes" : "No");
    }
}