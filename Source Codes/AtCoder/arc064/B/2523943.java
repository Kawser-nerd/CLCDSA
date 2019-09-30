import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int p = s.charAt(0) == s.charAt(s.length()-1) ? 0 : 1;
		boolean firstLost = (s.length() + p) % 2 == 1;
		System.out.println(firstLost ? "Second" : "First");
	}

}