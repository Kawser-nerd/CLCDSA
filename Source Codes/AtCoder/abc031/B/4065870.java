import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt();
		int h = sc.nextInt();
		int n = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (a < l) {
				sb.append(l - a);
			} else if (a <= h) {
				sb.append(0);
			} else {
				sb.append(-1);
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}