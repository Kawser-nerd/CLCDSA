import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		String t = scanner.nextLine();
		scanner.close();

		String[] toReplace = {"a","t","c","o","d","e","r"};

		boolean canWin = true;
		for (int i = 0; i < s.length(); i++) {
			if (!canWin) {
				break;
			}
			if (s.charAt(i) == t.charAt(i)) {
				canWin = true;
			} else if (s.charAt(i) == '@') {
				canWin = containToReplace(t.charAt(i));
			} else if (t.charAt(i) == '@') {
				canWin = containToReplace(s.charAt(i));
			} else {
				canWin = false;
			}
		}

		String msg = "";
		if (canWin) {
			msg = "You can win";
		} else {
			msg = "You will lose";
		}

		System.out.println(msg);
	}

	private static boolean containToReplace(char c) {
		char[] toReplace = {'a','t','c','o','d','e','r'};

		for (int i = 0; i < toReplace.length; i++) {
			if (c == toReplace[i]) {
				return true;
			}
		}

		return false;
	}
}