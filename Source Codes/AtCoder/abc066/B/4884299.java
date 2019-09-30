import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		String S = sc.next();
		String ms = "";
		int len = S.length();
		int ans = 0;

		if (len % 2 == 0) {
			ms = S.substring(0, len - 2);
		} else {
			ms = S.substring(0, len - 1);
		}

		if (ms.length() == 2) {
			System.out.println("2");
			return;
		}

		for (int i = ms.length(); i > 1; i-=2) {

			if(ms.substring(0, i/2).equals(ms.substring(i/2,i))) {
				ans = i;
				break;
			}
		}

		System.out.println(ans);
	}
}