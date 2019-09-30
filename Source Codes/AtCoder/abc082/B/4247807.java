import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		char[] s = sc.next().toCharArray();
		char[] t = sc.next().toCharArray();

		Arrays.sort(s);
		Arrays.sort(t);

		String ans = "No";

		for (int i = 0, j = t.length - 1; i < s.length || j >= 0; i++, j--) {
			if (i >= s.length && j >= 0) {
				ans = "Yes";
				break;
			}
			if (i < s.length && j < 0) {
				break;
			}
			if (s[i] < t[j]) {
				ans = "Yes";
				break;
			}
			if (s[i] > t[j]) {
				break;
			}
		}
		System.out.println(ans);
		sc.close();
	}

}