import java.util.*;
class Main {
	public static int mod = 1000000007;
	public static int power(int a, int b) {
		long ret = 1;
		for(int i = 30; i >= 0; i--) {
			ret = (long)(1) * ret * ret % mod;
			if((b & (1 << i)) != 0) ret = (long)(1) * ret * a % mod;
		}
		return (int)(ret);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), A = sc.nextInt(), B = sc.nextInt();
		long a[] = new long[N]; int c[] = new int[N];
		for(int i = 0; i < N; i++) a[i] = sc.nextLong();
		if(A == 1) B = 0;
		while(B != 0) {
			int pos = 0;
			for(int j = 1; j < N; j++) {
				if(a[pos] > a[j]) pos = j;
			}
			a[pos] *= A; c[pos]++; B--;
			boolean flag = false;
			for(int j = 0; j < N; j++) {
				if(c[j] == 0) {
					flag = true; break;
				}
			}
			if(!flag) break;
		}
		Arrays.sort(a);
		int p = power(A, B / N);
		for(int i = B % N; i < N; i++) System.out.println(a[i] % mod * p % mod);
		for(int i = 0; i < B % N; i++) System.out.println(a[i] % mod * p % mod * A % mod);
	}
}