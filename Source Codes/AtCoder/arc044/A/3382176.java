import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), sum = 0, tmp, i;
		sc.close();
		if (N == 1) System.out.println("Not Prime");
		else {
			for (i = 2; i <= (int)Math.sqrt(N); ++i) {
				if (N % i == 0) break;
			}
			if (i == (int)Math.sqrt(N) + 1) System.out.println("Prime");
			else {
				tmp = N;
				do {
					sum += tmp % 10;
					tmp /= 10;
				} while (tmp != 0);
				if (N % 10 % 2 != 0 && N % 10 != 5 && sum % 3 != 0) System.out.println("Prime");
				else System.out.println("Not Prime");
			}
		}
	}
}