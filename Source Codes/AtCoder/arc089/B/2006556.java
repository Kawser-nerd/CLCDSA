import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
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
		System.out.println(-3%2);
	}
	
	//*
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	/*/
	InputUtil in = new InputUtil();
	//*/
	PrintWriter out = new PrintWriter(System.out);
	String S = null;
	int N = 0;
	int K = 0;
	char[] c = null;
	int[] x = null;
	int[] y = null;
	int ans = 0;
	long time = -1;
	
	public void input() throws IOException {
		time = System.currentTimeMillis();
		//*
		S = br.readLine();
		String[] tmp = S.split(" +");
		N = Integer.parseInt(tmp[0]);
		K = Integer.parseInt(tmp[1]);
		x = new int[N];
		y = new int[N];
		c = new char[N];
		for (int i=0; i<N; i++) {
			S = br.readLine();
			tmp = S.split(" +");
			x[i] = Integer.parseInt(tmp[0]);
			y[i] = Integer.parseInt(tmp[1]);
			c[i] = tmp[2].charAt(0);
		}
		/*/
		//*/
		
	}
	
	private String printTime() {
		return "time="+(System.currentTimeMillis()-time);
	}

	public void solve() throws IOException {
		char[][] matrixW = new char[2*K][2*K];
		char[][] matrixB = new char[2*K][2*K];
		char[][] matrixW_XRange_YFix = new char[2*K][2*K];
		char[][] matrixW_XFix_YRange = new char[2*K][2*K];
		char[][] matrixB_XRange_YFix = new char[2*K][2*K];
		char[][] matrixB_XFix_YRange = new char[2*K][2*K];
		int[][] countMatrix = new int[K][K];

		for (int i=0; i<N; i++) {
			if (c[i] == 'W') {
				matrixW[x[i]%(2*K)][y[i]%(2*K)] ++;
			} else {
				matrixB[x[i]%(2*K)][y[i]%(2*K)] ++;
			}
		}

		//XFix_YRange
		for (int x=0; x<2*K; x++) {
			for (int y=0; y<K; y++) {
				matrixW_XFix_YRange[x][0] += matrixW[x][y];
				matrixB_XFix_YRange[x][0] += matrixB[x][y];
			}
			for (int y=1; y<2*K; y++) {
				matrixW_XFix_YRange[x][y] += matrixW_XFix_YRange[x][y-1] + matrixW[x][(y+K-1)%(2*K)] - matrixW[x][y-1];
				matrixB_XFix_YRange[x][y] += matrixB_XFix_YRange[x][y-1] + matrixB[x][(y+K-1)%(2*K)] - matrixB[x][y-1];
			}
		}

		//XRange_YFix
		for (int y=0; y<2*K; y++) {
			for (int x=0; x<K; x++) {
				matrixW_XRange_YFix[0][y] += matrixW[x][y];
				matrixB_XRange_YFix[0][y] += matrixB[x][y];
			}
			for (int x=1; x<2*K; x++) {
				matrixW_XRange_YFix[x][y] += matrixW_XRange_YFix[x-1][y] + matrixW[(x+K-1)%(2*K)][y] - matrixW[x-1][y];
				matrixB_XRange_YFix[x][y] += matrixB_XRange_YFix[x-1][y] + matrixB[(x+K-1)%(2*K)][y] - matrixB[x-1][y];
			}
		}
		
		int maxOk = -1;
		int countOk = 0;
		for (int offx=0; offx<K; offx++) {
			for (int offy=0; offy<K; offy++) {
				if (offx==0 && offy ==0) {
					for (int i=0; i<N; i++) {
						if ((x[i]/K + y[i]/K)%2 == ((c[i]=='W')?0:1)) {
							countOk ++;
						}
					}
					countMatrix[0][0] = countOk;
				} else if (offy==0){
					countOk = countMatrix[offx][offy] = countMatrix[offx-1][offy] 
							+ matrixW_XFix_YRange[offx+K-1][offy]
							- matrixW_XFix_YRange[offx-1][offy]
							- matrixB_XFix_YRange[offx+K-1][offy]
							+ matrixB_XFix_YRange[offx-1][offy]
							- matrixW_XFix_YRange[offx+K-1][offy+K]
							+ matrixW_XFix_YRange[offx-1][offy+K]
							+ matrixB_XFix_YRange[offx+K-1][offy+K]
							- matrixB_XFix_YRange[offx-1][offy+K];
				} else {
					countOk = countMatrix[offx][offy] = countMatrix[offx][offy-1] 
							+ matrixW_XRange_YFix[offx][offy+K-1]
							- matrixW_XRange_YFix[offx][offy-1]
							- matrixB_XRange_YFix[offx][offy+K-1]
							+ matrixB_XRange_YFix[offx][offy-1]
							- matrixW_XRange_YFix[offx+K][offy+K-1]
							+ matrixW_XRange_YFix[offx+K][offy-1]
							+ matrixB_XRange_YFix[offx+K][offy+K-1]
							- matrixB_XRange_YFix[offx+K][offy-1];
				}
				maxOk = Math.max(maxOk, Math.max(countOk, N-countOk));
			}
		}
		ans = maxOk;
	}
	
	
	
	public void output() {
		out.println(ans);
		out.flush();
	}
}

//*
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
//*/