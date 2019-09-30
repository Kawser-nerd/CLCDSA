import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i+=2) {
			sb.append(s.charAt(i));
		}
		System.out.println(sb);
	}
}