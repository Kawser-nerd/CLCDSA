import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main implements Runnable {
 	
	private String problemname = "test";

	int[] dx = new int[]{-1, 0, 0, 1};
	int[] dy = new int[]{0, -1, 1, 0};

	public void run() {
		try {
    	 	in = new BufferedReader(new FileReader(problemname + ".in"));
    	 	out = new PrintWriter(problemname + ".out");
    	 	tnz = new StringTokenizer("");

    	 	int T = nextInt();
    	 	for (int q = 0; q < T; q++) {
    	 	 	int W = nextInt(), Q = nextInt();

    	 	 	String[] map = new String[W];
    	 	 	for (int i = 0; i < W; i++) {
    	 	 	 	map[i] = next();
    	 	 	}

    	 	 	String[][][] ans = new String[502][W][W];

    	 	 	for (int x = 0; x < W; x++) {
    	 	 	 	for (int y = 0; y < W; y++) {
    	 	 	 		if (map[y].charAt(x) == '+' || map[y].charAt(x) == '-') continue;
    	 	 	 	 	ans[map[y].charAt(x) - '0' + 250][x][y] = "" + map[y].charAt(x);
    	 	 	 	}
    	 	 	}

    	 	 	for (int qq = 0; qq < 10; qq++) 
    	 	 	for (int s = 0; s <= 500; s++) {
    	 	 	 	for (int x = 0; x < W; x++) {
    	 	 	 	 	for (int y = 0; y < W; y++) {
    	 	 	 	 		if (ans[s][x][y] == null) continue;

    	 	 	 	 	 	for (int q1 = 0; q1 < 4; q1++) {
    	 	 	 	 	 	 	int x2 = x + dx[q1], y2 = y + dy[q1];

    	 	 	 	 	 	 	if (x2 < 0 || x2 >= W || y2 < 0 || y2 >= W) {
    	 	 	 	 	 	 	 	continue;
    	 	 	 	 	 	 	}

    	 	 	 	 	 	 	int dif = 1;
    	 	 	 	 	 	 	if (map[y2].charAt(x2) == '-') {
    	 	 	 	 	 	 	 	dif = -1;
    	 	 	 	 	 	 	}

    	 	 	 	 	 	 	for (int q2 = 0; q2 < 4; q2++) {
        	 	 	 	 	 	 	int x3 = x2 + dx[q2], y3 = y2 + dy[q2];

        	 	 	 	 	 	 	if (x3 < 0 || x3 >= W || y3 < 0 || y3 >= W) {
        	 	 	 	 	 	 	 	continue;
        	 	 	 	 	 	 	}

        	 	 	 	 	 	 	int newd = (s + (map[y3].charAt(x3) - '0') * dif);
        	 	 	 	 	 	 	if (newd <= 500 && newd >= 0) {
        	 	 	 	 	 	 		if (ans[newd][x3][y3] != null && ans[newd][x3][y3].length() < ans[s][x][y].length() + 2) continue;

        	 	 	 	 	 	 	 	String news = ans[s][x][y] + map[y2].charAt(x2) + map[y3].charAt(x3);

        	 	 	 	 	 	 	 	if (ans[newd][x3][y3] == null || ans[newd][x3][y3].length() > news.length() || 
        	 	 	 	 	 	 	 		(ans[newd][x3][y3].length() == news.length()) && ans[newd][x3][y3].compareTo(news) > 0) {
        	 	 	 	 	 	 	 		ans[newd][x3][y3] = news;	
        	 	 	 	 	 	 	 	}
        	 	 	 	 	 	 	}
    	 	 	 	 	 	 	}
    	 	 	 	 	 	}
    	 	 	 	 	}
    	 	 	 	}
    	 	 	}

    	 	 	out.println("Case #" + (q + 1) + ": ");
    	 	 	for (int i = 0; i < Q; i++) {
    	 	 	 	int newd = nextInt();

    	 	 	 	String res = null;

    	 	 	 	for (int x3 = 0; x3 < W; x3++) {
    	 	 	 	 	for (int y3 = 0; y3 < W; y3++) {
    	 	 	 	 		String news = ans[newd + 250][x3][y3];

    	 	 	 	 		if (news == null) continue;

   		   	 	 	 	 	 if (res == null || res.length() > news.length() || 
         	 	 	 	 	 	 		(res.length() == news.length()) && res.compareTo(news) > 0) {
        	 	 	 	 	 	 	 		res = news;	
         	 	 	 	 	}	

    	 	 	 	 	}
    	 	 	 	}

    	 	 	 	out.println(res);
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
