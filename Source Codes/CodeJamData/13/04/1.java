
/* @JUDGE_ID: 1848XX XXX Java */

import java.util.*;
import java.io.*;

class Chest {
    public int num=0;
    public int keyType=0;
    public int[] keys=null;
    public int[] keysNum = null;

    public Chest() {
    }

    public void addKeys(int[] keys) {
	if (keys != null) {
	    keysNum = new int[Main.MAX_KEY_TYPE];
	    for (int i=0; i<keys.length; i++) {
		keysNum[keys[i]]++;
	    }
	}
    }

}

class SolvedException extends Exception {
    public int[] opened=null;
    public SolvedException() {
    }
}

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";
    public static int MAX_KEY_TYPE=201;

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

	input_loop1: for (int t=0; t<T; t++) {
	    int K;
	    int N;

	    com1 = stdin.get1();
	    if (com1==null) {
		break input_loop1;
	    }
	    K = Integer.parseInt(com1);

	    com1 = stdin.get1();
	    if (com1==null) {
		break input_loop1;
	    }
	    N = Integer.parseInt(com1);

	    int[] keys = new int[K];
	    for (int i=0; i<K; i++) {
		com1 = stdin.get1();
		if (com1==null) {
		    break input_loop1;
		}
		keys[i] = Integer.parseInt(com1);
	    }

	    ArrayList<Chest> chests = new ArrayList<Chest>();
	    for (int i=0; i<N; i++) {
		Chest chest = new Chest();
		chest.num = i+1;

		com1 = stdin.get1();
		if (com1==null) {
		    break input_loop1;
		}
		chest.keyType = Integer.parseInt(com1);

		int keyNumber=0;
		com1 = stdin.get1();
		if (com1==null) {
		    break input_loop1;
		}
		keyNumber = Integer.parseInt(com1);
		if (keyNumber>0) {
		    chest.keys = new int[keyNumber];
		} else {
		    chest.keys=null;
		}

		for (int j=0; chest.keys != null && j<chest.keys.length; j++) {
		    com1 = stdin.get1();
		    if (com1==null) {
			break input_loop1;
		    }
		    chest.keys[j] = Integer.parseInt(com1);
		}
		chests.add(chest);
	    }

	    solve(keys, chests);
	}

	ret=0;
    	return ret;
    }

    private boolean check2(int[] keyLeft, ArrayList<Chest> chests, int[] opened) {
	int[] keyLeft2 = Arrays.copyOf (keyLeft, keyLeft.length);
	int[] opened2 = Arrays.copyOf (opened, opened.length);
	int[] keyLeft3 = new int[keyLeft.length];

	for (int i=0; i<chests.size(); i++) {
	    if (opened2[i] !=0) {
		continue;
	    }
	    Chest chest = chests.get(i);
	    keyLeft3[chest.keyType]++;
	    opened2[i] = 1;
	    for (int j=0; chest.keys != null && j<chest.keys.length; j++) {
		keyLeft2[chest.keys[j]]++;
	    }
	}
	for (int i=0; i<keyLeft.length; i++) {
	    if (keyLeft2[i] < keyLeft3[i]) {
		return false;
	    }
	}
	return true;
    }

    private boolean check1(int[] keyLeft, ArrayList<Chest> chests, int[] opened) {
	boolean loopFlag=true;
	int[] keyLeft2 = Arrays.copyOf (keyLeft, keyLeft.length);
	int[] opened2 = Arrays.copyOf (opened, opened.length);

	while (loopFlag) {
	    loopFlag=false;
	    for (int i=0; i<chests.size(); i++) {
		if (opened2[i] !=0) {
		    continue;
		}
		Chest chest = chests.get(i);
		if (keyLeft2[chest.keyType]>0) {
		    opened2[i] = 1;
		    for (int j=0; chest.keys != null && j<chest.keys.length; j++) {
			if (keyLeft2[chest.keys[j]]==0) {
			    loopFlag=true;
			}
			keyLeft2[chest.keys[j]]++;
		    }
		}
	    }
	}
	for (int i=0; i<opened2.length; i++) {
	    if (opened2[i] == 0) {
		return false;
	    }
	}
	return true;
    }

    /**
     * recursive to solve the problem
     */
    private int solveR(int N, int K, int[] keyLeft, ArrayList<Chest> chests, int[] opened) throws SolvedException {
	if (N==0) {
	    SolvedException e = new SolvedException();
	    e.opened = opened;
	    throw (e);
	}
	if (K==0) {
	    return 0;
	}
	logInfo("N=%1$d, K=%2$d", N, K);
	if (this.logger != null) {
	    int result_N=0;
	    int[] result = new int[opened.length];
	    for (int i=0; i<opened.length; i++) {
		if (opened[i]==0) {
		    continue;
		}
		result[opened.length-opened[i]]=i+1;
		result_N++;
	    }
	    for (int i=0; i<result.length && i<result_N; i++) {
		System.out.format(" %1$d", result[i]);
	    }
	    System.out.println();
	}
	for (int i=0; i<chests.size(); i++) {
	    if (opened[i] != 0) {
		continue;
	    }
	    Chest chest = chests.get(i);
	    if (keyLeft[chest.keyType]>0) {
		keyLeft[chest.keyType]--;
		K--;
		opened[i]=N;
		for (int j=0; chest.keys != null && j<chest.keys.length; j++) {
		    keyLeft[chest.keys[j]]++;
		    K++;
		}
		boolean result1, result2;
		result2 = check2(keyLeft, chests, opened);
		if (result2) {
		    result1 = check1(keyLeft, chests, opened);
		    if (result1) {
			solveR(N-1, K, keyLeft, chests, opened);
		    }
		}

		for (int j=0; chest.keys != null && j<chest.keys.length; j++) {
		    keyLeft[chest.keys[j]]--;
		    K--;
		}
		keyLeft[chest.keyType]++;
		K++;
		opened[i]=0;
	    }
	}
	return 0;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int[] keys, ArrayList<Chest> chests) {
	int[] keyLeft = new int[Main.MAX_KEY_TYPE];
	Arrays.fill(keyLeft,0);
	for (int i=0; i<keys.length; i++) {
	    keyLeft[keys[i]]++;
	}
	SolvedException solvedException=null;
	try {
	    int[] opened = new int[chests.size()];
	    solveR(chests.size(), keys.length, keyLeft, chests, opened); 
	} catch (SolvedException e) {
	    solvedException = e;
	}
	if (solvedException == null) {
	    output(null);
	} else {
	    output(solvedException.opened);
	}

    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(int[] opened) {
	output_N++;
	
	System.out.format("Case #%1$d:", output_N);
	if (opened == null) {
	    System.out.format(" IMPOSSIBLE%n",output_N);
	    return;
	}

	int[] result = new int[opened.length];
	for (int i=0; i<opened.length; i++) {
	    result[opened.length-opened[i]]=i+1;
	}
	for (int i=0; i<result.length; i++) {
	    System.out.format(" %1$d", result[i]);
	}
	System.out.println();
	
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
