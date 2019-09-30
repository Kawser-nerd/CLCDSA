import java.util.Scanner;

public class Main {
	static int N, M;
	static int[] value;
	static int sum;
	static int min;
	static int ruikei;

	public static void main(String[] args) {
		scanAndSet();
		min = value[0];
		ruikei += value[0];
		for(int i = 1;i< M;i++) {
			ruikei += value[i];
			min = min > ruikei ? ruikei : min;
		}

		System.out.println(sum - min);

	}

	public static void scanAndSet() {
		Scanner scan = new Scanner(System.in);
		int a,b,score;

		N = scan.nextInt();
		M = scan.nextInt();
		sum = 0;

		value = new int[M+1];
		for(int i = 0;i < M+1;i++) value[i] = 0;

		for(int i = 0;i < N;i++) {
			a = scan.nextInt();
			b = scan.nextInt();
			score = scan.nextInt();

			value[a-1] += score;
			value[b] -= score;
			sum += score;

		}

		scan.close();
	}
}