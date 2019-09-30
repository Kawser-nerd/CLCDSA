import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main implements Runnable {
 	
	private String problemname = "test";

	public void run() {
		try {
    	 	in = new BufferedReader(new FileReader(problemname + ".in"));
    	 	out = new PrintWriter(problemname + ".out");
    	 	tnz = new StringTokenizer("");

    	 	int T = nextInt();
    	 	outer: for (int q = 0; q < T; q++) {
    	 	 	String s = next();

    	 	 	int[] num = new int[10];

    	 	 	int n = s.length();

    	 	 	for (int i = 0; i < n; i++) {
    	 	 	 	num[s.charAt(i) - '0']++;
    	 	 	}

    	 	 	out.print("Case #" + (q + 1) + ": ");

    	 	 	int[] tmp = new int[10];
    	 	 	int max = 0;
    	 	 	for (int i = n - 1; i >= 0; i--) {
    	 	 	 	if (s.charAt(i) - '0' >= max) {
    	 	 	 	 	max = s.charAt(i) - '0';
    	 	 	 	 	tmp[s.charAt(i) - '0']++;
    	 	 	 	} else {
    	 	 	 	 	for (int j = s.charAt(i) - '0' + 1; j < 10; j++) {
    	 	 	 	 	 	if (tmp[j] > 0) {
    	 	 	 	 	 	 	tmp[j]--;
    	 	 	 	 	 	 	tmp[s.charAt(i) - '0']++;

    	 	 	 	 	 	 	String ans = s.substring(0, i) + ((char) (j + '0'));
    	 	 	 	 	 	 	for (int k = 0; k < 10; k++) {
    	 	 	 	 	 	 	 	while (tmp[k] > 0) {
    	 	 	 	 	 	 	 	 	ans = ans + ((char)(k + '0'));
    	 	 	 	 	 	 	 	 	tmp[k]--;
    	 	 	 	 	 	 	 	}
    	 	 	 	 	 	 	}

    	 	 	 	 	 	 	out.println(ans);
    	 	 	 	 	 	 	continue outer;
    	 	 	 	 	 	}
    	 	 	 	 	}
    	 	 	 	}
    	 	 	}

    	 	 	for (int i = 1; i < 10; i++) {
    	 	 	 	if (num[i] > 0) {
    	 	 	 	 	out.print((char)(i + '0'));
    	 	 	 	 	num[i]--;
    	 	 	 	 	num[0]++;

    	 	 	 	 	for (int j = 0; j < 10; j++) {

        	 	 	 	 	while (num[j] > 0) {
        	 	 	 	 	 	out.print((char)(j + '0'));
        	 	 	 	 	 	num[j]--;
        	 	 	 	 	}
        	 	 	 	}

    	 	 	 	}
    	 	 	}
    	 	 	out.println();
    	 	}

    	 	in.close();
    	 	out.close();
	 	}
	 	catch (Exception e) {
	 		System.err.println("Main proc exception!");
	 	 	e.printStackTrace();
	 	}
	}

	public static void main(String[] args) {
	 	new Thread(new Main()).start();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tnz;

	private void seek() {
	 	while (!tnz.hasMoreTokens()) {
	 		String s = null;
	 		try {
		 	 	s = in.readLine();
		 	}
		 	catch (Exception e) {
		 	 	e.printStackTrace();
		 	}
	 	 	if (s == null) return;
	 	 	tnz = new StringTokenizer(s);
	 	}
	}

	private String next() {
	 	seek();
	 	return tnz.nextToken();
	}

	private int nextInt() {
	 	return Integer.parseInt(next());
	}

	private long nextLong() {
	 	return Long.parseLong(next());
	}

	private BigInteger nextBigInteger() {
	 	return new BigInteger(next());
	}

	private double nextDouble() {
	 	return Double.parseDouble(next());
	}

}
