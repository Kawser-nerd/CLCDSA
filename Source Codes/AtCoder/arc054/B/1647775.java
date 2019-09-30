import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	double p;
	void solve() {
		Scanner sc=new Scanner(System.in);
		p=sc.nextDouble();
		double x=Math.log(p/1.5*Math.log(2.0))/Math.log(2.0)*1.5;
		x=Math.max(x, 0.0);
		double ans=x+p/Math.pow(2, x/1.5);
		System.out.println(String.format("%.8f",ans));
	}
	
	double calc(double x) {
		return x+p/Math.pow(2, x/1.5);
	}
}