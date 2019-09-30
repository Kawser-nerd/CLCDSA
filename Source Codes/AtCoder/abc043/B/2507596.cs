using System;
using System.Text;

class B {
    public static void Main() {
        var s = new StringBuilder();
        foreach (var i in Console.ReadLine())
            switch (i) {
                case 'B': if (s.Length != 0) --s.Length; break;
                default: s.Append(i); break;
            }
        Console.WriteLine(s);
    }
}