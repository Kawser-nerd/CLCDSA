import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		double N = sc.nextDouble();
		double ans = 0;
		for(double i = 1; i <= N; i++) {
			ans += (10000 * i) / N;
		}
		System.out.println(ans);
	}
}