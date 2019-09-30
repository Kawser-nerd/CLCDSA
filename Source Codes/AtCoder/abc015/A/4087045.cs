using System;

namespace Test{
    class Program{
        static void Main(string[] args){
            String s = Console.ReadLine(),t=Console.ReadLine();
            if (s.Length > t.Length) Console.WriteLine(s);
            else Console.WriteLine(t);
        }
    }
}