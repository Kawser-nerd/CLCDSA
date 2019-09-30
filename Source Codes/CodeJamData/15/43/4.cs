using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P3
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var input = new FileStream("in.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(input))
				{
					using (var output = new FileStream("out.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(output))
						{
							var s = reader.ReadLine();
							var T = long.Parse(s);
							for (var t = 1; t <= T; t++)
							{
								s = reader.ReadLine();
								var N = int.Parse(s);
								var Words = new Dictionary<String, int>();
								var sentences = new List<int>[N];
								for (var i = 0; i < N; i++)
								{
									s = reader.ReadLine();
									var parts = s.Split(' ');
									sentences[i] = new List<int>(parts.Length);
									foreach (var w in parts)
									{
										int ind;
										if (!Words.TryGetValue(w, out ind))
										{
											ind = Words.Count;
											Words.Add(w, ind);
										}
										if (!sentences[i].Contains(ind))
										{
											sentences[i].Add(ind);
										}
									}
								}
								var langs = new int[Words.Count];
								var max = 1;
								for (int p = 0; p < 18; p++)
								{
									max *= 2;
								}
								var best = Words.Count;
								for (int p = 0; p < max; p++)
								{
									var pp = p;
									for (var i = 0; i < Words.Count; i++)
									{
										langs[i] = 0;
									}
									foreach (var w in sentences[0])
									{
										langs[w] |= 1;
									}
									foreach (var w in sentences[1])
									{
										langs[w] |= 2;
									}
									for (var i = 2; i < sentences.Length; i++)
									{
										var l = (pp % 2 == 1) ? 1 : 2;
										pp /= 2;
										foreach (var w in sentences[i])
										{
											langs[w] |= l;
										}
									}
									var c = 0;
									for (var i = 0; i < Words.Count; i++)
									{
										if (langs[i] == 3)
										{
											c++;
										}
									}
									if (c < best)
									{
										best = c;
									}
								}
								Console.WriteLine(t);
								writer.WriteLine(String.Format("Case #{0}: {1}", t, best));
							}
						}
					}
				}
			}
		}
	}
}