import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();

		BigInteger A = new BigInteger(a);
		BigInteger SQ = A.multiply(A);

		BigInteger A2 = A.add(BigInteger.ONE);
		BigInteger SQ2 = A2.multiply(A2);

		String sq = SQ.toString();
		String sq2 = SQ2.toString();

		int len = 0;
		boolean zflg = true;
		boolean zflg2 = true;
		String ans = "";
		while (len < sq.length()) {
			String wk = sq.substring(0, sq.length() - len);
			if (len != 0 && (sq.charAt(sq.length() - len) != '0'
					|| sq.charAt(sq.length() - len + 1) != '0')) {
				zflg = false;
			}
			if (len != 0 && (sq2.charAt(sq2.length() - len) != '0'
					|| sq2.charAt(sq2.length() - len + 1) != '0')) {
				zflg2 = false;
			}
			String wk2 = sq2.substring(0, sq2.length() - len);
			if (zflg) {
				ans = wk;
			} else if (!wk.equals(wk2)) {
				String cand = new BigInteger(wk).add(BigInteger.ONE).toString();
				if (!(zflg2 && wk2.equals(cand))) {
					ans = cand;
				}
			}
			len += 2;
		}

		System.out.println(ans);
	}
}