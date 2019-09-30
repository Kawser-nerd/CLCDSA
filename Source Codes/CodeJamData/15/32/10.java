import java.util.*;

public class b {

	public static double[][] memo;
	public static int typeLen;
	public static int msgLen;
	public static int keyLen;
	public static String keys;
	public static String msg;
	public static int resetK;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			keyLen = stdin.nextInt();
			msgLen = stdin.nextInt();
			typeLen = stdin.nextInt();
			keys = stdin.next();
			msg = stdin.next();

			resetK = 0;
			for (int i=1; i<msg.length(); i++) {
				if (msg.substring(i).equals(msg.substring(0, msgLen-i))) {
					resetK = msgLen-i;
					break;
				}
			}

			memo = new double[typeLen+1][msgLen+1];
			for(int i=0; i<memo.length; i++)
				Arrays.fill(memo[i], -1.0);

			int max = getMax();
			double res = 0;
			if (max > 0)
				res = solve(0, 0);

			System.out.printf("Case #%d: %.7f\n", loop, max-res);
		}
	}

	public static int getMax() {

		// Check if a letter is missing, if so, return 0.
		for (int i=0; i<msgLen; i++)
			if (!keys.contains(""+msg.charAt(i)))
				return 0;

		char[] res = new char[typeLen];
		for (int i=0; i<msgLen; i++)
			res[i] = msg.charAt(i);

		// Greedily fill in chars.
		for (int i=msgLen; i<typeLen; i++) {

			// Look for longest match.
			char nextLet = '?';
			for (int start=i-msgLen+1; start<i; start++) {
				if (match(res, start, i-1)) {
					nextLet = msg.charAt(i-start);
					break;
				}
			}
			if (nextLet == '?') nextLet = msg.charAt(0);
			res[i] = nextLet;
		}

		String best = new String(res);

		int cnt = 0;
		for (int i=0; i<=best.length()-msg.length(); i++)
			if (best.substring(i, i+msg.length()).equals(msg))
				cnt++;
		return cnt;
	}

	public static double solve(int index, int k) {

		if (index == typeLen) {
			if (k == msgLen) return 1;
			return 0;
		}

		if (memo[index][k] > -.5) return memo[index][k];

		double res = 0;
		int savek = k;
		if (k == msgLen) {
			res = 1;
			k = resetK;
		}

		for (int i=0; i<keyLen; i++) {
			int next = getState(k, keys.charAt(i));
			res += (1.0/keyLen*solve(index+1,next));
		}

		memo[index][savek] = res;
		return res;
	}

	public static int getState(int k, char c) {

		String newS = msg.substring(0, k);
		newS = newS + c;
		char[] str = newS.toCharArray();

		for (int start=0; start<str.length; start++)
			if (match(str, start, str.length-1))
				return str.length-start;

		return 0;
	}

	public static boolean match(char[] arr, int low, int high) {

		for (int i=low,j=0; i<=high; i++,j++)
			if (arr[i] != msg.charAt(j))
				return false;
		return true;
	}
}