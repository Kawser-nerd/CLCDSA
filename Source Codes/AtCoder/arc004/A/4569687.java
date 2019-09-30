import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int x[] = new int[N];
		int y[] = new int[N];


		for (int i = 0; i < N; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}

		double max = 0;
		double dis = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				dis = Math.sqrt( Math.pow(x[i]-x[j], 2) + Math.pow(y[i]-y[j], 2));

				max = Math.max(max, dis);
			}
		}

		System.out.println(max);
	}

}