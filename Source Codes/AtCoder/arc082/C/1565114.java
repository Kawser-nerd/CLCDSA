import java.awt.Point;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;


public class Main {
	
	public static void main(String[] args) throws IOException {
//		ModUtil mu = new ModUtil();
//		System.out.println(mu.getC(200, 100));
		new Main().exec();
	}
	
	public void exec() throws IOException {
		InputUtil in = new InputUtil();
		PrintWriter out = new PrintWriter(System.out);
		ModUtil mu = new ModUtil();
		int N = in.nextInt();
		Point[] P = new Point[N];
		HashMap<Line,Integer> lineMap = new HashMap<>();
		for(int i=0; i<N; i++) {
			P[i] = new Point(in.nextInt(),in.nextInt());
		}
		int lineMax = 1;
		for(int i=0; i<N-1; i++){
			for(int j=i+1; j<N; j++) {
				Line l = Line.getLine(P[i], P[j]);
				if(lineMap.containsKey(l)){
					int tmp = lineMap.get(l) + 1;
					lineMap.put(l, tmp);
					lineMax = Math.max(lineMax, tmp);
				}else{
					lineMap.put(l, 1);
				}
			}
		}
		HashMap<Integer,Integer> lineNumMap = new HashMap<>();
		for(int lineNum: lineMap.values()) {
			if(lineNumMap.containsKey(lineNum)){
				lineNumMap.put(lineNum, lineNumMap.get(lineNum)+1);
			}else{
				lineNumMap.put(lineNum, 1);
			}
		}
		int ans = mu.power(2, N);
		ans = mu.sub(ans, 1);
		ans = mu.sub(ans, N);
		int pointMax = 2;
		int lines = 1;
		while(lines <= lineMax){
			Integer lineNum = lineNumMap.get(lines);
			if(lineNum != null) {
				for(int j=2; j<=pointMax; j++) {
					int subSetNum = mu.getC(pointMax, j);
					int totalSubSetNum = mu.multiple(subSetNum, lineNum);
					ans = mu.sub(ans, totalSubSetNum);
				}
			}
			pointMax++;
			lines = pointMax * (pointMax-1) / 2;
		}
		
		out.println(ans);
		out.flush();
	}
	
}

class Fraction implements Comparable<Fraction> {
	public static final Fraction INFINITE = new Fraction();
	int numerator = 0;
	int denominator = 1;
	
	private Fraction (){
		numerator = 1;
		denominator = 0;
	}
	public Fraction(int n, int d) {
		if(d<=0) throw new IllegalArgumentException();
		numerator=n;
		denominator=d;
		reduce();
	}
	
	public Fraction reduce() {
		if(this==INFINITE) return this;
		int gcd = MyMath.getGcd(numerator,denominator);
		numerator /= gcd;
		denominator /= gcd;
		return this;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + denominator;
		result = prime * result + numerator;
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
		Fraction other = (Fraction) obj;
		if (denominator != other.denominator)
			return false;
		if (numerator != other.numerator)
			return false;
		return true;
	}
	
	public double doubleValue() {
		if(this==INFINITE) return Double.NaN;
		return ((double)numerator)/denominator;
	}

	@Override
	public int compareTo(Fraction f) {
		if(this==f) return 0;
		return Double.compare(doubleValue(), f.doubleValue());
	}
	
	@Override
	public String toString() {
		return new StringBuilder().append("Fraction(").append(numerator).append("/").append(denominator).append(")").toString();
	}

}

class Line {
	Fraction slope = null;
	Fraction intercept = null;
	
	public static Line getLine(Point a, Point b) {
		if(a.x==b.x)
			return new Line(Fraction.INFINITE,new Fraction(a.x,1));
		if(a.x > b.x) 
			return getLine(b,a);
		else{
			int sn = b.y-a.y;
			int sd = b.x-a.x;
			int in = sd*a.y - sn*a.x;
			int id = sd;
			return new Line(sn, sd, in, id);
		}
	}
	
