import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Magic[] arr = new Magic[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Magic(sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(arr, new Comparator<Magic>() {
		public int compare(Magic m1, Magic m2) {
			if (m1.a < m1.b && m2.a < m2.b) {
				return m1.a - m2.a;
			} else if (m1.a >= m1.b && m2.a < m2.b) {
				return 1;
			} else if (m1.a < m1.b && m2.a >= m2.b) {
				return -1;
			} else {
				return m2.b - m1.b;
			}
		}
		});
		long tmp = 0;
		long max = 0;
		for (Magic m : arr) {
			tmp += m.a;
			if (max < tmp) {
				max = tmp;
			}
			tmp -= m.b;
		}
		System.out.println(max);
	}
	
	static class Magic {
		int a;
		int b;
		public Magic (int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
}