import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	//????180?
	final double FH = 10 * Math.PI - 20;
	//????90?
	final double FQ = 5 * Math.PI - 20;

	public static long l=0,l2=0;
	public static void main(String[] args) throws IOException {
		l = System.currentTimeMillis();
		new Main().exec();
		l2 = System.currentTimeMillis();
		
	}

	public void exec() throws IOException {
		
		InputUtil in = new InputUtil();
		PrintWriter out = new PrintWriter(System.out);
		int x1 = (int)in.nextInt();
		int y1 = (int)in.nextInt();
		int x2 = (int)in.nextInt();
		int y2 = (int)in.nextInt();
		int N = (int)in.nextInt();
		
		if(x2 < x1){
			int t=x1; x1=x2; x2=t;
			t=y1; y1=y2; y2=t;
		}
		boolean fRevY = (y2 < y1);
		int dirX=x2-x1;
		int dirY=fRevY?(y1-y2):(y2-y1);

		int[] FX = new int[N];
		int[] FY = new int[N];
		Integer[] F = new Integer[N];
		int index=0;
		for(int i=0; i<N; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			if(checkBetween(x1,x2,x,false) 
					&& checkBetween(y1,y2,y,fRevY)) {
				FX[index] = x;
				FY[index] = y;
				F[index] = index;
				index++;
			}
		}
		double dir = (long)(dirX+dirY)*100;
		if ( (dirX==0 || dirY==0) && index>0 ){
			dir += FH;
		}else if (index>0) {
			F = Arrays.copyOf(F, index);
			Arrays.sort(F,new Comparator<Integer>(){
				@Override
				public int compare(Integer o1, Integer o2) {
					return FX[o1.intValue()]-FX[o2.intValue()];
				}
			});
			int max = getLongestIncreasingSequence(F,FY,index,Integer.MIN_VALUE,fRevY);
			
			if(max == Math.min(dirX+1, dirY+1)) {
				dir += FQ * (max-1) + FH;
			} else {
				dir += FQ * max;
			}
		}
		out.printf("%.12f\n",dir);
		out.flush();
	}
	
	boolean checkBetween(int v1, int v2, int vc, boolean reverse) {
		if(!reverse)
			return (v1 <= vc && vc <= v2);
		else
			return (v2 <= vc && vc <= v1);
	}
	
	int getLongestIncreasingSequence(Integer[] F, int[] FY, int len, int minValue, boolean reverse) {
		int maxPath = 0;
		int[] maxSeq = new int[len];
		Arrays.fill(maxSeq,minValue);
		for(int i=0; i<len; i++) {
			int y = FY[F[i]];
			if(maxPath == 0){
				maxSeq[0] = y;
				maxPath = 1;
			} else {
				int insIdx = binarySearch(maxSeq, 0, maxPath, y, reverse);
				maxSeq[insIdx] = y;
				if(maxPath==insIdx) maxPath ++;
			}
		}
		return maxPath;
	}
	
	int binarySearch(int S[], int from, int to, int search, boolean reverse) {
		if(!reverse) {
			while (from + 1 < to) {
				int mid = (from + to)/2;
				if (search > S[mid-1])
					from = mid;
				else
					to = mid;
			}
			return (search > S[from])?(from+1):from;
		} else {
			while (from + 1 < to) {
				int mid = (from + to)/2;
				if (search < S[mid-1])
					from = mid;
				else
					to = mid;
			}
			return (search < S[from])?(from+1):from;
		}
    }
	int reverse(boolean rev,int xOrY) {
		return rev ? (99999999 - xOrY) : xOrY;
	}
	
}




class InputUtil {
	//Static Fields
	private static final int BUFSIZ = 100000;
	
	//Fields
	protected InputStream in;
	private char[] buf = null;
	private int ptr = 0;
	private int max = -1;
	private BufferedReader br = null;
	
	//Constructors
	public InputUtil() {this(System.in,BUFSIZ);}
	public InputUtil(InputStream in, int bufsiz) {
		initBuf(bufsiz);
		initIn(in);
	}
	
	//Methods
	//Initializer
	protected void initIn(InputStream in) {br = new BufferedReader(new InputStreamReader(this.in = in));}
	protected void initBuf(int bufsiz) {buf = new char[bufsiz];}
	
	//buffer operation
	private void next() throws IOException {ptr++; readBuf();}
	private void readBuf() throws IOException {
		if(ptr >= max && br.ready()) {
			if(max>0) Arrays.fill(buf,0,max,(char)0);
			max = br.read(buf);
			ptr = 0;
		}
	}
	
	//Number Input Reader/Parser
	private boolean isNum(char b) {return '0' <= b && b <= '9'; }
	private boolean isMinus(char b) {return b=='-'; }

	private int _nextInt() throws IOException {
		int sign = 1;
		int res = 0;
		char c;
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