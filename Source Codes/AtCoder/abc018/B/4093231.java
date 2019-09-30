import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder(sc.next());
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int left = sc.nextInt();
			int right = sc.nextInt();
			StringBuilder part = new StringBuilder(sb.subSequence(left - 1, right));
			part.reverse();
			for (int j = 0; j < part.length(); j++) {
				sb.setCharAt(left - 1 + j, part.charAt(j));
			}
		}
		System.out.println(sb);
	}
}