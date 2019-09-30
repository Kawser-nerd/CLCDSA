import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

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
	
//	public void debug() {
//	}
	
	
	InputUtil in = new InputUtil();
	PrintWriter out = new PrintWriter(System.out);
	int Q = 0;
	long[] A = null;
	long[] B = null;
	

//	boolean ansb = false;
	long[] ans = null;
	public void input() throws IOException {
		Q = in.nextInt();
		A = new long[Q];
		B = new long[Q];
		ans = new long[Q];
		for (int i=0; i<Q; i++) {
			A[i] = in.nextInt();
			B[i] = in.nextInt();
		}
	}
	
	public void solve() throws IOException {
		for (int i=0; i<Q; i++) {
			long score = A[i] * B[i];
			if (score == 1) {
				ans[i] = 0;
				continue;
			}
			if (A[i] > B[i]) {
				long tmp = A[i]; A[i]=B[i]; B[i]=tmp;
			}
			double tmpd1 = Math.sqrt(score-1);
			double tmpd2 = Math.floor(tmpd1);
			long scoreSqrt = new Double(tmpd2).longValue();
			
			while (scoreSqrt*scoreSqrt >= score) {
				scoreSqrt--;
			}
			
			ans[i] = scoreSqrt*2;
			
			if (A[i] <= scoreSqrt) {
				ans[i] --;
			}
			long tmp = (score-1)/scoreSqrt;
			if (scoreSqrt == tmp) {
				ans[i] -= 1;
			}
		}
	}
	
//	public void solve2() throws IOException {
//		for (int i=0; i<Q; i++) {
//			long score = A[i] * B[i];
//			HashSet<Long> bset = new HashSet<>();
//			for (long a=1; a<score; a++) {
//				if (a == A[i]) continue;
//				long b = (score-1)/a;
//				if (b == B[i] || bset.contains(b)) continue;
//				bset.add(b);
//			}
//			ans[i] = bset.size();
//		}
//	}
	
	public void output() {
		for (int i=0; i<Q; i++) {
			out.println(ans[i]);
		}
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