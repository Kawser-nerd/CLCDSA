import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		long K = sc.nextLong();

		long cnt = 1;
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (c != '1') {
				if (K < cnt) {
					System.out.println(1);
				}else {
					System.out.println(c);
				}
				return;
			}
			cnt++;
		}
		System.out.println(1);
	}
}