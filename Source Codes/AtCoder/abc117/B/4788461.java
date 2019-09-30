import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int[] L = new int[N];

		for(int i=0;i<N;i++) {
			L[i] = sc.nextInt();
		}

		Arrays.sort(L);

		int sum = 0;
		for(int i=0;i<L.length-1;i++) {
			sum += L[i];
		}
		if(sum > L[L.length-1]) {
			out.println("Yes");
		}else {
			out.println("No");
		}

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}