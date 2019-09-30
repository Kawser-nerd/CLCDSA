import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] s = {sc.next(), sc.next(), sc.next()};
		int p = 0;
		while (s[p].length() != 0) {
			int np = s[p].charAt(0) - 'a';
			s[p] = s[p].substring(1);
			p = np;
		}
		System.out.println((char)('A' + p));
	}
}