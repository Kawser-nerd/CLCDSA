import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int[] f = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 2; i <= Math.sqrt(n); i++) {
			for (int j = i + i; j <= n; j += i) {
				f[j] = 0;
			}
		}
		if (f[n] != 0)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}