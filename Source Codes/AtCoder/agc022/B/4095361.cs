using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		int[]A = new int[N];
		if(N==3){
			A[0]=2;
			A[1]=5;
			A[2]=63;
		} else if(N==4){
			A[0]=2;
			A[1]=5;
			A[2]=20;
			A[3]=63;
		} else {
			for(var i=0;i<(N-1)/8;i++){
				A[i*8] = (i+1)*12+2;
				A[i*8+1] = (i+1)*12+3;
				A[i*8+2] = (i+1)*12+4;
				A[i*8+3] = (i+1)*12+6;
				A[i*8+4] = (i+1)*12+8;
				A[i*8+5] = (i+1)*12+9;
				A[i*8+6] = (i+1)*12+10;
				A[i*8+7] = (i+1)*12+12;
			}
			if(N%8==1){
				A[N/8*8] = 12;
			} else if(N%8==2){
				A[N/8*8] = 12;
				A[N/8*8+1] = 6;
			} else if(N%8==3){
				A[N/8*8] = 12;
				A[N/8*8+1] = 8;
				A[N/8*8+2] = 4;
			} else if(N%8==4){
				A[N/8*8] = 12;
				A[N/8*8+1] = 9;
				A[N/8*8+2] = 6;
				A[N/8*8+3] = 3;
			} else if(N%8==5){
				A[N/8*8] = 12;
				A[N/8*8+1] = 10;
				A[N/8*8+2] = 9;
				A[N/8*8+3] = 3;
				A[N/8*8+4] = 2;
			} else if(N%8==6){
				A[N/8*8] = 12;
				A[N/8*8+1] = 10;
				A[N/8*8+2] = 9;
				A[N/8*8+3] = 6;
				A[N/8*8+4] = 3;
				A[N/8*8+5] = 2;
			} else if(N%8==7){
				A[N/8*8] = 12;
				A[N/8*8+1] = 10;
				A[N/8*8+2] = 9;
				A[N/8*8+3] = 8;
				A[N/8*8+4] = 4;
				A[N/8*8+5] = 3;
				A[N/8*8+6] = 2;
			} else if(N%8==0){
				A[N/8*8-8] = 12;
				A[N/8*8-7] = 10;
				A[N/8*8-6] = 9;
				A[N/8*8-5] = 8;
				A[N/8*8-4] = 6;
				A[N/8*8-3] = 4;
				A[N/8*8-2] = 3;
				A[N/8*8-1] = 2;
			}
		}
		Console.Write(A[0]);
		for(var i=1;i<N;i++){
			Console.Write(" "+A[i]);
		}
	}
}