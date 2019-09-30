using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[] a=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
		int n=-1;
		string[] ans=new string[s[0]];
		ans[0]="Possible";
		for(int i=1;i<s[0];i++){
			if(a[i-1]+a[i]>=s[1]){n=i;break;}
		}
		if(n==-1){Console.WriteLine("Impossible");}
		else{
			for(int i=1,j=1;i<s[0];i++){
				if(n==i){j=s[0]-2;}
				else if(n>i){
					ans[j]=i.ToString();
					j++;
				}
				else{
					ans[j]=i.ToString();
					j--;
				}
			}
			ans[s[0]-1]=n.ToString();
			Console.WriteLine(String.Join("\n",ans));
		}
	}
}