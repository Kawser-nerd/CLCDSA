using System;

namespace atcorder
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            atcorder.Irreversible_operation.Run();
        }
    }
    public class Irreversible_operation
    {
        public Irreversible_operation()
        {
        }
        public static void Run()
        {
            string S;
            S = Console.ReadLine();
            long num_B = 0;
            long result = 0;
            for (int i = 0; i < S.Length; i++)
            {
                if (S[i] == 'W')
                {
                    result += num_B;
                }else{
                    num_B++;
                }
            }
            Console.WriteLine(result);
        }
    }
}