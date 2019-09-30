using System;
namespace Application {
    public class PG {
        public static void Main(){
            string s = Console.ReadLine();
            string f = s.Substring(0,1).ToUpper()+s.Substring(1).ToLower();
            Console.WriteLine(f);
        }
    }
}