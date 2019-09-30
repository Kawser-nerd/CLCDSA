using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam {

	class Program {

		static void Main(string[] args) {
			StreamReader sr = File.OpenText(args[0]);
			StreamWriter sw = File.CreateText(args[1]);
			string[] tokens = sr.ReadLine().Split();
			int count = int.Parse(tokens[0]);
			for (int i = 0; i < count; i++) {
				string[] RkN = sr.ReadLine().Split();
				int R = int.Parse(RkN[0]);
				int capacity = int.Parse(RkN[1]);
				int N = int.Parse(RkN[2]);
				string[] more = sr.ReadLine().Split();
				int[] groupSizes = new int[N];
				for (int j = 0; j < N; j++) groupSizes[j] = int.Parse(more[j]);
				int[] nextRideIndices = new int[N];
				int[] rideSizes = new int[N];

				int rideSize = 0;
				int nextIndex = 0;
				int groupCount = 0;
				for (int j = 0; j < N; j++) {
					while (groupCount < N && rideSize + groupSizes[nextIndex] <= capacity) {
						rideSize += groupSizes[nextIndex];
						nextIndex = (nextIndex + 1) % N;
						groupCount++;
					}
					rideSizes[j] = rideSize;
					nextRideIndices[j] = nextIndex;

					// prepare for the next calculation;
					groupCount--;
					rideSize -= groupSizes[j];
				}

				nextIndex = 0;
				Int64 income = 0;
				for (int j = 0; j < R; j++) {
					income += rideSizes[nextIndex];
					nextIndex = nextRideIndices[nextIndex];
				}

				sw.WriteLine("Case #" + (1 + i).ToString() + ": " + income.ToString());
			}
			sr.Close();
			sw.Close();
		}
	}
}
