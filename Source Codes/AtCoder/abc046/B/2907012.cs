using System;

namespace atcoder_ABC046B
{
    class MainClass
    {
        public static void Main(string[] args)
        {
			string[] array = Console.ReadLine().Split(' ');
			int ballCount = int.Parse(array[0]);
			int colorCount = int.Parse(array[1]);

			int answer = colorCount * (int)Math.Pow((colorCount - 1), (ballCount - 1));
			if (answer == 0)
			{
				Console.WriteLine(2147483647);
			}
			else
			{
				Console.WriteLine(answer);
			}
		}
    }
}