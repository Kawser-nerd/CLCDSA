using System;

namespace question2
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        void Run(){
            var n = int.Parse(Console.ReadLine());
            var total = 0;
            var max = 0;

            for(int i=0;i<n;i++){
                var pi = int.Parse(Console.ReadLine());
                total+=pi;
                max = Math.Max(max, pi);
            }

            Console.WriteLine($"{total-max/2}");
        }
    }
}