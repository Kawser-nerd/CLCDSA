import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;


public class Main {
	
	public static void main(String[] args) throws IOException {
		Main m = new Main();
		m.input();
		m.solve();
		m.output();
	}
	/*
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	/*/
	InputUtil in = new InputUtil();
	PrintWriter out = new PrintWriter(System.out);
	//*/
	int N = 0;
	int Z = 0;
	int W = 0;
	int[] a = null;
	int[] mintmp = null;
	int[] mintmp2 = null;
	int[] maxtmp = null;
	int[] maxtmp2 = null;
	HashMap<Condition,Integer> map = new HashMap<>(); 
	int X = 0;
	int Y = 0;
	int ans = 0;
	
	public void input() throws IOException {
		/*
		S = br.readLine();
		/*/
		N = in.nextInt();
		X = Z = in.nextInt();
		Y = W = in.nextInt();
		a = in.nextInt(new int[N]);
		//*/
	}

	public void solve() throws IOException {
		ans = -1;
		for(int i=N-1; i>=0; i--)
			ans = Math.max(ans, solveSub(X,Y,i,true));
	}
	
	public int solveSub(int XNum, int YNum, int nextIndex, boolean nextX) throws IOException {
		Condition tmp = new Condition(XNum,YNum,nextIndex,nextX);
		if(map.containsKey(tmp)){
			return map.get(tmp);
		}
		int ret = -1;
		if(nextIndex + 1 == N){
			if(nextX){
				XNum = a[nextIndex];
			}else{
				YNum = a[nextIndex];
			}
			ret = Math.abs(XNum-YNum);
		}else{
			for(int i=N-1; i>=nextIndex; i--){
				int score = nextX
						? solveSub(a[nextIndex],YNum,nextIndex+1,!nextX)
						: solveSub(XNum,a[nextIndex],nextIndex+1,!nextX);
				if(ret == -1)
					ret = score;
				else{
					if(nextX)
						ret = Math.max(ret, score);
					else
						ret = Math.min(ret, score);
				}
			}
		}
		map.put(tmp, ret);
		return ret;

	}
	

	public void output() {
		out.println(ans);
		out.flush();
		
	}
}

class Condition { 
	int XNum = -1;
	int YNum = -1;
	int nextIndex = -1;
	boolean nextX = false;
	public Condition(){}
	public Condition(int XNum, int YNum, int nextIndex, boolean nextX) {
		set(XNum,YNum,nextIndex,nextX);
	}
	
	public Condition set (int XNum, int YNum, int nextIndex, boolean nextX) {
		this.XNum = XNum;
		this.YNum = YNum;
		this.nextIndex = nextIndex;
		this.nextX = nextX;
		return this;
	}
	
	
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + XNum;
		result = prime * result + YNum;
		result = prime * result + nextIndex;
		result = prime * result + (nextX ? 1231 : 1237);
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Condition other = (Condition) obj;
		if (XNum != other.XNum)
			return false;
		if (YNum != other.YNum)
			return false;
		if (nextIndex != other.nextIndex)
			return false;
		if (nextX != other.nextX)
			return false;
		return true;
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