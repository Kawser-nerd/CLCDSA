using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		string[] arr=new string[s[0]];
		int[,] ud=new int[s[0]+1,s[1]];
		int[] q=new int[s[1]];
		int a=0;
		for (int i=0;i<s[0];i++){
			arr[i]=Console.ReadLine();
			for (int j=0;j<s[1];j++){
				if(arr[i][j].ToString()=="x"){q[j]=0;}
				else{q[j]++;}
				ud[i,j]=q[j];
			}
		}
		for (int i=s[0]-1;i>=0;i--){
			for (int j=s[1]-1;j>=0;j--){ud[i,j]=Math.Min(ud[i,j],ud[i+1,j]+1);}
		}
		int b=s[2]-1;
		bool c=true;
		for (int i=b;i<s[0]-b;i++){
			for (int j=b;j<s[1]-b;j++){
				for (int k=j-b;k<=j+b;k++){
					if(ud[i,k]<s[2]-Math.Abs(j-k)){c=false;break;}
				}
				if(c){a++;}
				c=true;
			}
		}
		Console.WriteLine(a);
	}
}