	private Line(int sn, int sd, int in, int id) {
		this(new Fraction(sn,sd),new Fraction(in,id));
	}
	
	private Line(Fraction slope, Fraction intercept) {
		this.slope=slope;
		this.intercept=intercept;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((intercept == null) ? 0 : intercept.hashCode());
		result = prime * result + ((slope == null) ? 0 : slope.hashCode());
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
		Line other = (Line) obj;
		if (intercept == null) {
			if (other.intercept != null)
				return false;
		} else if (!intercept.equals(other.intercept))
			return false;
		if (slope == null) {
			if (other.slope != null)
				return false;
		} else if (!slope.equals(other.slope))
			return false;
		return true;
	}
	
	@Override
	public String toString() {
		return new StringBuilder().append("Line(").append(slope).append(",").append(intercept).append(")").toString();
	}

}

class ModUtil {
	//Static Fields
	public static final int BASE_DEF = 998244353;
	public static final int CAPACITY_F = 200;
	
	//Fields
	protected int mod = BASE_DEF;
	protected int capacity = CAPACITY_F;
	private int[] Farray = null;;
	private int[] FInvarray = null;

	//Constructors
	public ModUtil() {
		initF();
	}
	public ModUtil(int m, int cap) {
		mod = m;
		capacity=cap;
		initF();
	}
	
	//Methods
	//Initializer
	protected void initF() {
		if(Farray != null) return;
		Farray = new int[capacity+1];
		FInvarray = new int[capacity+1];
		for(int n=0; n<Farray.length; n++) {
			Farray[n] = (n==0) ? 1 : multiple(n, Farray[n-1]);
			FInvarray[n] = divide(1, Farray[n]);
		}
	}

	//Basic Opertion
	public int modulo(long v) {return (int)(v%mod);}
	public int add(int a, int b) {return modulo(a + b);}
	public int sub(int a, int b) {return add(a, mod - b);}
	public int multiple(int a, int b) {return modulo((long)a * modulo(b));}
	public int divide(int a, int b) {return multiple(a, power(b, mod-2));}
	
	public int divideF(int a, int fn) {
		if(fn<=capacity) {
			return multiple(a, getFInv(fn));
		}else{
			return divide(a, getF(fn));
		}
	}
	
	public int power(int a, int b) {
		int ret = 1;
		for (int bitMask = 1; bitMask<=b; bitMask<<=1) {
			if ( (b & bitMask) != 0 ) ret = multiple(ret, a);
			a = multiple(a, a);
		}
		return ret;
	}

	//Factorial Operation
	public int getF(int n) {return Farray[n];}
	public int getFInv(int n) {return FInvarray[n];}

	//Permutation Operation
	protected int calcP(int n, int r) {
		if (n < 0 || r < 0 || n < r) throw new IllegalArgumentException("n=" +n+ ",r=" +r);
		if (n <= 1 || r == 0) return 1;
		if (r == 1) return n;
		return divideF(getF(n), n-r);
		
	}

	public int getP(int n, int r) {return calcP(n, r);}

	//Combination Operation
	protected int calcC(int n, int r) {
		if(n < 0 || r < 0 || n < r) throw new IllegalArgumentException("n=" +n+ ",r=" +r);
		if(n == 0 || n == 1) return 1;
		if(n - r < r) r = n - r;
		return divideF(divideF(getF(n), r),n-r);
	}
	
	public int getC(int n, int r) {return calcC(n,r);}
	public int getH(int n, int r) {return calcC(n+r-1, r);}

}

class MyMath {
	public static long getGcd(long a, long b){
		long tmp = 0;
		while (a%b!=0) {
			tmp = b;
			b = a%b;
			a = tmp;
		}
		return b;
	}

	public static int getGcd(int a, int b){
		return (int)getGcd((long)a, (long)b);
	}

	
	public static long getLcm(long a, long b){
		long gcd = getGcd(a,b);
		return (a/gcd)*b;
	}
	public static int getLcm(int a, int b){
		return (int)getLcm((long)a, (long)b);
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