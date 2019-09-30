import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		sb.append(n).append("\n");
		for (int i = 0; i < n; i++) {
			sb.append(1).append("\n");
		}
		System.out.print(sb);
	}
}