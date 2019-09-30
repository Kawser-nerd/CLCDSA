import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String N = reader.next();
		int ans = 0;
		for (int i = 0; i < N.length(); i++) {
			char ch = N.charAt(i);
			if (ch == '+' ) {
				ans++;
			} else {
				ans--;
			}
		}


		System.out.println(ans);
		reader.close();
	}
}