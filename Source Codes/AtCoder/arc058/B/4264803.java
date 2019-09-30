import java.util.Scanner;

public class Main {
	static final int MAX = 1000005;
    static final int MOD = 1000000007;
    static long[]fact = new long[MAX];
    static long[]factInv = new long[MAX];
    static long[]inv = new long[MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		sc.close();
		factMOD();
        invMOD();
        factInvMOD();
        long ans = 0;
        for(int i = B; i < W; i++) {
        	ans += combMOD(H - A - 1 + i, i) * combMOD(W + A - i - 2, A - 1);
        	ans %= MOD;
        }
        System.out.println(ans);
	}
	static void factMOD() {
        fact[0] = 1;
        for(int i = 1; i < MAX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
    }
    static void invMOD() {
        inv[0] = 1;
        inv[1] = 1;
        for(int i = 2; i < MAX; i++) {
            inv[i] = MOD - inv[(int)(MOD % i)] * (MOD / i) % MOD;
        }
    }
    static void factInvMOD() {
        factInv[0] = 1;
        for(int i = 1; i < MAX; i++) {
            factInv[i] = factInv[i - 1] * inv[i] % MOD;
        }
    }
    static long combMOD(int n, int k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fact[n] * ((factInv[k] * factInv[n - k]) % MOD) % MOD;
    }
}