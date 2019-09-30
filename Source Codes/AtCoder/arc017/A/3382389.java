import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), i;
		sc.close();
		for (i = 2; i <= (int)Math.sqrt(N); ++i) {
			if (N % i == 0) break;
		}
		if (i == (int)Math.sqrt(N) + 1) System.out.println("YES");
		else System.out.println("NO");
	}
}