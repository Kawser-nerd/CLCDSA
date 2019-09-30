using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int M = int.Parse(str[1]);
		int[]A = new int[M];
		string[] str2 = Console.ReadLine().Split();
		for(var i=0;i<M;i++){
			A[i] = int.Parse(str2[i]);
		}
		int[]E = new int[8];
		int[]EM = new int[8];
		for(var i=0;i<8;i++){
			E[i] = 99999;
		}
		int[]G = new int[10]{0,2,5,5,4,5,6,3,7,6};
		for(var i=0;i<M;i++){
			if(A[i]==1){
				E[2] = 2;
				EM[2] = A[i];
			} else if(A[i]==7){
				E[3] = 3;
				EM[3] = A[i];
			} else if(A[i]==4){
				E[4] = 4;
				EM[4] = A[i];
			} else if(A[i]==2 || A[i]==3 || A[i]==5){
				E[5] = 5;
				EM[5] = Math.Max(EM[5],A[i]);
			} else if(A[i]==6 || A[i]==9){
				E[6] = 6;
				EM[6] = Math.Max(EM[6],A[i]);
			} else if(A[i]==8){
				E[7] = 7;
				EM[7] = A[i];
			}
		}
		int[]DP = new int[N+1];
		int[,]DA = new int[N+1,8];
		for(var i=1;i<=N;i++){
			DP[i] = -1;
		}
		for(var i=1;i<=N;i++){
			for(var j=7;j>=2;j--){
				if(i-j>=0 && DP[i-j]!=-1){
					if(E[j] < 8){
						bool flag = false;
						if(DP[i]==-1 || DP[i-j]+1>DP[i]){
							flag = true;
						} else if(DP[i-j]+1==DP[i]){
							for(var k=9;k>=1;k--){
								if(E[G[k]]<8){
									int ta = 0;
									if(G[k]==j){
										ta = 1;
									}
									if(DA[i-j,G[k]]+ta>DA[i,G[k]]){
										flag = true;
										break;
									} else if(DA[i-j,G[k]]+ta<DA[i,G[k]]){
										flag = false;
										break;
									}
								}
							}
						}
						if(flag){
							for(var k=0;k<8;k++){
								DA[i,k] = DA[i-j,k];
							}
							DP[i] = DP[i-j]+1;
							DA[i,j] += 1;
						}
					}
				}
			}
		}
		//for(var i=0;i<=N;i++){
		//	for(var j=0;j<8;j++){
		//		Console.Write(DA[i,j]);
		//	}
		//	Console.WriteLine(" "+DP[i]);
		//}
		var list = new List<int>();
		int dn = N;
		for(var i=0;i<DP[N];i++){
			for(var j=9;j>=1;j--){
				if(EM[G[j]]==j && E[G[j]]<8){
					if(dn-E[G[j]]>=0 && DP[dn-E[G[j]]] == DP[dn]-1){
						list.Add(j);
						dn -= G[j];
						break;
					}
				}
			}
		}
		for(var i=0;i<list.Count;i++){
			Console.Write(list[i]);
		}
	}
}