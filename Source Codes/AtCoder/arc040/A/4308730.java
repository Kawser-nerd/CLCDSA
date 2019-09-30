import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int rCount = 0;
		int bCount = 0;
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			for (char c : s.toCharArray()) {
				if (c == 'R') {
					rCount++;
				} else if (c == 'B') {
					bCount++;
				}
			}
		}
		if (rCount > bCount) {
			System.out.println("TAKAHASHI");
		} else if (rCount < bCount) {
			System.out.println("AOKI");
		} else {
			System.out.println("DRAW");
		}
	}
}