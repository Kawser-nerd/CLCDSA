import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		if (a.charAt(0) - 'A' + 'a' == b.charAt(0)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}