import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		String t = sc.next();
		for (int i = 0; i < n; i++) {
			boolean flag = true;
			for (int j = 0; i + j < n; j++) {
				if (s.charAt(i + j) != t.charAt(j)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				System.out.println(n + i);
				return;
			}
		}
		System.out.println(n * 2);
	}
}