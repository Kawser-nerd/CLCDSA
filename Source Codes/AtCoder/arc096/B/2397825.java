import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;


public class Main {
	
	public static void main(String[] args) throws IOException {
		Main m = new Main();
		//*
		m.input();
		m.solve();
		m.output();
		/*/
		m.debug();
		//*/
	}
	
	public void debug() {
	}
	
	InputUtil in = new InputUtil();
	PrintWriter out = new PrintWriter(System.out);
	
	int N = 0;
	long C = 0;
	long[] X = null;
	int[] V = null;
	long[] LXsum = null;
	long[] RXsum = null;
	long[] LVsum = null;
	long[] RVsum = null;
	
	long maxCa = 0;
	long maxCaL = 0;
	long maxCaR = 0;
	int maxCaLindex = -1;
	int maxCaRindex = -1;
	long[] maxCaRevR = null;
	long[] maxCaRevL = null;

	public void input() throws IOException {
		N = in.nextInt();
		C = in.nextLong();
		X = new long[N];
		V = new int[N];
		LXsum = new long[N];
		RXsum = new long[N];
		LVsum = new long[N];
		RVsum = new long[N];
		maxCaRevL = new long[N];
		maxCaRevR = new long[N];
		
		for(int i=0; i<N; i++) {
			X[i] = in.nextLong();
			V[i] = in.nextInt();
		}

		for(int i=0; i<N; i++) {
			LXsum[i]=X[i];
			if(i==0) {
				LVsum[i]=V[i];
			} else {
				LVsum[i]=LVsum[i-1]+V[i];
			}
		}
		for(int i=N-1; i>=0; i--) {
			RXsum[i]=C-X[i];
			if(i==N-1) {
				RVsum[i]=V[i];
			} else {
				RVsum[i]=RVsum[i+1]+V[i];
			}
		}
		
		
	}
	
	public void solve() throws IOException {
		for (int li = 0; li < N; li++ ){
			solveSubRevL(li);
		}
		for (int ri = N-1; ri > -1; ri--){
			solveSubRevR(ri);
		}
		for (int li = 0; li < N; li++ ){
			solveSubL(li);
		}
		for (int ri = N-1; ri > -1; ri--){
			solveSubR(ri);
		}
//		if (maxCaRindex>0) {
//			maxCaR += maxCaRevL[maxCaRindex-1];
//		}
//		if (maxCaLindex<N-1){
//			maxCaL += maxCaRevR[maxCaLindex+1];
//		}
		maxCa = Math.max(maxCaR, maxCaL);
	}
	
	public void solveSubL(int li) {
		long ca = LVsum[li] - LXsum[li] + ((li==N-1) ? 0 : maxCaRevR[li+1]);
//		System.out.println("li="+li+",caL="+ca);
		if (maxCaL<ca) {
			maxCaL = ca;
			maxCaLindex = li;
		}
	}
	public void solveSubR(int ri) {
		long ca = RVsum[ri] - RXsum[ri] + ((ri==0) ? 0 : maxCaRevL[ri-1]);
//		System.out.println("ri="+ri+",caR="+ca);
		if (maxCaR<ca) {
			maxCaR = ca;
			maxCaRindex = ri;
		}
	}
	public void solveSubRevL(int li) {
		long ca = LVsum[li] - LXsum[li]*2;
		maxCaRevL[li] = Math.max((li==0) ? 0 : maxCaRevL[li-1], ca);
//		System.out.println("li="+li+",caRevL="+maxCaRevL[li]);
	}
	public void solveSubRevR(int ri) {
		long ca = RVsum[ri] - RXsum[ri]*2;
		maxCaRevR[ri] = Math.max((ri==N-1) ? 0 : maxCaRevR[ri+1], ca);
//		System.out.println("ri="+ri+",caRevR="+maxCaRevR[ri] );
	}
	
	
	public void output() {
		out.println(maxCa);
		out.flush();
	}
}
class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 100000;
	boolean lineMode = false;
	
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
	
	
	//String Input Reader/Parser
	private boolean isCrLf(byte b) {return b == 0x0a || b == 0x0d; }
	
	private void skipOneCrLf() throws IOException {
		byte b = buf[ptr];
		if (isCrLf(b)) {
			ptr++;
			if (b == 0x0d) {
				readBuf();
				if (ptr < max && buf[ptr] == 0x0a) {
					ptr++;
				}
			}
		}
	}
	
	public String nextLine() throws IOException {
		StringBuilder sb = new StringBuilder();
		boolean isFirst = true;
		for(readBuf(); ptr < max ;readBuf()) {
			byte b = buf[ptr];
			if(isCrLf(b)) {
				skipOneCrLf();
				if (!isFirst || lineMode) {
					break;
				}
			}else{
				int strPtr = ptr++;
				int endPtr = -1;
				for(int i = ptr; i<max; i++) {
					if(isCrLf(buf[i])) {
						endPtr = i;
						break;
					}
				}
				if(endPtr == -1) endPtr = max;
				sb.append(new String(buf,strPtr,endPtr-strPtr,"UTF-8"));
				ptr = endPtr;
			}
			isFirst = false;
		}
		lineMode = true;
		return sb.toString();
	}
	
	public byte nextByte() throws IOException {
		lineMode=false;
		readBuf();
		if(ptr < max) {
			return buf[ptr++];
		}else{
			return -1;
		}
	}
	
	//Number Input Reader/Parser
	private boolean isNum(byte b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(byte b) {return b=='-'; }
	
	public int nextInt() throws IOException {
		lineMode=false;
		readBuf();
		return (int)_nextLong();
	}
	
	public int[] nextInt(int[] result) throws IOException {
		lineMode=false;
		readBuf();
		for(int i=0; i<result.length; i++) {
			result[i] = (int)_nextLong();
		}
		return result;
	}
	
	private long _nextLong() throws IOException {
		int sign = 1;
		long res = 0;
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
	
	public long nextLong() throws IOException {
		lineMode=false;
		readBuf();
		return _nextLong();
	}
	
	public long[] nextLong(long[] result) throws IOException {
		lineMode=false;
		readBuf();
		for(int i=0; i<result.length; i++) {
			result[i] = _nextLong();
		}
		return result;
	}
	
	//Close 
	public void close() throws IOException {
		if(!this.in.equals(System.in)) 
			this.in.close();
	}

}

class OutputUtil {
	public static final String EOF = System.lineSeparator();

	public static void outputDivSpace(PrintWriter out, int[] a) {
		OutputUtil.output(out,a,0,a.length," ");
	}
	
	public static void outputDivEOF(PrintWriter out, int[] a) {
		OutputUtil.output(out,a,0,a.length,EOF);
	}
	
	public static void output(PrintWriter out, int[] a, int off, int len, String delim) {
		out.print(a[off]);
		for(int i=off+1; i<len; i++){
			out.print(delim);
			out.print(a[i]);
		}
		out.println("");
		out.flush();
	}
}