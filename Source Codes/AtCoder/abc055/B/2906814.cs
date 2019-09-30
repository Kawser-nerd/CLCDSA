using System;

namespace atcoder_ABC055B
{
    class MainClass
    {
        public static void Main(string[] args)
        {
			long N = int.Parse(Console.ReadLine());
			long power = 1;
			for (long i = 1; i <= N; i++)
			{
				power *= i;

				power %= 1000000007;
			}

			Console.WriteLine(power % 1000000007);
        }
    }
}