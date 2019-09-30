import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Seito[] array = new Seito[n];
		for (int i = 0; i < n; i++) {
			Seito seito = new Seito();
			seito.i = i + 1;
			seito.a = sc.nextInt();
			array[i] = seito;
		}
		sc.close();

		Arrays.sort(array, new Comparator<Seito>() {
			public int compare(Seito o1, Seito o2) {
				return o2.a - o1.a;
			}
		});

		for (Seito seito : array) {
			System.out.println(seito.i);
		}
	}

	static class Seito {
		int i, a;
	}
}