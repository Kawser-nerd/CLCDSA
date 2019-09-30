import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int K = sc.nextInt();

		int count = 0;

		int a = 1;


		while(count<N) {

			a = Math.min(a*2, a+K);

			count++;
		}

		System.out.println(a);
	}
}