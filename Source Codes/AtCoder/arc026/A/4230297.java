import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int ans = Math.min(n, 5) * b + Math.max(n - 5, 0) * a;
		System.out.println(ans);
	}
}