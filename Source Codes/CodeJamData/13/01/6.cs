using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace a
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string status = "Draw";
				bool ok = false;
				string[] v = {"", "", "", "", "", ""};
				for (int i = 0; i < 4; i++)
				{
					string linea = Console.ReadLine();
					if (ok)
					{
						continue;
					}
					if (linea.Replace('T', 'X') == "XXXX")
					{
						status = "X won";
						ok = true;
					}
					if (linea.Replace('T', 'O') == "OOOO")
					{
						status = "O won";
						ok = true;
					}
					if (linea.IndexOf('.') > -1)
					{
						status = "Game has not completed";
					}

					for (int j = 0; j < 4; j++)
					{
						v[j] += linea[j];
					}
					v[4] += linea[i];
					v[5] += linea[3 - i];
				}
				Console.ReadLine();
				if (!ok)
				{
					for (int i = 0; i < 6; i++)
					{
						string linea = v[i];
						if (linea.Replace('T', 'X') == "XXXX")
						{
							status = "X won";
							ok = true;
							break;
						}
						if (linea.Replace('T', 'O') == "OOOO")
						{
							status = "O won";
							ok = true;
							break;
						}
					}
				}

				Console.WriteLine("Case #{0}: {1}", caso, status);
			}
		}
	}
}
