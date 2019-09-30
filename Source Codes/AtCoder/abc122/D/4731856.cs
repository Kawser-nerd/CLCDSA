using System;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
class Program
{
	static void Main(string[] args)
	{
		const int A = 1;
		const int C = 2;
		const int G = 3;
		const int T = 4;

		int N = int.Parse(Console.ReadLine());

		var dic = new Dictionary<int, BigInteger>();
		
		dic.Add(A, new BigInteger(1));
		dic.Add(C, new BigInteger(1));
		dic.Add(G, new BigInteger(1));
		dic.Add(T, new BigInteger(1));

		for(int i=1; i<N; i++) {
			var temp = new Dictionary<int, BigInteger>();
			
			foreach(KeyValuePair<int, BigInteger> pair in dic){

				for(int ACGT = A; ACGT<=T; ACGT++) {
					int checkValue = (pair.Key * 10 + ACGT) % 10000;
					if(!ContainAGC(checkValue)) {
						if(temp.ContainsKey(checkValue)) {
							BigInteger bi = temp[checkValue];
							bi += pair.Value;
							temp[checkValue] = bi;
						}
						else {
							BigInteger bi = new BigInteger();
							bi += pair.Value;
							temp.Add(checkValue, bi);
						}
					}
				}
			}
			dic = temp;
		}

		BigInteger sum = 0;
		foreach(KeyValuePair<int, BigInteger> pair in dic){
			sum += pair.Value;
		}

		Console.WriteLine(sum%1000000007);
	}


	static bool ContainAGC(int val) {
		if(val/10 == 132) return true; // AGC*
		if(val/100 == 13 && val%10 == 2) return true; // AG*C
		if(val/1000 == 1 && val%100 == 32) return true; // A*GC
		if(val%1000 == 132 || val%1000 == 123 || val%1000 == 312) return true; // *AGC, *ACG, *GAC
		return false;
	}
}