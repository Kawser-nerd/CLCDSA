import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int ans = 0;
		if(N > K) {
			ans += K * X;
			ans += (N - K) * Y;
		} else {
			ans += N * X;
		}
		System.out.println(ans);
	}
}