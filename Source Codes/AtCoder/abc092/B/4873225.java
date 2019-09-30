import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int D = sc.nextInt();

		int X = sc.nextInt();

		int[] A = new int[N];

		for(int i=0;i<N;i++) {

			A[i] = sc.nextInt();
		}

		int choco = 0;

		for(int i=0;i<N;i++) {

			int Ai = A[i];

			for(int j=0;j<D;j+=Ai) {

				choco++;
			}
		}

		choco += X;

		System.out.println(choco);

	}

}