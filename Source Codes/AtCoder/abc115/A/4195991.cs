using System;
using System.Linq;

namespace question1
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        void Run(){
            var d = int.Parse(Console.ReadLine());
            var c = 25-d;
            var text = Enumerable.Repeat("Eve", c).Aggregate("Christmas", (a,b)=>$"{a} {b}");

            Console.WriteLine(text);
        }
    }
}