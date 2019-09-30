using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		if(s[1]==1||s[1]==s[0]*2-1){Console.WriteLine("No");}
		else{
			Console.WriteLine("Yes");
			int[] a=new int[s[0]*2];
			for(int i=1;i<s[0]*2;i++){a[i]=i;}
			if(s[0]==2){}
			else if(s[1]==2){
				a[2]=s[0]-1;a[s[0]-1]=2;
				a[1]=s[0];a[s[0]]=1;
			}
			else{
				a[s[1]]=s[0];a[s[0]]=s[1];
				a[s[0]*2-1]=a[s[0]-1];
				a[s[0]-1]=s[0]*2-1;
				a[1]=a[s[0]+1];a[s[0]+1]=1;
				if(a[2]==2){a[2]=a[s[0]-2];a[s[0]-2]=2;}
			}
			for(int i=1;i<s[0]*2;i++){Console.WriteLine("{0}",a[i]);}
		}
	}
}