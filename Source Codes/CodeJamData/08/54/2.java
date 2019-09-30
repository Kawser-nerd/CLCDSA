import java.io.*;
import java.util.*;
import java.math.*;

public class ProblemD {
	// 1*2*...*i mod 10007, 1 <= i < 10007
	int[] a = new int[11000];
	int[] rev = new int[11000];
	
	// a^b
	int pow(int a, int b) {
		if (b==0) return 1;
		int res = pow(a, b/2);
		res = (res * res)%10007;
		if (b%2==1)
			res = (res * a)%10007;
		return res;
	}
	
	// N! = 10007^p * Y
	// returns Y % 10007
	int factMod(int N) {
		if (N==0) return 1;
		int res = factMod(N/10007);
		int comp = N/10007;
		int last = N%10007;
		res = (res * pow(a[10006], comp)) % 10007;
		res = (res * a[last]) % 10007;
		return res;
	}
	
	// N! = 10007^p
	// returns p
	int factPw(int N) {
		return N / 10007 + N / (10007 * 10007);
	}
	
	// C(N, M) mod 10007
	int binom(int N, int M) {
		int pw = factPw(N) - factPw(M) - factPw(N-M);
		if (pw > 0) return 0;
		int res = factMod(N);
		res = (res * rev[factMod(M)]) % 10007;
		res = (res * rev[factMod(N-M)]) % 10007;
		return res;
	}
	
	int waysToGo(int r1, int c1, int r2, int c2) {
		if (r1==r2 && c1==c2) return 1;
		if (r1>=r2 || c1>=c2) return 0;
		int dst = r2 - r1 + c2 - c1;
		if (dst%3 != 0) return 0;
		int mv = dst/3;
		int dr = r2 - r1 - mv;
		int dc = c2 - c1 - mv;
		if (dr < 0 || dc < 0) return 0;
		return binom(dr+dc, dr);
	}
	
	int bitCnt(int x) {
		return (x==0?0:bitCnt(x&(x-1))+1);
	}
	
	void doMain() throws Exception {
		a[0] = 1;
		for (int i=1; i<10007; i++)
			a[i] = (a[i-1]*i)%10007;
		for (int i=1; i<10007; i++)
			for (int j=1; j<10007; j++)
				if ((i*j)%10007==1)
					rev[i]=j;
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			int H = sc.nextInt(), W = sc.nextInt(), R = sc.nextInt();
			int[] r = new int[R], c = new int[R];
			for (int i=0; i < R; i++) {
				r[i] = sc.nextInt();
				c[i] = sc.nextInt();
			}
			for (int i=0; i+1<R; i++)
				for (int j=0; j+1<R; j++)
					if (r[j] > r[j+1]) {
						int tmp=r[j]; r[j]=r[j+1]; r[j+1]=tmp;
						tmp=c[j]; c[j]=c[j+1]; c[j+1]=tmp;
					}
			int res = 0;
			for (int mask=0; mask<(1<<R); mask++) {
				int L = bitCnt(mask);
				int[] rr = new int[L+2];
				int[] cc = new int[L+2];
				rr[0]=1; cc[0]=1;
				rr[L+1]=H; cc[L+1]=W;
				int pos=1;
				for (int i=0; i < R; i++)
					if ((mask & (1<<i)) != 0) {
						rr[pos] = r[i];
						cc[pos++] = c[i];
					}
				int add = 1;
				for (int i=0; i+1<rr.length; i++)
					add = (add * waysToGo(rr[i], cc[i], rr[i+1], cc[i+1])) % 10007;
				if (L % 2 == 0)
					res += add; else res -= add;
				res %= 10007;
				if (res<0) res+=10007;
			}
			pw.println(res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemD()).doMain();
	}
}