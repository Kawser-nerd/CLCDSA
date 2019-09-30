import java.util.*;
import java.io.*;

public class InterestingRanges {
	public String rev(String s) {
		String res = "";
		for (int i=s.length()-1; i>=0; i--)
			res += s.charAt(i);
		return res;
	}
	
	long inv2 = 500000004;
	long MOD = 1000000007;
	
	public long empty(long len) {
		len %= MOD;
		long res = (len * (len + 1)) % MOD;
		res = (res * inv2) % MOD;
		return res;
	}
	
	public long mul(long a, long b) {
		a %= MOD;
		b %= MOD;
		return (a*b)%MOD;
	}
	
	public void doMain() throws Exception {
		List<Long> palin = new ArrayList<Long>();
		for (int i=1; i<=9; i++)
			palin.add((long)i);
		for (int i=1; i < 1000000; i++) {
			String s = "" + i;
			palin.add(Long.parseLong(s + rev(s)));
			for (char c='0'; c <= '9'; c++)
				palin.add(Long.parseLong(s + (char)c + rev(s)));
		}
		
		Collections.sort(palin);
		
		long[] pal = new long[palin.size()];
		int pos = 0;
		for (long l : palin)
			pal[pos++] = l;
		
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);
			// input
			long L = sc.nextLong();
			long R = sc.nextLong();
			
			// output
			pw.print("Case #" + caseNum + ": ");
			
			// solution
			int cnt = 0;
			for (int i=0; i < pal.length; i++)
				if (pal[i] >= L && pal[i] <= R) cnt++;
			
			if (cnt == 0) {
				pw.println(empty(R - L + 1));
				continue;
			}
			
			long[] data = new long[cnt];
			pos = 0;
			for (int i=0; i < pal.length; i++)
				if (pal[i] >= L && pal[i] <= R)
					data[pos++] = pal[i];
			
			long[] rdist = new long[cnt];
			rdist[cnt-1] = R - data[cnt-1] + 1;
			for (int i=cnt-2; i >= 0; i--)
				rdist[i] = data[i+1] - data[i];
			
			for (int i=cnt-1; i >= 0; i--)
				if (i + 2 < cnt)
					rdist[i] += rdist[i + 2];
			
			long res = 0;
			
			if (data[0] > L) {
				res = (res + empty(data[0] - L)) % MOD;
				if (cnt >= 2)
					res = (res + mul(data[0] - L, rdist[1])) % MOD;
			}
			if (data[cnt-1] < R)
				res = (res + empty(R - data[cnt-1])) % MOD;
			for (int i=0; i + 1 < cnt; i++)
				if (data[i] + 1 < data[i+1]) {
					res = (res + empty(data[i+1] - data[i] - 1));
					if (i + 2 < cnt)
						res = (res + mul(data[i+1] - data[i] - 1, rdist[i+2])) % MOD;
				}
			
			for (int i=0; i+1 < cnt; i++)
				res = (res + rdist[i+1]) % MOD;
			
			pw.println(res);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new InterestingRanges()).doMain();
	}
}