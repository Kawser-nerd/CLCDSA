import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int up = 0;
		int down = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			char c = s.charAt(i);
			if (c == '(') {
				for (int j = 0; j < down; j++) {
					sb.insert(0, '(');
				}
				for (int j = 0; j < down; j++) {
					sb.append(')');
				}
				down = 0;
				sb.append(c);
				up++;
			} else {
				if (up == 0) {
					down++;
				} else {
					sb.append(c);
					up--;
				}
			}
		}
		for (int j = 0; j < down; j++) {
			sb.insert(0, '(');
		}
		for (int j = 0; j < down; j++) {
			sb.append(')');
		}
		for (int i = 0; i < up; i++) {
			sb.append(')');
		}
		System.out.println(sb);
	}
}