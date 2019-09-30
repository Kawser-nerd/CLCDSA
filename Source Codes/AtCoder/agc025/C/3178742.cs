using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string str = Console.ReadLine();
		long N = long.Parse(str);
		long[,] LR = new long[N,2];
		long[] L = new long[N];
		long[] R = new long[N];
		for(var i=0;i<N;i++){
			string[] str2 = Console.ReadLine().Split();
			LR[i,0] = long.Parse(str2[0]);
			LR[i,1] = long.Parse(str2[1]);
			L[i] = LR[i,0];
			R[i] = LR[i,1];
		}
		Array.Sort(L);
		Array.Sort(R);
		long count = 0;
		long count2 = 0;
		long n1 = 0;
		long n2 = N-1;
		long nn = 0;
		while(true){
			if(L[n2] <= nn){
				count += Math.Abs(nn);
				break;
			}
			count += Math.Abs(L[n2]-nn);
			nn = L[n2];
			//if(n1 == n2){
			//	count += Math.Abs(nn);
			//	break;
			//}
			n2 -= 1;
			if(nn <= R[n1]){
				count += Math.Abs(nn);
				break;
			}
			count += Math.Abs(R[n1]-nn);
			nn = R[n1];
			//if(n1 == n2){
			//	count += Math.Abs(nn);
			//	break;
			//}
			n1 += 1;
		}
		n1 = 0;
		n2 = N-1;
		nn = 0;
		while(true){
			if(nn <= R[n1]){
				count2 += Math.Abs(nn);
				break;
			}
			count2 += Math.Abs(R[n1]-nn);
			nn = R[n1];
			//if(n1 == n2){
			//	count2 += Math.Abs(nn);
			//	break;
			//}
			n1 += 1;
			if(L[n2] <= nn){
				count2 += Math.Abs(nn);
				break;
			}
			count2 += Math.Abs(L[n2]-nn);
			nn = L[n2];
			//if(n1 == n2){
			//	count2 += Math.Abs(nn);
			//	break;
			//}
			n2 -= 1;
		}
		//Console.WriteLine(count +" "+count2);
		count = Math.Max(count,count2);
		Console.WriteLine(count);
	}
}