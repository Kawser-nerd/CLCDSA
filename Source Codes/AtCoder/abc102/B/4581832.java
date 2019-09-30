import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int[] a = new int[N];
		int max = 0;
		int min = 1000000000;

		for (int i = 0; i < N; i++) {
			a[i] = reader.nextInt();
			if (a[i] > max) {
				max = a[i];
			}
			if (a[i] < min) {
				min = a[i];
			}
		}
		reader.close();
		System.out.print(Math.abs(max - min));
	}
}