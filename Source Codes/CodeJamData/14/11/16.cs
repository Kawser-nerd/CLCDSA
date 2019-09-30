using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		int N, L;
		long[] Outlets, Devices;

		public TestCase(TextReader input)
		{
			var r = input.ReadInts();
			N = r[0]; L = r[1];
			Outlets = input.ReadStrings().Select(o => Convert.ToInt64(o, 2)).ToArray();
			Devices = input.ReadStrings().Select(d => Convert.ToInt64(d, 2)).ToArray();
		}

		public string GetResult()
		{
			var devices = new HashSet<long>(Devices);
			int min = int.MaxValue;
			int count = 1 << L;
			for (int i = 0; i != count; ++i)
			{
				int bitCount = Utility.CountBits(i);
				if (bitCount < min && Works(devices, i))
					min = bitCount;
			}
			return min == int.MaxValue ? "NOT POSSIBLE" : min.ToString();
		}

		private bool Works(HashSet<long> devices, int i)
		{
			var outlets = Outlets.Select(o => o ^ i).ToArray();
			return devices.IsSubsetOf(outlets);
		}
	}
}