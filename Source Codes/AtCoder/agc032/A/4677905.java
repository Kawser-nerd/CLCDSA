import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;


public class Main {
	
	public static void main(String[] args) throws Exception {
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
		LinkedList<Integer> a = new LinkedList<>(); 
		for (int i=0; i<100; i++) {
			int num = (int)(Math.random() * (i+1)) + 1;
			System.out.println("step:"+(i+1)+",num="+num);
			a.add(num-1,num);
		}
		PrintWriter out = new PrintWriter(System.out);
		OutputUtil.outputDivSpace(out, a.toArray(new Integer[a.size()]));
	}
	
	InputUtil in = new InputUtil();
	PrintWriter out = new PrintWriter(System.out);
	
	int N = 0;
	int[] b = null;
	int[] ans = null;
	LinkedList<Integer> a = new LinkedList<>();
	HashMap<Integer,List<Integer>> numMap = new HashMap<>();
	int[] numIdx = null;
	int[] numCnt = null;
	boolean[] bInserted = null;
	int[] bNowIdx = null;
	
	public void input() throws Exception {
		N = in.nextInt();
		b = in.nextInt(new int[N]);
		ans = new int[N];
		numIdx = new int[N+1];
		numCnt = new int[N+1];
		bInserted = new boolean[N];
		bNowIdx= new int[N];
		initMap();
	}
	
	private void initMap() {
		for (int i=0; i<N; i++) {
			numIdx[i]=0;
			numCnt[i]=0;
		}
		for (int i=N-1; i>=0; i--) {
			List<Integer> posList = null;
			if (numMap.containsKey(b[i])) {
				posList = numMap.get(b[i]);
			} else {
				posList = new ArrayList<>();
			}
			posList.add(i);
			numMap.put(b[i], posList);
			numCnt[b[i]]++;
		}
		count_bNowIdx();
	}
	
	public void solve() throws Exception {
		if (!solveSub(0)){
			ans = new int[]{-1};
		}
	}
	
	private boolean solveSub(int step) {
		if (step>0) {
			if (!checkAns()) {
				return false;
			}
			
			if (step == N) {
				return true;
			}
			
		} else {
			for (int i=0; i<N; i++) {
				if (b[i] > i+1) {
					return false;
				}
			}
		}
		int nextStep = step+1;
	
		for(int i=N-1; i>=0; i--){
			int num = b[i];
			if (bInserted[i]) {
				continue;
			}
			if (num>nextStep) {
				continue;
			}
			if (bNowIdx[i]!=num) {
				continue;
			}
			bInserted[i]=true;
			ans[nextStep-1]=num;
			a.add(num-1,num);
			numIdx[num]++;
			count_bNowIdx();
			if(solveSub(nextStep)){
				return true;
			} else {
				a.remove(num-1);
				bInserted[i]=false;
				ans[nextStep-1]=0;
				numIdx[num]--;
				count_bNowIdx();
			}
		}
		return false;
	}
	
	private void count_bNowIdx() {
		int index=1;
		for(int i=0; i<N; i++) {
			bNowIdx[i]=index;
			if (bInserted[i]) {
				index++;
			}
		}
	}
	
	private boolean checkAns(){
		int i=0;
		for(int ai: a) {
			while(i<b.length && b[i]!=ai){
				i++;
			}
			if (i>=b.length){
				return false;
			}
			i++;
		}
		return true;
	}

	public void output() {
		for(int a: ans) {
			out.println(a);
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

	public static void outputDivSpace(PrintWriter out, Integer[] a) {
		OutputUtil.output(out,a,0,a.length," ");
	}
	
	public static void outputDivEOF(PrintWriter out, Integer[] a) {
		OutputUtil.output(out,a,0,a.length,EOF);
	}
	
	public static void output(PrintWriter out, Integer[] a, int off, int len, String delim) {
		out.print(a[off]);
		for(int i=off+1; i<len; i++){
			out.print(delim);
			out.print(a[i]);
		}
		out.println("");
		out.flush();
	}

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