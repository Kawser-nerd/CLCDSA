import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		int sq = Integer.parseInt(a.concat(b));
		for (int i = 2; i < sq / 2; i++) {
			if (i * i == sq) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

}