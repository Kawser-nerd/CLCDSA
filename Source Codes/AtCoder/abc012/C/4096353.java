import java.util.*;

public class Main {
	static final int SUM = 2025;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = SUM - n;
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (i * j == ans) {
					sb.append(i).append(" x ").append(j).append("\n");
				}
			}
		}
		System.out.print(sb);
	}
}