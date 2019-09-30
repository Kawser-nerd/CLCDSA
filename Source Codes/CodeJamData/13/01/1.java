
/* @JUDGE_ID: 1848FM XXX Java */

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
	int N;
	int[][] board=null;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	N = Integer.parseInt(com1);

	for (int i=0; i<N; i++) {
	    board = new int[4][4];
	    for (int j=0; j<4; j++) {
		String s;
		s = stdin.get1();
		for (int k=0; k<s.length() && k<4; k++) {
		    char s1 = s.charAt(k);
		    if (s1=='X') {
			board[j][k]=1;
		    } else if (s1=='O') {
			board[j][k]=2;
		    } else if (s1=='T') {
			board[j][k]=3;
		    }
		}
	    }
	    solve(board);
	}

	ret=0;
    	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int[][] board) {
	boolean xWon=false;
	boolean oWon=false;
	boolean boardFull=true;
	boolean testXWonD1=true;
	boolean testXWonD2=true;
	boolean testOWonD1=true;
	boolean testOWonD2=true;
	for (int i=0; i<4; i++) {
	    if ((board[i][i] & 1) == 0) {
		testXWonD1=false;
	    }
	    if ((board[i][3-i] & 1) == 0) {
		testXWonD2=false;
	    }
	    if ((board[i][i] & 2) == 0) {
		testOWonD1=false;
	    }
	    if ((board[i][3-i] & 2) == 0) {
		testOWonD2=false;
	    }
	    boolean testXWon1=true;
	    boolean testXWon2=true;
	    boolean testOWon1=true;
	    boolean testOWon2=true;
	    for (int j=0; j<4; j++) {
		if ((board[i][j] & 1) == 0) {
		    testXWon1=false;
		}
		if ((board[j][i] & 1) == 0) {
		    testXWon2=false;
		}
		if ((board[i][j] & 2) == 0) {
		    testOWon1=false;
		}
		if ((board[j][i] & 2) == 0) {
		    testOWon2=false;
		}
		if (board[i][j]==0) {
		    boardFull=false;
		}
	    }
	    if (testXWon1 || testXWon2) {
		xWon=true;
	    }
	    if (testOWon1 || testOWon2) {
		oWon=true;
	    }
	}
	if (testXWonD1 || testXWonD2) {
	    xWon=true;
	}
	if (testOWonD1 || testOWonD2) {
	    oWon=true;
	}
	if (xWon) {
	    output("X won");
	} else if (oWon) {
	    output("O won");
	} else if (boardFull) {
	    output("Draw");
	} else {
	    output("Game has not completed");
	}
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(String s) {
	output_N++;
	System.out.format("Case #%1$d: %2$s%n", output_N, s);
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
