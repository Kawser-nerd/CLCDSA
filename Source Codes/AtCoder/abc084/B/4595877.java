import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt();
		char[] s = sc.next().toCharArray();
		int c = 0;
		if (s[a] == '-') {
			c++;
		} else {
			c = 0;
		}
		for (int i = 0; i < s.length; i++) {
			if (i != a && s[i] == '-') {
				c = 0;
			}
		}
		if (c != 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		sc.close();
	}

}