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
	
	public void solve() throws IOException {
		int[][] matrixB = new int[2*K+1][2*K+1];
		//Count
		for (int i=0; i<N; i++) {
			if (c[i] == 'W') {
				matrixB[(x[i]+K)%(2*K)+1][y[i]%(2*K)+1] ++;
			} else {
				matrixB[x[i]%(2*K)+1][y[i]%(2*K)+1] ++;
			}
		}
		//Sum
		for (int x=1; x<2*K+1; x++) {
			for (int y=1; y<2*K+1; y++) {
				matrixB[x][y] += matrixB[x-1][y];
				matrixB[x][y] += matrixB[x][y-1];
				matrixB[x][y] -= matrixB[x-1][y-1];
			}
		}
		
		for (int x=0; x<K; x++) {
			for (int y=0; y<K; y++) {
				int a = matrixB[x][y];
				int b = matrixB[x+K][y];
				int c = matrixB[2*K][y];
				int d = matrixB[x][y+K];
				int e = matrixB[x+K][y+K];
				int f = matrixB[2*K][y+K];
				int g = matrixB[x][2*K];
				int h = matrixB[x+K][2*K];
				int i = matrixB[2*K][2*K];
				int count = 2*a - 2*b + c - 2*d + 2*e - f + g - h + i;
				ans = Math.max(ans, Math.max(count, N-count));
				//System.out.println("x="+x+",y="+y+"(a,b,c,d,e,f,g,h,i)='("+a+","+b+","+c+","+d+","+e+","+f+","+g+","+h+","+i+"),count="+count+",ans="+ans);
			}
		}
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