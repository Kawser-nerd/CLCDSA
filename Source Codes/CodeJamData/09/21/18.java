import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main implements Runnable {
 	
	private String problemname = "test";

	public void run() {
		try {
			Locale.setDefault(Locale.US);

    	 	in = new BufferedReader(new FileReader(problemname + ".in"));
    	 	out = new PrintWriter(problemname + ".out");
    	 	tnz = new StringTokenizer("");

    	 	int N = nextInt();
    	 	for (int q = 0; q < N; q++) {
    	 	 	int L = nextInt();


    	 	 	int dep = 0;

    	 	 	int cnt = 0;
    	 	 	int[] l = new int[80*L], r = new int[80*L];
    	 	 	String[] name = new String[80*L];

    	 	 	int[] st = new int[80*L];

    	 	 	double[] pr = new double[80*L];

    	 	 	while (dep > 0 || cnt == 0) {
    	 	 	 	String s = next();

    	 	 	 	//System.out.println(s + " " + dep);

    	 	 	 	if (s.charAt(0) == '(') {
    	 	 	 		if (dep != 0) {
    	 	 	 		 	if (l[st[dep - 1]] == 0) {
    	 	 	 		 	 	l[st[dep - 1]] = cnt;
    	 	 	 		 	} else {
    	 	 	 		 	 	r[st[dep - 1]] = cnt;
    	 	 	 		 	}
    	 	 	 		}
    	 	 	 	 	st[dep++] = cnt++;

    	 	 	 	 	if (s.length() == 1) {
    	 	 	 	 	 	continue;
    	 	 	 	 	}

    	 	 	 	 	s = s.substring(1);
    	 	 	 	}


    	 	 	 	int sk = s.indexOf(')');

    	 	 	 	if (sk == 0) {
    	 	 	 		for (int i = 0; i < s.length(); i++) dep--;
    	 	 	 	 	continue;
    	 	 	 	}

    	 	 	 	if (sk != -1) {
    	 	 	 	 	pr[st[dep - 1]] = Double.parseDouble(s.substring(0, s.length() - 1));
    	 	 	 	 	for (int i = sk; i < s.length(); i++) dep--;
    	 	 	 	 	continue;
    	 	 	 	}

    	 	 	 	if (s.charAt(0) >= '0' && s.charAt(0) <= '9') {
    	 	 	 	 	pr[st[dep - 1]] = Double.parseDouble(s);
    	 	 	 	 	continue;
    	 	 	 	}

    	 	 	 	name[st[dep - 1]] = s;
    	 	 	}

    	 	 	int A = nextInt();
    	 	 	out.println("Case #" + (q + 1) + ":");
    	 	 	for (int i = 0; i < A; i++) {
					String nm = next();
					int n = nextInt();


					HashSet<String> fs = new HashSet<String>();
					for (int j = 0; j < n; j++) {
					 	fs.add(next());
					}

					int where = 0;
					double ans = pr[0];

					while (name[where] != null) {
						if (fs.contains(name[where])) {
						 	where = l[where];
						} else {
						 	where = r[where];
						}
						ans *= pr[where];
					}	

					out.printf("%.7f\n", ans);
    	 	 	}
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
