using System;
    using System.Linq;
    using System.Text.RegularExpressions;
    class A{
      static void Main(){
        var s = Console.ReadLine();
        var a = s.StartsWith("A");
        var b = s.Substring(2, s.Length - 3).Count(x => x == 'C') == 1;
        var c = !Regex.IsMatch(string.Join("", s.Substring(1).Split('C')), "[A-Z]");
        Console.WriteLine(a && b && c ? "AC" : "WA");
      }
    }