using System;
using System.Linq;

namespace ConsoleApp1
{
	class Program
	{
		static void Main(string[] a_asArgs)
		{
			int[] l_aiInput = Console.ReadLine().Split(' ').Select(l_sItem => int.Parse(l_sItem)).ToArray();
			int l_iH = l_aiInput[0];
			int l_iW = l_aiInput[1];
			int l_iK = l_aiInput[2];

			if (l_iW == 1)
			{
				Console.WriteLine("1");
				return;
			}

			byte[][] l_aaiPattern = new byte[][] {
				new byte[] { 0x00, 0x01 },
				new byte[] { 0x02 },
				new byte[] { 0x04, 0x05 },
				new byte[] { 0x08, 0x09, 0x0a },
				new byte[] { 0x10, 0x11, 0x12, 0x14, 0x15 },
				new byte[] { 0x20, 0x21, 0x22, 0x24, 0x25, 0x28, 0x29, 0x2a },
				new byte[] { 0x40, 0x41, 0x42, 0x44, 0x45, 0x48, 0x49, 0x4a, 0x50, 0x51, 0x52, 0x54, 0x55 }
			};

			uint[] l_aiUpper = new uint[l_iW];
			uint[] l_aiLower = new uint[l_iW];
			l_aiUpper[0] = 1;

			for (int l_iY = 0; l_iY < l_iH; l_iY++)
			{
				for (int l_iPatternIndex = 0; l_iPatternIndex < l_iW - 1; l_iPatternIndex++)
				{
					foreach (byte l_iPattern in l_aaiPattern[l_iPatternIndex])
					{
						for (int l_iX = 0; l_iX < l_iW; l_iX++)
						{
							if (l_iX > 0 && (l_iPattern & (1 << l_iX - 1)) != 0)
							{
								l_aiLower[l_iX] += l_aiUpper[l_iX - 1];
							}
							else if (l_iX < l_iW - 1 && (l_iPattern & (1 << l_iX)) != 0)
							{
								l_aiLower[l_iX] += l_aiUpper[l_iX + 1];
							}
							else
							{
								l_aiLower[l_iX] += l_aiUpper[l_iX];
							}
							l_aiLower[l_iX] %= 1000000007;
						}
					}
				}
				l_aiLower.CopyTo(l_aiUpper, 0);
				Array.Clear(l_aiLower, 0, l_iW);
			}
			Console.WriteLine(l_aiUpper[l_iK - 1]);
		}
	}
}