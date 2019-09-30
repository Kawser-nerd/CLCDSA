import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		double l=sc.nextDouble();
		double x=sc.nextDouble();
		double y=sc.nextDouble();
		double s=sc.nextDouble();
		double d=sc.nextDouble();
		
		double ans=0;
		if(s>d) {
			if(y>x)ans=Math.min((l-s+d)/(x+y), (s-d)/(y-x));
			else ans=(l-s+d)/(x+y);
		}else {
			if(y>x)ans=Math.min((d-s)/(x+y), (s+l-d)/(y-x));
			else ans=(d-s)/(x+y);
		}
		System.out.println(ans);
	}
}