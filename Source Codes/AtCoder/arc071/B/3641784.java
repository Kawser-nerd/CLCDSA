import java.util.Scanner;
	

public class Main{

	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		long mod = 1000000007;
		int n = sc.nextInt();
		int m = sc.nextInt();
		long[] x = new long[n];
		long[] y = new long[m];
		for(int i=0;i<n;i++){
			x[i] = sc.nextLong();
		}
		for(int i=0;i<m;i++){
			y[i] = sc.nextLong();
		}
		
		long[] dx = new long[n];
		long[] dy = new long[m];
		
		for(int i=1;i<n;i++){
			dx[i] = x[i]-x[i-1];
		}
		
		for(int i=1;i<m;i++){
			dy[i] = y[i]-y[i-1]; 
		}
		
		long xsum = 0;
		long ysum = 0;
		
		for(long i=1;i<n;i++){
			xsum += (dx[(int)i]*(i*((long)(n-i))%mod))%mod;
			xsum %= mod;
		}
		
		for(long i=1;i<m;i++){
			ysum += (dy[(int)i]*(i*(m-i)%mod))%mod;
			ysum %= mod;
		}
		
		System.out.println(xsum*ysum%mod);
		
	}
	

}