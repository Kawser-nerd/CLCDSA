using System;
namespace ABC011A
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int ans = 0;
            if(N==12){
                ans = 1;
            }
            else{
                ans = N + 1;
            }
            Console.WriteLine(ans);
        }
    }
}