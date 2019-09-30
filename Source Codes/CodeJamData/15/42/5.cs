using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P2
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
							var T = int.Parse(s);
							for (var t = 1; t <= T; t++)
							{
								s = reader.ReadLine();
								var parts = s.Split(' ');
								var N = int.Parse(parts[0]);
								var V = double.Parse(parts[1]);
								var X = double.Parse(parts[2]);
								var R = new double[N];
								var C = new double[N];
								var equals = 0.0;
								var more = 0.0;
								var moreWS = 0.0;
								var less = 0.0;
								var lessWS = 0.0;
								for (var i = 0; i < N; i++)
								{
									s = reader.ReadLine();
									parts = s.Split(' ');
									R[i] = double.Parse(parts[0]);
									C[i] = double.Parse(parts[1]);
									if (Math.Abs(C[i] - X) < 1e-6)
									{
										equals += R[i];
									}
									else if (C[i] < X - 1e-6)
									{
										less += R[i];
										lessWS += R[i] * C[i];
									}
									else if (C[i] > X + 1e-6)
									{
										more += R[i];
										moreWS += R[i] * C[i];
									}
								}
								double best;
								if (equals > 0)
								{
									best = V / equals;
								}
								else
								{
									if ((more > 0 && less == 0.0)
										|| (more == 0 && less > 0))
									{
										best = -1;
									}
									else
									{
										var moreC = moreWS / more;
										var lessC = lessWS / less;
										var vl = V * (X - moreC) / (lessC - moreC);
										var vm = V - vl;
										best = Math.Max(vl / less, vm / more);
									}
								}

								writer.WriteLine(String.Format("Case #{0}: {1}", t, best < 0 ? "IMPOSSIBLE" : best.ToString()));
							}
						}
					}
				}
			}
		}
	}
}