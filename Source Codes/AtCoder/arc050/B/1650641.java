import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		long R=sc.nextLong();
		long B=sc.nextLong();
		long x=sc.nextLong();
		long y=sc.nextLong();
		long min=0;
		long max=Long.MAX_VALUE;
		
		for(int i=0;i<200;i++) {
			boolean judge=false;
			long mid=(min+max)/2;
			if(R-mid>=0 && B-mid>=0) {
				if((R-mid)/(x-1) + (B-mid)/(y-1) >=mid) {
					judge=true;
				}
			}
			if(judge)min=mid;
			else max=mid;
		}
		System.out.println(min);
	}
}