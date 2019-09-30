import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String A = sc.next();

		if (A.length() > 1) {
			System.out.println(A.substring(0, A.length()-1));
			return;
		}

		String s = "abcdefghijklmnopqrsuvwxyz";
		if (A.equals("a")) {
			System.out.println(-1);
			return;
		}
		for (int i = 0; i < s.length(); i++) {
			String w = s.substring(i, i+1);
			if (w.compareTo(A)<0) {
				System.out.println(w);
				return;
			}
		}
	}
}