import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		String s = sc.next();
		int[] count = new int[6];
		for (int i = 0; i < s.length(); i++) {
			count[s.charAt(i) - 'A']++;
		}
		System.out.println(count[0] + " " + count[1] + " " + count[2] + " " + count[3] + " " + count[4] + " " + count[5]);
	}
}