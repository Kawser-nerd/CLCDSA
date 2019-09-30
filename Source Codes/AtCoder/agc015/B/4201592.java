import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		long ans = 0;
		for(int i = 0; i < S.length(); i++) {
			if(S.substring(i, i + 1).equals("U")) {
				ans = ans + (S.length() - 1 - i) + i * 2;
			} else {
				ans = ans + (S.length() - 1 - i) * 2 + i;
			}
		}
		System.out.println(ans);
	}
}