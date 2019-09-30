import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		if (n == 0) {
			System.out.println(0);
			return;
		}

		int rem = 0;
		String ans = "";
		while (n != 0) {
			rem = n % -2;
			n /= -2;
			if (rem == -1) {
				n++;
				rem = 1;
			}
			ans = rem + ans;
		}

		System.out.println(ans);
	}
}