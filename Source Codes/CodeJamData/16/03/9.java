import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.InputStream;
import java.util.*;

public class Big {

	public static String pad(String s, int len){
		String t = new String();
		int i;
		for(i = 0; i < len - s.length(); i++){
			t = t + "0";
		}
		t = t + s;
		return t;
	}

	public static void main(String args[]) throws IOException{
		PrintWriter out = new PrintWriter(System.out);
		Scanner sc = new Scanner(System.in);

		int nc = sc.nextInt();
		out.println("Case #1:");
		int N = sc.nextInt();
		int J = sc.nextInt();
		
		BigInteger num;

		BigInteger one = BigInteger.valueOf(1);
		BigInteger hi = BigInteger.valueOf(1L<<(N-1));
		int cnt = 0;
		for (num = BigInteger.valueOf(0); num.compareTo(hi) < 0; num = num.add(one)){
			String s = (one.toString() + pad(num.toString(2), N-2) + one.toString());
			int b;
			boolean bad = false;
			BigInteger curr[] = new BigInteger[11];
			for (b = 2; b <= 10; b++){
				curr[b] = new BigInteger(s, b);
				if (curr[b].isProbablePrime(5)) {
					bad = true;
					break;
				}
			}
			if (!bad){
				BigInteger div[] = new BigInteger[11];
				for(b = 2; b <= 10; b++){
					boolean ok = false;
					for(div[b] = BigInteger.valueOf(2); div[b].multiply(div[b]).compareTo(curr[b]) <= 0 &&
							div[b].compareTo(BigInteger.valueOf(1000000)) <= 0; 
							div[b] = div[b].add(one)){
						if (curr[b].mod(div[b]).compareTo(BigInteger.ZERO) == 0) {
							ok = true; 
							break;
						}
					}
					if (!ok) {
						bad = true;
						break;
					}
				}
				if (!bad){
					out.print(s);
					int i;
					for (i = 2; i <= 10; i++) out.print(" " + div[i].toString());
					out.println();
					out.flush();
					cnt++;
					if (cnt == J){
						out.close();
						sc.close();
						return;
					}		
				}
			}
		}

		out.close();
		sc.close();

	}
}

