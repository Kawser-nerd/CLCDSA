import java.util.Arrays;
import java.util.Scanner;
 
public class Main{
	
	static final Scanner s=new Scanner(System.in);
	
	static int n;
	public static void main(String[] __){
		
		n=s.nextInt();
		long a[]=new long[n];
		for(int i=0;i<n;i++) a[i]=s.nextInt();
		if(a[0]!=0) {
			long r1=solve(Arrays.copyOf(a,a.length));
			long r2=Math.abs(a[0])+1;
			a[0]=-a[0]/Math.abs(a[0]);
			r2+=solve(Arrays.copyOf(a,a.length));
			//System.out.println(r1);
			//System.out.println(r2);
			System.out.println(Math.min(r1,r2));
		}else {
			a[0]=1;
			long r1=1+solve(Arrays.copyOf(a,a.length));
			a[0]=-1;
			long r2=1+solve(Arrays.copyOf(a,a.length));
			//System.out.println(r1);
			//System.out.println(r2);
			System.out.println(Math.min(r1,r2));
		}
	}
	private static final long solve(long[]a) {
		long sum[]=new long[n];
		sum[0]=a[0];
		long res=0;
		for(int i=1;i<n;i++) {
			sum[i]=a[i]+sum[i-1];
			if(sum[i-1]>0) {
				long t=-sum[i-1]-1;
				if(a[i]>t){
					res+=a[i]-t;
					a[i]=t;
				}
			}else {
				long t=-sum[i-1]+1;
				if(a[i]<t){
					res+=t-a[i];
					a[i]=t;
				}
			}
			sum[i]=a[i]+sum[i-1];
		}
		
		//System.out.println(Arrays.toString(a));
		return res;
	}
}