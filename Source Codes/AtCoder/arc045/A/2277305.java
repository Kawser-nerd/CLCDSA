import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String ans = "";
		for (String ss : s.split(" ")) {
			if (ss.equals("Left")) {
				ans += "< ";
			} else if (ss.equals("Right")) {
				ans += "> ";
			} else {
				ans += "A ";
			}
		}
		System.out.println(ans.trim());
	}
}