import java.math.*;
import java.util.*;

class Main{
	static Scanner s=new Scanner(System.in);
	public static void main(String[] $){
		int n=s.nextInt(),a=s.nextInt(),b=s.nextInt();
		long[] v=new long[n];
		Arrays.setAll(v,i->s.nextLong());
		Arrays.sort(v);
		long sum=0;
		int use=0,count=0;
		for(int i=n-a;i<n;++i){
			if(v[n-a]==v[i]){
				++use;
				++count;
			}
			sum+=v[i];
		}
		System.out.println(BigDecimal.valueOf(sum*1.0/a).toPlainString());
		for(int i=0;i<n-a;++i)
			if(v[n-a]==v[i])
				++count;
		
		System.err.println(count+" "+use);
		if(v[n-a]==v[n-1]){
			long r=0;
			for(int i=0,e=Math.min(b-a,count-use);i<=e;++i)
				r+=comb(count,use+i);
			System.out.println(r);
		}else{
			System.out.println(comb(count,use));
		}
	}
	static long comb(int count,int use){
		long r=1;
		for(int i=use+1;i<=count;++i){
				r*=i;
				r/=i-use;
		}
		return r;
	}
}