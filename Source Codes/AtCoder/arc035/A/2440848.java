import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.next().split("");
		for (int i = 0; i < s.length; i++) {
			if (s[i].equals(s[s.length - i - 1]) || s[i].equals("*") || s[s.length - i - 1].equals("*")) continue;
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
	}
}