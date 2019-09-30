/// <summary>
///	https://code.google.com/codejam/contest/3264486/dashboard#s=p2
/// </summary>


using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace BathroomStalls
{
	public class CaseInfo
	{

		public Dictionary<long, long> Distances { get; set; }
		public long Guests { get; set; }

		public static CaseInfo Parse(StreamReader inStream)
		{
			string line = inStream.ReadLine();
			string[] lineParts = line.Split();


			long distance = long.Parse(lineParts[0]);
			long guests = long.Parse(lineParts[1]);
			CaseInfo result = new CaseInfo();
			result.Distances = new Dictionary<long, long>();
			result.Distances[distance] = 1;
			result.Guests = guests;
			return result;
		}


		public string Solve()
		{
			long maxDistance = Distances.Keys.Max();

			while (Distances[maxDistance] < Guests)
			{
				long takeGuests = Distances[maxDistance];
				Distances.Remove(maxDistance);
				Guests -= takeGuests;

				if (maxDistance % 2 == 1)
				{
					long newDistance = (maxDistance - 1) / 2;
					if (!Distances.ContainsKey(newDistance))
					{
						Distances[newDistance] = 0;
					}

					Distances[newDistance] += takeGuests * 2;
				}
				else
				{
					long newDistance1 = maxDistance / 2;
					long newDistance2 = newDistance1 - 1;

					if (!Distances.ContainsKey(newDistance1))
					{
						Distances[newDistance1] = 0;
					}

					if (!Distances.ContainsKey(newDistance2))
					{
						Distances[newDistance2] = 0;
					}

					Distances[newDistance1] += takeGuests;
					Distances[newDistance2] += takeGuests;
				}

				maxDistance = Distances.Keys.Max();

				if (maxDistance == 0)
				{
					break;
				}

			}

			long lMin;
			long lMax;

			if (maxDistance == 0)
			{
				lMin = 0;
				lMax = 0;
			}
			else if (maxDistance % 2 == 1)
			{
				lMin = (maxDistance - 1) / 2;
				lMax = lMin;
			}
			else
			{
				lMax = maxDistance / 2;
				lMin = lMax - 1;
			}

			return lMax.ToString() + " " + lMin.ToString();
		}


	}


	class MainClass
	{

		public static void Main(string[] args)
		{
			Encoding encoding = new UTF8Encoding(false);
			string inFilePath = "/gcj/2017/c/in.txt";
			string outFilePath = "/gcj/2017/c/out.txt";

			List<string> resultLines = new List<string>();
			using (StreamReader inStream = new StreamReader(inFilePath, encoding))
			{
				int casesCount = int.Parse(inStream.ReadLine());
				for (int caseNumber = 1; caseNumber <= casesCount; caseNumber++)
				{
					CaseInfo c = CaseInfo.Parse(inStream);
					string solution = c.Solve();

					Console.WriteLine("Case #" + caseNumber + ": " + solution);
					resultLines.Add("Case #" + caseNumber + ": " + solution);

					//break;
				}
			}

			File.WriteAllLines(outFilePath, resultLines, encoding);

			Console.ReadKey();
		}
	}
}
