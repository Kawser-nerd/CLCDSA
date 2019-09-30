using System;
class Program{
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[] t=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[] v=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int a=0,b=0,c=t[0]*2;
		for(int i=0;i<n;i++){b+=t[i];}
		b*=2;
		double[] h=new double[b+1];
		double ans=0;
		for(int i=1;i<b;i++){
			if(i>c){a++;c+=t[a]*2;}
			h[i]=Math.Min(h[i-1]+0.5,v[a]);
		}
		c-=t[n-1]*2;
		for(int i=b-1;i>=0;i--){
			if(i<c){a--;c-=t[a]*2;}
			h[i]=Math.Min(Math.Min(h[i+1]+0.5,v[a]),h[i]);
			ans+=Math.Abs(h[i]-h[i+1])*0.25+Math.Min(h[i],h[i+1])*0.5;
		}
		Console.WriteLine("{0}",ans);
	}
}