using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace C
{
	class C
	{
		static void Main(string[] args)
		{
			string sInFileName = args[0];
			string sOutFileName = args[1];

			StreamReader oInputFile = File.OpenText(sInFileName);
			StreamWriter oOutputFile = File.CreateText(sOutFileName);

			// read T
			int T;
			string sFirstLine = oInputFile.ReadLine();
			T = Int32.Parse(sFirstLine);

			for (int i = 1; i <= T; i++)
			{
				// read M, N
				int M, N;
				string sLine = oInputFile.ReadLine();
				string[] aLine = sLine.Split(' ');
				M = Int32.Parse(aLine[0]);
				N = Int32.Parse(aLine[1]);

				byte[,] aTable = new byte[M, N];
				for (int j = 0; j < M; j++)
				{
					sLine = oInputFile.ReadLine();
					for (int k = 0; k < N / 4; k++)
					{
						byte c = (byte)sLine[k];
						if (c >= 'A') c = (byte)(c - (byte)'A' + (byte)10);
						else c -= (byte)'0';
						if ((c & 8) != 0) aTable[j, 4 * k] = 1;
						if ((c & 4) != 0) aTable[j, 4 * k + 1] = 1;
						if ((c & 2) != 0) aTable[j, 4 * k + 2] = 1;
						if ((c & 1) != 0) aTable[j, 4 * k + 3] = 1;
					}
				}

				int[] aSizes = new int[M+1];

				for (int nSize = M; nSize > 0; nSize--)
				{
					for (int y = 0; y < M - nSize + 1; y++)
					{
						for (int x = 0; x < N - nSize + 1; x++)
						{
							if (AllocBoard(aTable, x, y, nSize))
							{
								aSizes[nSize]++;
								x += nSize - 1;
							}
						}
					}
				}

				int nNonEmptySizes = 0;
				for (int l = 1; l < M+1; l++)
				{
					if (aSizes[l] > 0) nNonEmptySizes++;
				}
				oOutputFile.WriteLine("Case #{0}: {1}", i.ToString(), nNonEmptySizes.ToString());

				for (int m = M; m >= 1; m--)
				{
					if (aSizes[m] > 0)
						oOutputFile.WriteLine("{0} {1}", m.ToString(), aSizes[m]);
				}
			}

			oOutputFile.Close();
			oInputFile.Close();
		}

		static bool AllocBoard(byte[,] aTable, int x, int y, int nSize)
		{
			byte nStart = aTable[y, x];
			if (nStart == 2) return false;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < nSize; j++)
				{
					byte nCheck = aTable[y + i, x + j];
					if (nCheck == 2) return false;
					if (nCheck == nStart && (((i + j) % 2) == 1)) return false;
					if (nCheck != nStart && (((i + j) % 2) == 0)) return false;
				}
			}

			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < nSize; j++)
				{
					aTable[y + i, x + j] = 2;
				}
			}

			return true;
		}
	}
}
