import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Stack;

class sushi {
	public int t;
	public long d;

	public sushi(int t, long d) {
		this.t = t;
		this.d = d;
	}

	public long getD() {
		return this.d;
	}
}

public class Main {

	static Scanner sc = new Scanner(System.in);
	static Stack st = new Stack();
	static int N = sc.nextInt();
	static int K = sc.nextInt();
	static sushi[] S = new sushi[N];
	static boolean[] used = new boolean[N + 1];
	static long sum_t = 0;
	static long sum_d = 0;
	static long ans = 0;

	public static void main(String[] args) {
		for(int i = 0; i < N; i++) {
			int t = sc.nextInt();
			long d = sc.nextLong();
			sushi su = new sushi(t, d);
			S[i] = su;
		}

		Arrays.sort(S, Comparator.comparing(sushi::getD).reversed());

		for(int i = 0; i < K; i++) {
			if(used[S[i].t]) {
				st.push(S[i].d);
			} else {
				used[S[i].t] = true;
				sum_t++;
			}
			sum_d += S[i].d;
		}
		ans = sum_d + sum_t * sum_t;

		for(int i = K; i < N; i++) {
			if(st.empty())
				break;
			if(used[S[i].t])
				continue;
			used[S[i].t] = true;
			sum_t++;
			sum_d += S[i].d - (long) st.pop();
			ans = Math.max(ans, sum_d + sum_t * sum_t);
		}

		System.out.println(ans);
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.