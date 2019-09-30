import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		sc.close();
		if (N == M) System.out.println(N - 1);
		else System.out.println(N);
	}
}