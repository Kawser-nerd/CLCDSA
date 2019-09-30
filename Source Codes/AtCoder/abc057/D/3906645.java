import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		Long[] v = new Long[N];
		for(int i = 0; i < N; i++) {
			v[i] = sc.nextLong();
		}
		sc.close();
		Arrays.sort(v, Comparator.reverseOrder());
		long sum = 0;
		int cnt = 1;
		long k = v[0];
		for(int i = 0; i < N; i++) {
			if(k != v[i]) {
				cnt++;
				k = v[i];
			}
		}
		for(int i = 0; i < A; i++) {
			sum += v[i];
		}
		double myu = (double) sum / A;

		int[] t = new int[cnt];
		k = v[0];
		int idx = 0;
		for(int i = 0; i < N; i++) {
			if(k == v[i]) {
				t[idx]++;
			}else {
				k = v[i];
				idx++;
				t[idx]++;
			}
		}
		long ans = 0;

		for(int i = A; i <= B; i++) {
			long s = 0;
			for(int j = 0; j < i; j++) {
				s += v[j];
			}
			if(sum * i == s * A) {
				int a = 0;
				for(int j : t) {
					a += j;
					if(a >= i) {
						ans += comb(j, a - i);
						break;
					}
				}
			}else {
				break;
			}
		}
		BigDecimal bd = new BigDecimal(myu);
		System.out.println(bd.toString());
		System.out.println(ans);
	}
	public static long comb(int n, int r) {
        if (n - r < r) r = n - r;
        if (r == 0) return 1;
        if (r == 1) return n;
        int[] num = new int[r];
        int[] den = new int[r];
        for (int k = 0; k < r; k++){
            num[k] = n - r + k + 1;
            den[k] = k + 1;
        }
        for (int p = 2; p <= r; p++) {
            int pivot = den[p - 1];
            if (pivot > 1) {
                int offset = (n - r) % p;
                for (int k = p - 1; k < r; k += p) {
                    num[k - offset] /= pivot;
                    den[k] /= pivot;
                }
            }
        }
        long result = 1;
        for (int k = 0; k < r; k++) {
            if (num[k] > 1) result *= num[k];
        }
        return result;
    }

}