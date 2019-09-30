using System;

namespace atcoder_ABC029C
{
    class MainClass
    {
		private static char[] wordArray = { 'a', 'b', 'c' };
        private static int passwordLength = int.Parse(Console.ReadLine());

        public static void Main(string[] args)
        {
            CreatePassword("");
        }

        private static void CreatePassword(string password)
        {
			if (password.Length == passwordLength) 
			{
				Console.WriteLine(password); 
				return;
			}

            for (int i = 0; i < wordArray.Length; i++)
            {
                CreatePassword(password + wordArray[i]);
            }
        }
    }
}