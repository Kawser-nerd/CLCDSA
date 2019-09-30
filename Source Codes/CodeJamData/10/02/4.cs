using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using Mono.Math;

namespace gcj2
{
	class Program
	{

		static BigInteger GCD (BigInteger a, BigInteger b)
		{
			BigInteger Remainder;
			
			while (b != 0) {
				Remainder = BigInteger.Modulus (a, b);
				a = b;
				b = Remainder;
			}
			
			return a;
		}

		static BigInteger GCD (IEnumerable<BigInteger> numbers)
		{
			BigInteger gcd = numbers.First ();
			foreach (BigInteger n in numbers)
				gcd = n.GCD (gcd);
			
			return gcd;
		}

		static int compareBigInt (BigInteger.Sign a)
		{
			if (a == BigInteger.Sign.Negative)
				return -1; else if (a == BigInteger.Sign.Positive)
				return 1;
			else
				return 0;
		}
		static readonly BigInteger zero = new BigInteger (0);


		static string Solve (bool withLoop, IEnumerable<string> inputTxt)
		{
			int caseIndex = 1;
			StringBuilder output = new StringBuilder ();
			foreach (string line in inputTxt) {
				var split = line.Split (' ').ToList ();
				split.RemoveAt (0);
				BigInteger[] input = split.Select (str => BigInteger.Parse (str)).ToArray ();
				
				var sortedInput = input.ToList ();
				sortedInput.Sort (delegate(BigInteger a, BigInteger b) { return compareBigInt (a.Compare (b)); });
				BigInteger lowerValue = sortedInput.First ();
				sortedInput.RemoveAt (0);
				
				var differences = sortedInput.Select (x => BigInteger.Subtract (x, lowerValue)).ToArray ();
				BigInteger T = GCD (differences);
				BigInteger y = new BigInteger (0);
				bool found = false;
				
				if (!withLoop)
					y = BigInteger.Modulus (BigInteger.Subtract (T, BigInteger.Modulus (lowerValue, T)), T);
				else
					for (BigInteger i = 0; !found; i += T) {
						if (i >= lowerValue) {
							y = BigInteger.Subtract (i, lowerValue);
							found = sortedInput.All (x => BigInteger.Modulus (x + y, T) == zero);
						}
					}
				
				output.AppendLine (string.Format ("Case #{0}: {1}", caseIndex, y));
				caseIndex++;
			}
			output.Remove (output.Length - 1, 1);
			//Console.WriteLine (output.ToString ());
			
			return output.ToString ();
		}
		static void Main (string[] args)
		{
			var inputTxt = System.IO.File.ReadAllLines ("B-large.in").ToList ();
			inputTxt.RemoveAt (0);
			System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch ();
			
			bool withLoop;
			if(!bool.TryParse(args.FirstOrDefault(),out withLoop))
				withLoop=false;
			
			timer.Start ();
			string output = Solve (false, inputTxt);
			timer.Stop ();
			Console.WriteLine ("with loop({0}) =>{1} ms",withLoop,  timer.ElapsedMilliseconds);
			
			//	string realOutput=System.IO.File.ReadAllText("ouput.txt");
			//	Console.WriteLine("----------------------");
			//Console.WriteLine(realOutput);
			//Console.WriteLine("OKKK->>> {0}", realOutput==output.ToString());
			System.IO.File.WriteAllText (string.Format("out{0}-{1}.txt",withLoop?"(withloop)":"(withoutloop)",System.DateTime.Now.ToShortTimeString()), output.ToString ());
			Console.WriteLine(output);
		}
		
		
	}
}
