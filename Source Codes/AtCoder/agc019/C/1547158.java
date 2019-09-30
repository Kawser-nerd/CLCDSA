import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

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
		
		boolean fRevX = (x2 < x1);
		boolean fRevY = (y2 < y1);
		if(fRevX){
			x1 = reverse(fRevX,x1);
			x2 = reverse(fRevX,x2);
		}
		if(fRevY){
			y1 = reverse(fRevY,y1);
			y2 = reverse(fRevY,y2);
		}
		int dirX=x2-x1;
		int dirY=y2-y1;

		Pair[] F = new Pair[N];
		int index=0;
		for(int i=0; i<N; i++) {
			int x = reverse(fRevX,in.nextInt());
			int y = reverse(fRevY,in.nextInt());
			Pair f = new Pair(x,y);
			if(checkBetween(x1,x2,f.x()) && checkBetween(y1,y2,f.y())) {
				F[index++] = f;
			}
		}
		double dir = (long)(dirX+dirY)*100;
		if ( (dirX==0 || dirY==0) && index>0 ){
			dir += FH;
		}else if (index>0) {
			Arrays.sort(F,0,index);
			int max = getLongestIncreasingSequence(F,index,0);
			
			if(max == Math.min(dirX+1, dirY+1)) {
				dir += FQ * (max-1) + FH;
			} else {
				dir += FQ * max;
			}
		}
		out.printf("%.12f\n",dir);
		out.flush();
	}
	
	boolean checkBetween(int v1, int v2, int vc) {
		return (v1 <= vc && vc <= v2);
	}
	
	int getLongestIncreasingSequence(Pair[] in, int len, int minValue) {
		int maxPath = 0;
		int[] maxSeq = new int[len];
		Arrays.fill(maxSeq,minValue);
		for(int i=0; i<len; i++) {
			if(maxPath == 0){
				maxSeq[0] = in[i].y();
				maxPath = 1;
			} else {
				int insIdx = Arrays.binarySearch(maxSeq, 0, maxPath, in[i].y());
				if(insIdx < 0){
					insIdx = -insIdx - 1;
					maxSeq[insIdx] = in[i].y();
					if(maxPath==insIdx) maxPath ++;
				}
			}
		}
		return maxPath;
	}
	
	void swap(int a, int b) {
		int t=a; a=b; b=t;
	}
	int reverse(boolean rev,int xOrY) {
		return rev ? (99999999 - xOrY) : xOrY;
	}
	
}

class Pair implements Comparable<Pair> {
	int v1;
	int v2;
	
	public Pair(int v1, int v2) {
		this.v1=v1;
		this.v2=v2;
	}
	
	public int getSortKey() {
		return v1;
	}
	
	public int x(){return v1;}
	public int y(){return v2;}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + v1;
		result = prime * result + v2;
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
		Pair other = (Pair) obj;
		if (v1 != other.v1)
			return false;
		if (v2 != other.v2)
			return false;
		return true;
	}

	@Override
	public int compareTo(Pair arg0) {
		return getSortKey() - arg0.getSortKey();
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