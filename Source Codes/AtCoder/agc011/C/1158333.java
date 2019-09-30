import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static ArrayList<Integer>[] e = null;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();

		e = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			e[i] = new ArrayList<>(8);
		}

		for (int i = 0; i < M; i++) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		sc.close();

		int[] chk = new int[N];
		int evenCnt = 0;
		long singleCnt = 0;
		ArrayList<Integer> a = new ArrayList<>();
		Arrays.fill(chk, -1);
		for (int i = 0; i < N; i++) {
			if (chk[i] == -1) {
				if (e[i].size() == 0) {
					chk[i] = 0;
					singleCnt++;
				} else {
					int c = count(chk, i, 0, false) ? 1 : 2;
					a.add(c);
					evenCnt += (c == 2) ? 1 : 0;
				}
			}
		}
		long cnt = 0;
		for (int x : a) {
			if (x == 2) {
				cnt += 2 * evenCnt + (a.size() - evenCnt);
			} else {
				cnt += a.size();
			}
		}
		cnt += ((long) N) * ((long) N) - (N - singleCnt) * (N - singleCnt);
		System.out.println(cnt);
	}

	public static boolean count(int[] chk, int pos, int parity, boolean odd) {
		if (chk[pos] != -1) {
			if (chk[pos] == parity) {
				return odd;
			} else {
				return true;
			}
		}
		chk[pos] = parity;
		for (int next : e[pos]) {
			odd |= count(chk, next, 1 - parity, odd);
		}
		return odd;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.