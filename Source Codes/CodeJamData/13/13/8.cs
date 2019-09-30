using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			string[] s = Console.ReadLine().Split(' ');
			int R = int.Parse(s[0]);
			int N = int.Parse(s[1]);
			int M = int.Parse(s[2]);
			int K = int.Parse(s[3]);

			int []num = new int[K];
			int[] results = new int[N];

			for (int testCase = 0; testCase < T; testCase++)
			{
				Console.WriteLine("Case #{0}:", testCase + 1);
				for (int r = 0; r < R; r++)
				{
					bool m5 = false, m25 = false, m125 = false, m3 = false, m9 = false, m27 = false, m16 = false, m64 = false, m4 = false, m2 = false, has2 = false, has24 = false;
					s = Console.ReadLine().Split(' ');
					for (int k = 0; k < K; k++)
					{
						num[k] = int.Parse(s[k]);

						if (num[k] % 5 == 0)
						{
							m5 = true;
							if (num[k] % 25 == 0)
							{
								m25 = true;
								if (num[k] % 125 == 0)
									m125 = true;
							}
						}
						if (num[k] % 3 == 0)
						{
							m3 = true;
							if (num[k] % 9 == 0)
							{
								m9 = true;
								if (num[k] % 27 == 0)
									m27 = true;
							}
						}

						if (num[k] % 2 == 0)
						{
							m2 = true;
							if (num[k] % 4 == 0)
							{
								m4 = true;
								if (num[k] % 16 == 0)
								{
									m16 = true;
									if (num[k] % 64 == 0)
										m64 = true;
								}
								else if (num[k] % 8 == 0)
									has24 = true;
							}
							else
								has2 = true;
						}
					}

					if (m125)
					{
						Console.WriteLine("555");
					}
					else if (m25)
					{
						if (m3)
							Console.WriteLine("553");
						else if (m4)
							Console.WriteLine("554");
						else
							Console.WriteLine("552");
					}
					else if (m5)
					{
						if (m9)
							Console.WriteLine("533");
						else if (m3)
						{
							if (m4)
								Console.WriteLine("534");
							else if (m2)
								Console.WriteLine("532");
							else
								Console.WriteLine("532");
						}
						else if (m16)
							Console.WriteLine("544");
						else if (has24)
							Console.WriteLine("542");
						else
							Console.WriteLine("522"); // Random
					}
					else
					{
						if (m27)
							Console.WriteLine("333");
						else if (m9)
						{
							if (m4)
								Console.WriteLine("334");
							else if (m2)
								Console.WriteLine("332");
							else
								Console.WriteLine("332");
						}
						else if (m3)
						{
							if (m16)
								Console.WriteLine("344");
							else if (has24)
								Console.WriteLine("342");
							else if (has2)
								Console.WriteLine("322"); //XXXX
							else
								Console.WriteLine("322"); //XXXX
						}
						else if (m64)
							Console.WriteLine("444");
						else if (m16)
							Console.WriteLine("442");
						else if (has24)
							Console.WriteLine("422"); // Random
						else if (has2)
						{
							if (m4)
								Console.WriteLine("422");
							else
								Console.WriteLine("222");
						}
						else
							Console.WriteLine("222");
					}
				}
			}
		}
	}
}
