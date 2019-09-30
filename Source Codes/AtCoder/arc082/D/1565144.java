import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;


public class Main {
	
	public static void main(String[] args) throws IOException {
		new Main().exec();
	}
	
	public void exec() throws IOException {
		InputUtil in = new InputUtil();
		PrintWriter out = new PrintWriter(System.out);
		int X = in.nextInt();
		int K = in.nextInt();
		int[] R = in.nextInt(new int[K]);
		int Q = in.nextInt();
		int[] T = new int[Q];
		int[] A = new int[Q];
		for(int i=0; i<Q; i++) {
			T[i] = in.nextInt();
			A[i] = in.nextInt();
		}
		int q=0;
		initParam(X);
		for(;q<Q && T[q]<=R[0];q++){
			out.println(calcSand(T[q],A[q]));
			out.flush();

		}
		initNextParam(R[0]);
		for(int i=1; i<K; i++) {
			for(;q<Q && T[q]<=R[i];q++){
				out.println(calcSand(T[q]-R[i-1], A[q]));
				out.flush();
			}
			initNextParam(R[i]-R[i-1]);
		}
		for(;q<Q;q++){
			out.println(calcSand(T[q]-R[K-1], A[q]));
			out.flush();
		}
		out.flush();
	}
	int X = 0;
	int pa = 0;
	int pb = 0;
	int pc = 0;
	int pA = 0;
	int pB = 0; 
	boolean AisUpper = true;
	private void initParam(int X){
		this.X = X;
		pa=pc=pA=0;
		pb=pB=X;
	}
	private void initNextParam(int t){
		pa = calcParamA(t);
		pb = calcParamB(t);
		pc = calcParamC(t);
		AisUpper = !AisUpper;
		pA = AisUpper ? pc : (X - pc);
		pB = AisUpper ? (pc + pb - pa) : (X - pc - pb + pa);
	}
	private int calcSand(int t, int aq){
		int pat = calcParamA(t);
		int pbt = calcParamB(t);
		int pct = calcParamC(t);
		if(aq < pat){
			return pct;
		}else if (pat <= aq && aq < pbt){
			return pct + aq - pat;
		}else{
			return pct + pbt - pat;
		}
	}
	
	private int calcParamA(int t){
		return (t<pA) ? pa : (AisUpper ? Math.min(X, pa + t - pA) : Math.max(0, pa - t + pA));
	}
	private int calcParamB(int t){
		return (t<pB) ? pb : (AisUpper ? Math.min(X, pb + t - pB) : Math.max(0, pb - t + pB));
	}
	private int calcParamC(int t){
		return AisUpper ? Math.max(0, pc - t) : Math.min(X, pc + t);
	}
}

class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 100000;
	
	//Fields
	protected InputStream in;
	private byte[] buf = null;
	private int ptr = 0;
	private int max = -1;
	private DataInputStream dis = null;
	//Constructors
	public InputUtil() {this(System.in,BUFSIZ);}
	public InputUtil(InputStream in, int bufsiz) {
		initBuf(bufsiz);
		initIn(in);
	}
	
	//Methods
	//Initializer
	protected void initIn(InputStream in) {dis = new DataInputStream(this.in = in);}
	protected void initBuf(int bufsiz) {buf = new byte[bufsiz];}
	
	//buffer operation
	private void next() throws IOException {ptr++; readBuf();}
	private void readBuf() throws IOException {
		if(ptr >= max && dis.available()>0) {
			if(max>0) Arrays.fill(buf,0,max,(byte)0);
			max = dis.read(buf);
			ptr = 0;
		}
	}
	
	//Number Input Reader/Parser
	private boolean isNum(byte b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(byte b) {return b=='-'; }

	private int _nextInt() throws IOException {
		int sign = 1;
		int res = 0;
		byte c;
		while (!isNum(c=buf[ptr]) && !isMinus(c)) 
			next();
		if (isMinus(buf[ptr])) {
			sign = -1;
			next();
		}
		while (isNum(c=buf[ptr])) {
			res *= 10;
			res += c - '0' ;
			next();
		}
		next();
		return sign * res;
	}
	
	public int nextInt() throws IOException {
		readBuf();
		return _nextInt();
	}

	public int[] nextInt(int[] result) throws IOException {
		readBuf();
		for(int i=0; i<result.length; i++) {
			result[i] = _nextInt();
		}
		return result;
	}
	
	//Close 
	public void close() throws IOException {
		if(!this.in.equals(System.in)) 
			this.in.close();
	}

}