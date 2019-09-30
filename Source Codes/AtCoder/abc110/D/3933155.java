import java.util.*;
public class Main {
	static int modAns = (int)Math.pow(10, 9) + 7;
	static long fac[] = new long[1000000];
	static long finv[] = new long[1000000];
	static long inv[] = new long[1000000];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int length = sc.nextInt();
		int multi = sc.nextInt();
		long ans = 1;
		ArrayList<Integer> counts = new ArrayList<Integer>();
		for(int i = 2; i <= multi; i ++) {
			if(multi % i == 0) {
				int count = 0;
				while(multi % i == 0) {
					multi /= i;
					count ++;
				}
				counts.add(count);
			}
			if(multi == 1) { break; }
		}
		COMinit();
		for(int i = 0; i < counts.size(); i ++) {
			ans *= combi(counts.get(i) + length - 1, Math.min(counts.get(i), length - 1)) % modAns;
			ans %= modAns;
		}
		System.out.println(ans);
	}

	public static long combi(int n, int r) {
		return fac[n] * (finv[r] * finv[n - r] % modAns) % modAns;
	}

	public static void COMinit() {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < fac.length; i++){
				fac[i] = fac[i - 1] * i % modAns;
				inv[i] = modAns - inv[modAns%i] * (modAns / i) % modAns;
				finv[i] = finv[i - 1] * inv[i] % modAns;
		}
	}
}