using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		int N = int.Parse(str[0]);
		int C = int.Parse(str[1]);
		int[,]D = new int[C,C];
		int[,]CC = new int[N,N];
		for(var i=0;i<C;i++){
			string[] str2 = Console.ReadLine().Split();
			for(var j=0;j<C;j++){
				D[i,j] = int.Parse(str2[j]);
			}
		}
		for(var i=0;i<N;i++){
			string[] str3 = Console.ReadLine().Split();
			for(var j=0;j<N;j++){
				CC[i,j] = int.Parse(str3[j]);
			}
		}
		int[,] Dis = new int[3,C];
		int count = 0;
		for(var h=0;h<3;h++){
			for(var i=0;i<C;i++){
				count = 0;
				for(var j=0;j<N;j++){
					for(var k=0;k<N;k++){
						if((j+k)%3 == h){
							count += D[CC[j,k]-1,i];
						}
					}
				}
				Dis[h,i] = count;
			}
		}
		int[,] mina = new int[3,3];
		int[,] minc = new int[3,3];
		for(var i=0;i<3;i++){
			for(var j=0;j<3;j++){
				mina[i,j] = 999999999;
				minc[i,j] = 99;
			}
		}
		for(var h=0;h<3;h++){
			for(var i=0;i<C;i++){
				if(Dis[h,i] < mina[h,0]){
					mina[h,2] = mina[h,1];
					minc[h,2] = minc[h,1];
					mina[h,1] = mina[h,0];
					minc[h,1] = minc[h,0];
					mina[h,0] = Dis[h,i];
					minc[h,0] = i;
				} else if(Dis[h,i] < mina[h,1]){
					mina[h,2] = mina[h,1];
					minc[h,2] = minc[h,1];
					mina[h,1] = Dis[h,i];
					minc[h,1] = i;
				} else if(Dis[h,i] < mina[h,2]){
					mina[h,2] = Dis[h,i];
					minc[h,2] = i;
				}
			}
		}
		int min = 999999999;
		for(var h=0;h<3;h++){
			for(var i=0;i<3;i++){
				if(minc[0,h] != minc[1,i]){
					for(var j=0;j<3;j++){
						if(minc[0,h] != minc[2,j] && minc[1,i] != minc[2,j]){
							min = Math.Min(min,mina[0,h]+mina[1,i]+mina[2,j]);
						}							
					}
				}
			}
		}
		Console.WriteLine(min);
	}
}