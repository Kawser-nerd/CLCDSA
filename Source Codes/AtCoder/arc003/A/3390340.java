import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), sum = 0;
		char r[] = new char[N + 1];
		r = sc.next().toCharArray();
		sc.close();
		for (int i = 0; i < N; ++i) {
			if (r[i] == 'F') continue;
			sum += 'E' - r[i];
		}
		System.out.println((double)sum / N);
	}
}