import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception {
		Scanner scan=new Scanner(System.in);
		long N=scan.nextLong();
		long a=(long) Math.sqrt(N);
		int ans=100000000;
		for(int i=1;i<a+1;i++) {
			long b=1000000000;
			long c=1000000000;
			if(N%i==0) {
				b=N/i;
				c=i;
			}
			
			int lb=String.valueOf(b).length();
			int lc=String.valueOf(c).length();
			if(Math.max(lb,lc)<ans){
				ans=Math.max(lb,lc);
			}
		}
		System.out.println(ans);
	}
}