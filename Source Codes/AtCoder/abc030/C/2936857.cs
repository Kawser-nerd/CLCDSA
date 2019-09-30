using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] a=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] b=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int t=0,i=0,j=0,ans=0;

		while(i<s[0]){
			t=a[i]+q[0];
			while(j<s[1]&&b[j]<t){j++;}
			if(j<s[1]){
				t=b[j]+q[1];
				while(i<s[0]&&a[i]<t){i++;}
				ans++;
			}
			else{break;}
		}
		
		Console.WriteLine("{0}",ans);
	}
}