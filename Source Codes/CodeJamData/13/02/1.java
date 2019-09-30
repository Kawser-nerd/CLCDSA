
/* @JUDGE_ID: 1848XX XXX Java */

import java.util.*;
import java.io.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";

    /**
     * Init class data here
     */
    private void init() {
	
    }

    /**
     * Handle the input here.
     * This method will call solve() method inside to solve the problem.
     * The return value indicates if there are more input data need to 
     * be handled. If it doesn't return 0, means this function have to be
     * called again to solve next data.
     * @return 0: end. 1: need to call input() again for next data.
     */
    private int input() {
	int ret=0;
	String com1;
	int T;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	T = Integer.parseInt(com1);

	for (int t=0; t<T; t++) {
	    int N;
	    int M;
	    int[][] lawn;
	    com1 = stdin.get1();
	    if (com1==null) {
		break;
	    }
	    N = Integer.parseInt(com1);
	    com1 = stdin.get1();
	    if (com1==null) {
		break;
	    }
	    M = Integer.parseInt(com1);
	    lawn = new int[N][M];

	    for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
		    com1 = stdin.get1();
		    if (com1==null) {
			break;
		    }
		    lawn[i][j] = Integer.parseInt(com1);
		}
	    }
	    solve(lawn);
	
	}


	ret=0;
    	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int[][] lawn) {
	int N = lawn.length;
	int M = 0;
	if (N>0) {
	    M = lawn[0].length;
	}

	int[] maxX = new int[N];
	int[] maxY = new int[M];

	Arrays.fill(maxX, Integer.MIN_VALUE);
	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
		if (lawn[i][j] > maxX[i]) {
		    maxX[i] = lawn[i][j];
		}
	    }
	}

	Arrays.fill(maxY, Integer.MIN_VALUE);
	for (int i=0; i<M; i++) {
	    for (int j=0; j<N; j++) {
		if (lawn[j][i] > maxY[i]) {
		    maxY[i] = lawn[j][i];
		}
	    }
	}

	boolean canDoFlag=true;
	solve_loop03: for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
		if (lawn[i][j] < maxX[i] && lawn[i][j] < maxY[j]) {
		    canDoFlag=false;
		    break solve_loop03;
		}
	    }
	}
	output(canDoFlag);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(boolean canDoFlag) {
	output_N++;
	System.out.format("Case #%1$d: %2$s%n", output_N, canDoFlag?"YES":"NO");
    }


    /**
     * log information for debugging.
     */
    public void logInfo(String a, Object... args) {
	if (logger != null) {
	    logger.info(String.format(a,args));
	}
    }

    public void begin() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].compareTo("unittest")==0) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].compareTo("debug")==0) {
		java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.INFO);
	    }
	}
	myMain.begin();
    }
}

class Stdin
{
    private java.io.InputStream cin;
    private java.io.BufferedReader cin_br;
    private java.io.StreamTokenizer cin_st;

    public static java.lang.String endl = System.getProperty("line.separator");

    public Stdin() {
	this(java.lang.System.in);
    }

    public Stdin(java.io.InputStream cin) {
	this.cin = cin;
 	cin_br = new java.io.BufferedReader(new java.io.InputStreamReader(this.cin));
	cin_st = new java.io.StreamTokenizer(cin_br);
	cin_st.resetSyntax();
	cin_st.wordChars('\u0021','\u007E');
	cin_st.wordChars('\u00A0','\u00FF');
	cin_st.whitespaceChars('\u0000', '\u0020');
    }

    public java.io.InputStream getInputStream() {
	return cin;
    }

    public java.io.BufferedReader getBufferedReader() {
	return cin_br;
    }

    public java.io.StreamTokenizer getStreamTokenizer() {
	return cin_st;
    }

    public java.lang.String gets() {
	java.lang.String str=null;
	try {
	    str = this.cin_br.readLine();
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }

    public java.lang.String get1() {
	java.lang.String str=null;
	try {
	    if (cin_st.nextToken() != java.io.StreamTokenizer.TT_EOF) {
		str = cin_st.sval;
	    }
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }
}
