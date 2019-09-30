using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int M = int.Parse(str[1]);
		int[,]A = new int[M,2];
		int[]C = new int[N];
		for(var i=0;i<M;i++){
			string[] str2 = Console.ReadLine().Split();
			A[i,0] = int.Parse(str2[0]);
			A[i,1] = int.Parse(str2[1]);
			C[A[i,0]-1]++;
			C[A[i,1]-1]++;
		}
		var listN = new List<int>[N];
		for(var i=0;i<N;i++){
			listN[i] = new List<int>();
		}
		for(var i=0;i<M;i++){
			listN[A[i,0]-1].Add(A[i,1]);
			listN[A[i,1]-1].Add(A[i,0]);
		}
		string ans = "Yes";
			int ct = 0;
			int ct6 = 0;
			int ct4 = 0;
			int ct4a = -1;
			int ct4b = -1;
			for(var i=0;i<N;i++){
				if(C[i]%2==1){
					ct++;
				}
				if(C[i]>=6){
					ct6++;
				}
				if(C[i]>=4){
					ct4++;
					if(ct4a==-1){
						ct4a = i;
					} else if(ct4b==-1){
						ct4b = i;
					}
				}
			}
			if(ct>=1){
				ans = "No";
			} else {
				if(ct6>=1 || ct4>=3){
					ans = "Yes";
				} else if(ct4<=1){
					ans = "No";
				} else {
					var list = new List<int>();
					int bct = 0;
					for(var i=0;i<N;i++){
						if(A[i,0] == ct4a+1){
							if(A[i,1]==ct4b+1){
								bct++;
							} else {
								list.Add(A[i,1]);
							}
                          listN[A[i,0]-1].Remove(A[i,1]);
							listN[A[i,1]-1].Remove(A[i,0]);
							A[i,0] = -1;
							A[i,1] = -1;

						}
						if(A[i,1] == ct4a+1){
							if(A[i,0]==ct4b+1){
								bct++;
							} else {
								list.Add(A[i,0]);
							}	
                          listN[A[i,0]-1].Remove(A[i,1]);
							listN[A[i,1]-1].Remove(A[i,0]);
							A[i,0] = -1;
							A[i,1] = -1;
						}
					}
					while(true){
						var list2 = new List<int>();
						for(var j=0;j<list.Count;j++){
							for(var k=0;k<listN[list[j]-1].Count;k++){
								if(listN[list[j]-1][k]==ct4b+1){
									bct++;
								} else if(listN[list[j]-1][k]!=ct4a+1){
									list2.Add(listN[list[j]-1][k]);
								}
								listN[listN[list[j]-1][k]-1].Remove(list[j]);
								listN[list[j]-1].RemoveAt(k);
								k--;
							}
						}
						list = new List<int>(list2);
						if(list.Count==0){
							if(bct!=2){
								ans = "No";
							}
							break;
						}
					}
				}
			}
		Console.WriteLine(ans);
	}
}