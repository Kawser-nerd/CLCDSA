import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char last = '0';
		int loser = 0;
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			if (i != 0) {
				if (s.charAt(0) != last || set.contains(s)) {
					loser = i;
					break;
				}
			}
			last = s.charAt(s.length() - 1);
			set.add(s);
		}
		if (loser == 0) {
			System.out.println("DRAW");
		} else if (loser % 2 == 0) {
			System.out.println("LOSE");
		} else {
			System.out.println("WIN");
		}
	}
}