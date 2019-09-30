import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] x=read(sc);
		int[] g=read(sc);
		for(int i=1;i<n;i++){
			int[] t=read(sc);
			g=gcd(g,t);
		}
		System.out.println(count(x,g)+1);
	}
	static long count(int[] x,int[] g){
		if(x.length<g.length) return 0;
		if(x.length==g.length){
			for(int i=0;i<x.length;i++){
				if(x[i]!=g[i]){
					if(x[i]>g[i]) return 1;
					else return 0;
				}
			}
			return 1;
		}
		long mod=998244353;
		long res=0;
		long c=1;
		for(int i=0;i<=x.length-g.length;i++){
			res=res*2%mod;
			res+=x[i];
		}
		res--;
		
		int[] rem=remainder(x,g);
		int[] y=Arrays.copyOf(x,x.length);
		for(int i=rem.length-1;i>=0;i--){
			y[i+(x.length-rem.length)]^=rem[i];
		}
		return res+count(x,y);
	}
	static long modPow(long a,long b,long mod){
		long res=1;
		long c=a;
		while(b>0){
			if(b%2==1) res=res*c%mod;
			c=c*c%mod;
			b/=2;
		}
		return res;
	}
	static int[] gcd(int[] a,int[] b){
		if(a.length > b.length) return gcd(b,a);
		int[] c=Arrays.copyOf(a,a.length),d=Arrays.copyOf(b,b.length);
		while(c.length>0){
			d=remainder(d,c);
			if(d.length==0) return c;
			c=remainder(c,d);
		}
		return d;
	}
	static int[] read(Scanner sc){
		String str=sc.next();
		int n=str.length();
		int[] res=new int[n];
		for(int i=0;i<n;i++) res[i]=(str.charAt(i)=='1')?1:0;
		return res;
	}
	static int[] remainder(int[] a,int[] b){//O(n^2)
		if(a.length < b.length) return Arrays.copyOf(a,a.length);
		int[] res=new int[b.length];
		int[] c=Arrays.copyOf(a,a.length);
		int size=a.length;
		int start=0;
		while(size>=b.length){
			for(int i=0;i<b.length;i++){
				c[i+start]^=b[i];
			}
			while((start<c.length) && c[start]==0) start++;
			size=c.length-start;
		}
		return Arrays.copyOfRange(c,start,c.length);
	}
}