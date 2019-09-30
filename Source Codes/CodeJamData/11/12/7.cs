using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace b
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] linea = Console.ReadLine().Split(' ');

				int N = int.Parse(linea[0]); //palabras dicc
				int M = int.Parse(linea[1]); //listas sean

				Dictionary<int, List<string>> dicc = new Dictionary<int, List<string>>();
				List<string> palabras = new List<string>();
				for (int p = 0; p < N; p++)
				{
					string pal = Console.ReadLine();
					if (!dicc.ContainsKey(pal.Length)) dicc.Add(pal.Length, new List<string>());
					dicc[pal.Length].Add(pal);
					palabras.Add(pal);
				}

				List<string> soluciones = new List<string>();
				for (int i = 0; i < M; i++)
				{
					string lista = Console.ReadLine();
					string mejor = palabras.First();
					int turnosMejor = 0;

					foreach (string palabra in palabras)
					{
						List<string> posibles = new List<string>(dicc[palabra.Length]);
						int turnos = 0;
						int tapadas = palabra.Length;
						for (int c = 0; c < lista.Length; c++)
						{
							char letra = lista[c];
							if (!posibles.Any(p => p.IndexOf(letra) >= 0)) continue;
							if (palabra.IndexOf(letra) >= 0)
							{
								//filtrar posibles con las q calcen todas las letras
								for (int pos = 0; pos < palabra.Length; pos++)
								{
									if (palabra[pos] == letra)
									{
										posibles = posibles.Where(p => p[pos] == letra).ToList();
										tapadas--;
									}
									else
									{
										posibles = posibles.Where(p => p[pos] != letra).ToList();
									}
								}
							}
							else
							{
								turnos++;
								posibles = posibles.Where(p => p.IndexOf(letra) < 0).ToList();
							}
							if (tapadas == 0) break;
						}
						if (turnos > turnosMejor)
						{
							mejor = palabra;
							turnosMejor = turnos;
						}
					}

					soluciones.Add(mejor);
				}

				Console.WriteLine("Case #{0}: {1}", caso, string.Join(" ", soluciones.ToArray()));
			}
		}
	}
}
