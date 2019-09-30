import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Zaatu[] array = new Zaatu[n];
		Zaatu[] array2 = new Zaatu[n];
		for (int i = 0; i < n; i++) {
			Zaatu z = new Zaatu();
			z.a = sc.nextInt();
			array[i] = z;
			array2[i] = z;
		}
		sc.close();

		Arrays.sort(array, new Comparator<Zaatu>() {
			public int compare(Zaatu o1, Zaatu o2) {
				return o1.a - o2.a;
			}
		});

		array[0].b = 0;
		for (int i = 1; i < n; i++) {
			if (array[i].a == array[i - 1].a) {
				array[i].b = array[i - 1].b;
			} else {
				array[i].b = array[i - 1].b + 1;
			}
		}

		for (int i = 0; i < n; i++) {
			System.out.println(array2[i].b);
		}
	}

	static class Zaatu {
		int a, b;
	}
}