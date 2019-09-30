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

		int[] rem = new int[40];
		for (int i = 0; i < rem.length; i++) {
			rem[i] = n % -2;
			n /= -2;
			if (rem[i] == -1) {
				n++;
				rem[i] = 1;
			}
		}

		int i = rem.length - 1;
		for (; i >= 0; i--) {
			if (rem[i] == 1) {
				break;
			}
		}
		for (; i >= 0; i--) {
			System.out.print(rem[i]);
		}
		System.out.println();
	}
}