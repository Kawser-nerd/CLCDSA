using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		string[] str = Console.ReadLine().Split();
		int[] A = new int[N];
		for(var i=0;i<N;i++){
			A[i] = int.Parse(str[i]);
		}
		int min = 1;
		int max = N;
		while(min<max){
			int na = (min+max)/2;
			bool flag = true;
			var listS = new List<int>();
			var listN = new List<int>();
			listS.Add(1);
			listN.Add(A[0]);
			for(var i=1;i<N;i++){
				if(A[i] > A[i-1]){
					int cta = listS.Count-1;
					if(listS[cta] == 1){
						listN[cta] += A[i]-A[i-1];
					} else {
						listS.Add(1);
						listN.Add(A[i]-A[i-1]);
					}
				} else {
					int cn = listS.Count-1;
					int ca = A[i-1]-A[i];
					while(ca > 0){
						if(listN[cn] <= ca){
							ca -= listN[cn];
							listN.RemoveAt(cn);
							listS.RemoveAt(cn);
							cn--;
						} else {
							listN[cn] -= ca;
							ca = 0;
						}
					}
					if(listS[cn] == na){
						if(listS.Count == 1){
							flag = false;
							break;
						} else {
							int n1 = listN[cn];
							if(listN[cn-1] == 1){
								listS[cn-1] += 1;
								listS[cn] = 1;
								if(cn-1 > 0 && listS[cn-2] == listS[cn-1]){
									listN[cn-2] += listN[cn-1];
									listS[cn-1] = listS[cn];
									listN[cn-1] = listN[cn];
									listS.RemoveAt(cn);
									listN.RemoveAt(cn);
								}
							} else {
								listN[cn-1] -= 1;
								listS[cn] = listS[cn-1]+1;
								listN[cn] = 1;
								listS.Add(1);
								listN.Add(n1);
							}
						}
					} else {
						if(listN[cn] == 1){
							listS[cn] += 1;
							if(cn > 0 && listS[cn-1] == listS[cn]){
								listN[cn-1] += listN[cn];
								listS.RemoveAt(cn);
								listN.RemoveAt(cn);
							}
						} else {
							listN[cn] -= 1;
							listS.Add(listS[cn]+1);
							listN.Add(1);
						}
					}
				}
			}
			if(flag){
				max = na;
			} else {
				min = na+1;
			}
		}
		Console.WriteLine(min);
	}
}