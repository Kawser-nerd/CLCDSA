using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using JamHelpers;
using System.Diagnostics;

namespace R1Q2
{
	//Requires libraries:
	//https://github.com/CodesInChaos/Google-Code-Jam-Helpers
	//https://github.com/CodesInChaos/ChaosUtil
	class Program : ProgramBase
	{
		public override void RunCase()
		{
			var header = ReadLine().Split();
			Debug.Assert(header.Length == 3);
			double distance = header[0].ToDouble();
			int numberOfSpeedSections = header[1].ToInt();
			int numberOfAccelerations = header[2].ToInt();
			var speedSections = new List<Tuple<double, double>>();
			for (int i = 0; i < numberOfSpeedSections; i++)
			{
				var parts = ReadLine().Split().ToDouble();
				speedSections.Add(Tuple.Create(parts[0], parts[1]));// t,x
			}
			//speedSections.Insert(0, Tuple.Create(speedSections[0].Item1 - 1E8, speedSections[0].Item2 - 1E8));
			WriteLine(CaseStr);
			var accelerations = ReadLine().Split().ToDouble().ToList();
			Debug.Assert(accelerations.Count == numberOfAccelerations);
			for (int accIndex = 0; accIndex < numberOfAccelerations; accIndex++)
			{
				double waitTime = 0;
				var acceleration = accelerations[accIndex];
				for (int secIndex = 1; secIndex < speedSections.Count; secIndex++)
				{
					double t1 = speedSections[secIndex - 1].Item1;
					double x1 = speedSections[secIndex - 1].Item2;
					double t2 = speedSections[secIndex].Item1;
					double x2 = speedSections[secIndex].Item2;
					Debug.Assert(x2 > x1);
					Debug.Assert(t2 > t1);
					if (x1 >= distance)
						continue;
					double v = (x2 - x1) / (t2 - t1);
					Debug.Assert(v > 0);
					if (x2 > distance)
						x2 = distance;
					t2 = (x2 - x1) / v + t1;
					Debug.Assert(x2 > x1);
					Debug.Assert(t2 > t1);
					double myT = Math.Sqrt(2 * x2 / acceleration);
					waitTime = Math.Max(waitTime, t2 - myT);
				}
				Debug.Assert(waitTime >= 0);
				var totalTime = Math.Sqrt(2 * distance / acceleration) + waitTime;
				WriteLine(totalTime);
			}
		}


		public static void Main()
		{
			new Program().Run();
		}
	}
}
