
/* @JUDGE_ID: 1848XX XXX Java */

import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";
    private ArrayList<Long> longTable=null;
    private ArrayList<BigInteger> bigTable=null;
    /**
     * Init class data here
     */
    private void init() {
	longTable = genLongTable();
	bigTable = genBigTable(50);
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
	int T=0;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	T = Integer.parseInt(com1);
	for (int t=0; t<T; t++) {
	    BigInteger A;
	    BigInteger B;

	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    A = new BigInteger(com1);

	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    B = new BigInteger(com1);

	    solve(A,B);
	    
	}

    	return ret;
    }

    private boolean isPalindromes(String s) {
	boolean ret=true;
	int N = s.length();
	for (int i=0; i<N/2; i++) {
	    if (s.charAt(i) != s.charAt(N-i-1)) {
		ret=false;
		break;
	    }
	}
	return ret;
    }

    private ArrayList<BigInteger> genBigTable(int N) {
	ArrayList<BigInteger> ret = new ArrayList<BigInteger>();

	if (N>=1) {
	    ret.add(new BigInteger("1"));
	    ret.add(new BigInteger("4"));
	    ret.add(new BigInteger("9"));
	}

	for (int len=2; len<=N; len++) {
	    logInfo("len=%1$d, size=%2$d",len, ret.size());
	    char[] genS = new char[len];
	    Arrays.fill(genS, '0');
	    genS[0]='1';
	    boolean loopFlag=true;
	    while (loopFlag) {
		/* generate palindromes by mirror */
		for (int i=0; i<len/2; i++) {
		    genS[len-i-1] = genS[i];
		}
		String s = new String(genS);
		BigInteger r1 = new BigInteger(s);
		BigInteger r12 = r1.multiply(r1);
		String r12s = r12.toString();
		//logInfo("Calculating %1$s^2 = %2$s, len=%3$d",s,r12s,len);
		if (isPalindromes(r12s)) {
		    ret.add(r12);
		}
		for (int i=(len-1)/2; i>=0; i--) {
		    genS[i]++;
		    if (genS[i] >= '3') {
			genS[i] = '0';
			continue;
		    }
		    int sum;
		    sum=0;
		    for (int j=i; j>=0; j--) {
			if (len%2==1 && j==(len-1)/2) {
			    sum += ((genS[j]-'0')*(genS[j]-'0'));
			} else {
			    sum += ((genS[j]-'0')*(genS[j]-'0'))*2;
			}
		    }
		    if (sum>=10) {
			genS[i]='0';
			continue;
		    }
		    break;
		}
		if (genS[0]=='0' || genS[0]>='3') {
		    loopFlag=false;
		}
	    }
	}
	return ret;
    }

    private ArrayList<Long> genLongTable() {
	ArrayList<Long> ret = new ArrayList<Long>();
	long maxN = 10000000;
	for (long i=1; i<=maxN; i++) {
	    String si = Long.toString(i);
	    if (!isPalindromes(si)) {
		continue;
	    }
	    long ii = i*i;
	    String sii = Long.toString(ii);
	    if (isPalindromes(sii)) {
		ret.add(new Long(ii));
	    }
	}
	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(long A,long B) {
	Long ALong = new Long(A);
	Long BLong = new Long(B);
	int indexA = Collections.binarySearch(longTable, ALong);
	int indexB = Collections.binarySearch(longTable, BLong);
	if (indexA < 0) {
	    indexA = -(indexA+1);
	}
	if (indexB < 0) {
	    indexB = -(indexB+1);
	    indexB = indexB-1;
	}

	output(indexB-indexA+1);
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(BigInteger A,BigInteger B) {
	int indexA = Collections.binarySearch(bigTable, A);
	int indexB = Collections.binarySearch(bigTable, B);
	if (indexA < 0) {
	    indexA = -(indexA+1);
	}
	if (indexB < 0) {
	    indexB = -(indexB+1);
	    indexB = indexB-1;
	}

	output(indexB-indexA+1);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(int c) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n", output_N, c);
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

	longTable = genLongTable();
	bigTable = genBigTable(7);

	System.out.format("%1$d %2$d%n",longTable.size(), bigTable.size());
	for (int i=0; i<longTable.size() && i<bigTable.size(); i++) {
	    System.out.format("%1$d %2$d%n",longTable.get(i), bigTable.get(i));
	}

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
