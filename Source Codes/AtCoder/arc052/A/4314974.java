import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int a1 = -1;
		int a2 = -1;
		for (char c : arr) {
			if (c >= '0' && c <= '9') {
				if (a1 == -1) {
					a1 = c - '0';
				} else {
					a2 = c - '0';
				}
			}
		}
		int ans;
		if (a2 == -1) {
			ans = a1;
		} else {
			ans = a1 * 10 + a2;
		}
		System.out.println(ans);
	}
}