import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		long k = sc.nextLong();
		sc.close();

		int idx = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				idx = i;
			} else {
				break;
			}
		}
		if (idx == -1) {
			System.out.println(s.charAt(0));
		} else if (idx >= k - 1) {
			System.out.println("1");
		} else {
			System.out.println(s.charAt(idx + 1));
		}
	}
}