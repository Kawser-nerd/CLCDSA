import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] s = {sc.nextLine(), sc.nextLine(), sc.nextLine()};

		int turn = 'a';
		while (true) {
			if (s[turn - 'a'].length() == 0) {
				break;
			}
			char c = s[turn - 'a'].charAt(0);
			s[turn - 'a'] = s[turn - 'a'].substring(1);
			turn = c;
		}
		System.out.println(turn == 'a' ? "A" : turn == 'b' ? "B" : "C");
	}
}