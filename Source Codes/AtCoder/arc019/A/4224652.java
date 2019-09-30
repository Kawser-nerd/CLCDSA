import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (c == 'O' || c == 'D') {
				sb.append(0);
			} else if (c == 'I') {
				sb.append(1);
			} else if (c == 'Z') {
				sb.append(2);
			} else if (c == 'S') {
				sb.append(5);
			} else if (c == 'B') {
				sb.append(8);
			} else {
				sb.append(c);
			}
		}
		System.out.println(sb);
	}
}