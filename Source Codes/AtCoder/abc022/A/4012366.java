import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int S = sc.nextInt();
		int T = sc.nextInt();
		int W = sc.nextInt();
		
		int now = W;
		int ans = S <= W && W <= T ? 1 : 0;
		for (int i = 0; i < N-1; i++) {
			int a = sc.nextInt();
			W += a;
			if (S <= W && W <= T) {
				ans++;
			}
		}
		
		System.out.println(ans);
	}
}