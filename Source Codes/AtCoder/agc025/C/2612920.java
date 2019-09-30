import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}

	Scanner sc = new Scanner(System.in);

	class P {
		int id;
		int l;
		int r;
	}

	void run() {

		int n = sc.nextInt();

		P[] p = new P[n];

		for (int i = 0; i < n; i++) {
			p[i] = new P();
			p[i].l = sc.nextInt();
			p[i].r = sc.nextInt();
			p[i].id = i;
		}

		P[] p2 = Arrays.copyOf(p, p.length);

		Arrays.sort(p, (pp, pp2) -> pp.l - pp2.l);
		Arrays.sort(p2, (pp, pp2) -> pp.r - pp2.r);
		long ans = 0;

		boolean used[] = new boolean[n];
		int left = 0;
		int right = n - 1;

		greedyFromLeft: {
			int current = 0;
			long sum = 0;
			int count = 0;
			while (count < n) {

				while (used[p2[left].id]) {
					left++;
				}

				used[p2[left].id] = true;

				if (current > p2[left].r) {
					sum += (current - p2[left].r);
					current = p2[left].r;
				}
				count++;
				if (count == n) {
					break;
				}

				while (used[p[right].id]) {
					right--;
				}

				used[p[right].id] = true;
				if (current < p[right].l) {
					sum += (p[right].l - current);
					current = p[right].l;
				}

				count++;

			}
			ans = Math.max(ans, sum+Math.abs(current));
		}

		Arrays.fill(used, false);
		left = 0;
		right = n - 1;

		greedyFromRight: {
			int current = 0;
			long sum = 0;
			int count = 0;
			while (count < n) {

				while (used[p[right].id]) {
					right--;
				}

				used[p[right].id] = true;
				if (current < p[right].l) {
					sum += (p[right].l - current);
					current = p[right].l;
				}

				count++;
				if (count == n) {
					break;
				}

				while (used[p2[left].id]) {
					left++;
				}

				used[p2[left].id] = true;

				if (current > p2[left].r) {
					sum += (current - p2[left].r);
					current = p2[left].r;
				}
				count++;
			}
			ans = Math.max(ans, sum+Math.abs(current));

		}
		System.out.println(ans);

	}
}