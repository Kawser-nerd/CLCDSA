using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		// Alice and Bob have a lawn in front of their house, shaped like an N metre by M metre rectangle.
		// Each year, they try to cut the lawn in some interesting pattern.
		// They used to do their cutting with shears, which was very time-consuming;
		// but now they have a new automatic lawnmower with multiple settings, and they want to try it out.

		// The new lawnmower has a height setting - you can set it to any height h between 1 and 100 millimetres,
		// and it will cut all the grass higher than h it encounters to height h.
		// You run it by entering the lawn at any part of the edge of the lawn; then the lawnmower goes in a straight line,
		// perpendicular to the edge of the lawn it entered, cutting grass in a swath 1m wide,
		// until it exits the lawn on the other side.
		// The lawnmower's height can be set only when it is not on the lawn.

		// Alice and Bob have a number of various patterns of grass that they could have on their lawn.
		// For each of those, they want to know whether it's possible to cut the grass into this pattern with their new lawnmower.
		// Each pattern is described by specifying the height of the grass on each 1m x 1m square of the lawn.

		// The grass is initially 100mm high on the whole lawn.

		// Each test case begins with a line containing two numbers: N and M.
		// Next follow N lines, with the ith line containing M numbers a[i,j] each, the number a[i,j] describing
		// the desired height of the grass in the jth square of the ith row.

		int N; // 1 ≤ N ≤ 10|100
		int M; // 1 ≤ M ≤ 10|100
		int[,] A; // 1 ≤ A[i, j] ≤ 2|100.

		public TestCase(TextReader input)
		{
			var x = input.ReadInts();
			N = x[0]; M = x[1];
			A = new int[N, M];
			Enumerable.Range(0, N).ForEach(i => input.ReadInts().ForEach((ch, j) => A[i, j] = ch));
		}

		public string GetResult()
		{
			// Return either the word "YES" if it's possible to get the pattern using the lawnmower,
			// or "NO", if it's impossible (quotes for clarity only).
			var rowMax = A.GetRows().Select(r => r.Max()).ToArray();
			var columnMax = A.GetColumns().Select(c => c.Max()).ToArray();
			return Enumerable.Range(0, N).All(i => Enumerable.Range(0, M).All(j => rowMax[i] <= A[i, j] || columnMax[j] <= A[i, j]))
				? "YES"
				: "NO";
		}
	}
}