using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		string t=Console.ReadLine();
		int k=1<<29;
		if(t.Length<10){k=int.Parse(t);}
		int[] b=Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);
		int[] a=new int[s[0]+1];
		int[] c=new int[s[0]+1];
		int i=s[1];
		int p=1;

		while(a[i]==0&&p<k){
			a[i]=p;
			c[p]=b[i];
			i=b[i];
			p++;
		}
		if(p==k){Console.WriteLine("{0}",b[i]);}
		else{
			int l=0;
			for(int j=0;j<t.Length;j++){
				l=l*10+t[j]-'0';
				l%=(p-a[i]);
			}
			l=(l+(p-a[i])*100000-a[i]+1)%(p-a[i]);
			c[a[i]-1]=c[p-1];
			Console.WriteLine("{0}",c[l+a[i]-1]);
		}
	}
}