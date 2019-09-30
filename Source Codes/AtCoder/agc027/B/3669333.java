import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long x=sc.nextLong();
		long[] a=new long[n];
		for(int i=0;i<n;i++)a[i]=sc.nextLong();
		
		long[] psum=new long[n];
		long sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
			psum[i]=sum;
		}
		
		long res=Long.MAX_VALUE;
		label:
		for(int i=1;i<n;i++){
			long t=i*x;
			for(int j=0;j*i<n;j++){//a[n-1-i*j] to a[n-1-i*j-i+1]
				long pres=psum[n-1-i*j]-((n-1-i*j-i)<0?0:psum[n-1-i*j-i]);
				long coef=(j==0?5:2*j+3);
				if(63<=(Math.log(pres)+Math.log(coef))/Math.log(2)) continue label;
				if((Long.MAX_VALUE-t)<coef*pres)continue label;
				t+=coef*pres;
			}
			res=Math.min(res,t);
		}
		res+=n*x;
		pl(res);
	}
	static void pl(Object o){System.out.println(o);}
}