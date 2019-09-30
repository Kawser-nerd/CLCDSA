import java.util.ArrayList;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		solver();
	}

	static void solver() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		ArrayList<Integer> odd = new ArrayList<Integer>();
		ArrayList<Integer> ord = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			if (a[i] % 2 != 0) {
				odd.add(a[i]);
				ord.add(i);
			}
		}
		if (m == 1) {
			show(a);
			if (a[0] != 1) {
				System.out.println(2);
				System.out.println((a[0] - 1) + " " + 1);
			} else {
				System.out.println(1);
				System.out.println(a[0]);
			}
			return;
		} else if (m == 2) {
			show(a);
			int count = 1;
			if (a[0] != 1)
				count++;
			if (a[1] != 1)
				count++;
			System.out.println(count);
			if (a[0] != 1)
				System.out.print((a[0] - 1) + " ");
			System.out.print(2);
			if (a[1] != 1)
				System.out.println(" " + (a[1] - 1));
			else
				System.out.println();
			return;
		}

		if (odd.size() > 2) {
			System.out.println("Impossible");
			return;
		} else {
			if (ord.size() > 0) {
				int d = a[0];
				a[0] = odd.get(0);
				a[ord.get(0)] = d;
				if (ord.size() == 2) {
					d = a[m - 1];
					a[m - 1] = odd.get(1);
					a[ord.get(1)] = d;
				}
			}
			show(a);
			int count = m - 1;
			if (a[0] != 1)
				count++;
			if (a[m - 1] != 1)
				count++;
			System.out.println(count);
			System.out.print((a[0] != 1 ? (a[0] - 1) + " " : ""));
			for (int i = 1; i < m - 1; i++) {
				System.out.print(a[i] + " ");
			}
			System.out.print(2);
			System.out.println((a[m - 1] != 1 ? " " + (a[m - 1] - 1) : ""));
			return;
		}
	}

	static void show(int[] a) {
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + (i == a.length - 1 ? "\n" : " "));
		}
	}
}