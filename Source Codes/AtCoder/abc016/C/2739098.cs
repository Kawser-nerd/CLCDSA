using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[,] arr=new int[s[0]+1,s[0]+1];
		
		for (int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			arr[q[0],q[0]]=1;
			arr[q[1],q[1]]=1;
			arr[q[0],q[1]]=2;
			arr[q[1],q[0]]=2;
		}
		for(int i=1;i<=s[0];i++){
			int a=0;
			for(int j=1;j<=s[0];j++){
				if(arr[i,j]==2){
					for(int k=1;k<=s[0];k++){
						if(i!=k&&arr[j,k]==2&&arr[i,k]==0){
							a++;
							arr[i,k]=3;
						}
					}
				}
			}
			Console.WriteLine(a);
		}
	}
}