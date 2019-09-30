import java.util.*;
import java.lang.*;

public class Main {
	static StringBuilder sb;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append("a");
		}
		solve(n);
	}
	static void solve(int n) {
		if (n == 1) {
			sb.setCharAt(sb.length() - n, 'a');
			System.out.println(sb);
			sb.setCharAt(sb.length() - n, 'b');
			System.out.println(sb);
			sb.setCharAt(sb.length() - n, 'c');
			System.out.println(sb);
			sb.setCharAt(sb.length() - n, 'a');
		} else {
			sb.setCharAt(sb.length() - n, 'a');
			solve(n - 1);
			sb.setCharAt(sb.length() - n, 'b');
			solve(n - 1);
			sb.setCharAt(sb.length() - n, 'c');
			solve(n - 1);
			sb.setCharAt(sb.length() - n, 'a');
		}
	}
}