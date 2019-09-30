using System;

namespace Although_I_Always_Use_C_plus_plus
{
	class MainClass
	{
		public static void Main(string[] args)
		{
            int x = readInt(), i;
            for (i = 1; i * (i + 1) / 2 < x; i++) {}
            Console.Write(i);
		}

		private static int readInt()
		{
			char c;
			while ((c = (char)Console.Read()) > 0)
				if (c >= '0' && c <= '9' || c == '-') break;
			int res = 0, multi = (c == '-' ? -1 : 1);
			do
			{
				if (c == '-')
					continue;
				else if (c >= '0' && c <= '9')
					res = res * 10 + c - '0';
				else
					break;
			} while ((c = (char)Console.Read()) > 0);
			return res;
		}
	}
}