import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int d = Integer.parseInt(sc.next());
		int e = Integer.parseInt(sc.next());
		int f = Integer.parseInt(sc.next());
		int water = 0;
		int sugar = 0;
		for (int i = 0; i <= f; i += 100 * a) {
			for (int j = 0; i + j <= f; j += 100 * b) {
				for (int k = 0; i + j + k <= f; k += c) {
					for (int l = 0; i + j + k + l <= f; l += d) {
						if ((k + l) * 100 <= e * (i + j)) {
							if ((water == 0 && sugar == 0)|| sugar * (i + j + k + l) < (k + l) * water) {
								water = i + j + k + l;
								sugar = k + l;
							}
						}
					}
				}
			}
		}
		System.out.println(water + " " + sugar);
	}
}