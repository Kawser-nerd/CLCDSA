import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		if (s.charAt(s.length() - 1) == 'T') {
			System.out.print("YES");
		} else {
			System.out.print("NO");
		}
	}
}