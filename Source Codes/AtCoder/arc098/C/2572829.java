import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;


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
	
	int N, K, Q;
	int[] A,ASorted;
	Map<Integer,List<Integer>> Amap = new HashMap<>();
	long ans = 0;
//	boolean ans = false;
			
	public void input() throws IOException {
		N = in.nextInt();
		K = in.nextInt();
		Q = in.nextInt();
		A = in.nextInt(new int[N]);
		ASorted = new int[N];
		System.arraycopy(A, 0, ASorted, 0, N);
		Arrays.sort(ASorted);
		for (int i=0; i<N; i++) {
			addAmap(A[i],i);
		}
	}
	
	private void addAmap (int key, int val) {
		List<Integer> valList;
		if (Amap.containsKey(key)) {
			valList = Amap.get(key);
		} else {
			valList = new ArrayList<>();
			Amap.put(key, valList);
		}
		valList.add(val);
	}
	
	public void solve() throws IOException {
		ans = Integer.MAX_VALUE;
		TreeSet<Integer> ngIdxSet = new TreeSet<>();
		TreeMap<Integer,Integer> rangesMap = new TreeMap<>();
		rangesMap.put(0,N-1);
		
		for (int i=0; i<N-Q+1 && ans > 0; ) {
			List<Integer> AmapList = null;

			if (ans > ASorted[i+Q-1] - ASorted[i]) {
				int result = check(i,ngIdxSet, rangesMap);
				if (result<0) {
					return;
				} else {
					ans = (ans>result)?result:ans;
				}
			}
			AmapList = Amap.get(ASorted[i]);
			for (int elem : AmapList) { 
				ngIdxSet.add(elem);
				int rangeStartIdx = rangesMap.floorKey(elem);
				int rangeEndIdx = rangesMap.get(rangeStartIdx);
				if (rangeStartIdx == elem) {
					rangesMap.remove(rangeStartIdx);
				} else {
					rangesMap.put(rangeStartIdx, elem-1);
				}
				if (rangeEndIdx > elem){
					rangesMap.put(elem+1, rangeEndIdx);
				}
			}
			i += AmapList.size();
		}
	}
	
	private int check(int idx, TreeSet<Integer> ngIdxSet, TreeMap<Integer,Integer> rangesMap) {
		int checkResult = 0;
		if (idx==0) {
			checkResult = ASorted[Q-1] - ASorted[0];
		} else if (idx>0) {
			List<Integer> exList = new ArrayList<>();

			//????????????????
			Map<Integer,Integer> rangeCountMap = new HashMap<>();
			int activeRanges = 0;
			for (Map.Entry<Integer, Integer> e : rangesMap.entrySet()) {
				int k = e.getKey();
				int v = e.getValue();
				int rangeCount = v-k+1-K;
				rangeCountMap.put(k, rangeCount);
				if (rangeCount >= 0) {
					activeRanges ++;
				}
			}
			
			List<Integer> AmapList = null;
			for (int j=idx; j<N && exList.size() < Q && activeRanges>0; j+=AmapList.size()) {
				AmapList = Amap.get(ASorted[j]);
				for (int elem: AmapList) {
					int rangeStartIdx = rangesMap.floorKey(elem);
					int rangeCount = rangeCountMap.get(rangeStartIdx);
					if (rangeCount>=0) {
						exList.add(A[elem]);
					}
					rangeCountMap.put(rangeStartIdx, --rangeCount);
					if (rangeCount == -1) {
						activeRanges--;
					}
					if (activeRanges <= 0) {
						break;
					}
				}
			}
			if (exList.size() < Q) {
				return -1;
			}
			Collections.sort(exList);
			checkResult = exList.get(Q-1) - exList.get(0);
			
		} else {
			return -1;
		}
		return checkResult;
	}
	
	
	
	public void output() {
		out.println(ans);
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