using System;
using System.Collections.Generic;
class Program{
	static int[][] s=new int[5][];
	static int[] arr=new int[9];
	static int[] tn=new int[9];
	static int ans=0;
	static int[] b=new int[2];
	static void Main(){
		for(int i=0;i<5;i++){
			s[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		}
		for(int i=0;i<9;i++){arr[i]=2;}
		ans=s[0][0]+s[0][1]+s[0][2]+s[1][0]+s[1][1]+s[1][2]+s[2][0]+s[2][1]+s[3][0]+s[3][1]+s[4][0]+s[4][1];

		for(int i=0;i<9;i++){
			if(arr[i]==2){
				arr[i]=0;
				fu(1);
				tn[0]=Math.Max(tn[0],tn[1]);
				arr[i]=2;
			}
		}

		Console.WriteLine(tn[0]);
		Console.WriteLine(ans-tn[0]);
	}
	static void fu(int a){
		tn[a]=(a&1)*10000;
		for(int i=0;i<9;i++){
			if(arr[i]==2){
				arr[i]=a&1;
				if(a==8){
					b[0]=0;
					b[arr[0]^arr[3]]+=s[0][0];b[arr[1]^arr[4]]+=s[0][1];b[arr[2]^arr[5]]+=s[0][2];
					b[arr[3]^arr[6]]+=s[1][0];b[arr[4]^arr[7]]+=s[1][1];b[arr[5]^arr[8]]+=s[1][2];
					b[arr[0]^arr[1]]+=s[2][0];b[arr[1]^arr[2]]+=s[2][1];
					b[arr[3]^arr[4]]+=s[3][0];b[arr[4]^arr[5]]+=s[3][1];
					b[arr[6]^arr[7]]+=s[4][0];b[arr[7]^arr[8]]+=s[4][1];
					tn[8]=b[0];
				}
				else{
					fu(a+1);
					if((a&1)==0){
						tn[a]=Math.Max(tn[a],tn[a+1]);
						if(tn[a]>tn[a-1]){arr[i]=2;break;}
					}
					else{
						tn[a]=Math.Min(tn[a],tn[a+1]);
						if(tn[a]<tn[a-1]){arr[i]=2;break;}
					}
				}
				arr[i]=2;
			}
		}
	}
}