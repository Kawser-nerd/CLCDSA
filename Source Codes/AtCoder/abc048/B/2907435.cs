using System;

namespace atcoder_ABC048B
{
    class MainClass
    {
        public static void Main(string[] args)
        {
			string[] array = Console.ReadLine().Split(' ');
			ulong startNumber = ulong.Parse(array[0]);
			ulong endNumber = ulong.Parse(array[1]);
			ulong x = ulong.Parse(array[2]);

			ulong untilEnd = endNumber / x;
			ulong untilStart = startNumber / x;

			ulong resultCount = untilEnd - untilStart;
			if (startNumber % x == 0)
			{
				resultCount++;
			}

			Console.WriteLine(resultCount);
        }
    }
}