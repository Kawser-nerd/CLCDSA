import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		char[] s = sc.next().toCharArray();
		
		int count = 1;
		char now = s[0];
		String ans = "";
		for (int i = 1; i < s.length; i++) {
			if (now == s[i]) {
				count++;
			} else {
				ans += now + "" + count;
				now = s[i];
				count = 1;
			}
		}
		
		ans += now + "" + count;
		
		System.out.println(ans);
	}
}