import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		for (int i = s.length() - 2; i > 1; i -= 2) {
			String ss = s.substring(0, i);
			if (ss.substring(0, i / 2).equals(ss.substring(i / 2))) {
				System.out.println(ss.length());
				return;
			}
		}
	}
}