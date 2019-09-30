import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		long[] l = new long[N+1];


		Arrays.fill(l, 0);

		l[0] = 2;

		l[1] = 1;

		for(int i=2;i<N+1;i++) {


			long l_i = l[i-1] + l[i-2];

			l[i] = l_i;
		}

		System.out.println(l[N]);
	}

}