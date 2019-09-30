import java.util.Scanner;

public class Main {
	static int ans = 0;
	static int N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		dfs(0);
		System.out.println(ans);
	}
	static void dfs(long x) {
		if (x > N) {
			return;
		}
		String s = String.valueOf(x);
		if (s.contains("7")
			&& s.contains("5")
				&& s.contains("3")) {
			ans++;
		}
	dfs(x*10 + 7);
	dfs(x*10 + 5);
	dfs(x*10 + 3);
	}
}