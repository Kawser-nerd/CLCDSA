import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws NumberFormatException,
	IOException {Main solve = new Main();solve.solve();}
	void dump(int[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(int[]a,int n){for(int i=0;i<a.length;i++)System.out.printf("%"+n+"d",a[i]);System.out.println();}
	void dump(long[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(char[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]);System.out.println();}
	long pow(long a,int n){long r=1;while(n>0){if((n&1)==1)r*=a;a*=a;n>>=1;}return r;}
	String itob(int a,int l){return String.format("%"+l+"s",Integer.toBinaryString(a)).replace(' ','0');}
	int binarySearchSmallerMax(int[]a,int v) // get maximum index which a[idx]<=v
	{int l=0,r=a.length-1,s=0;while(l<=r){int m=(l+r)/2;if(a[m]>v)r=m-1;else{l=m+1;s=m;}}return a[s]>v?-1:s;}
	void solve() throws NumberFormatException, IOException{
		final ContestScanner in = new ContestScanner();
		Writer out = new Writer();
		int n = in.nextInt();
		int A = in.nextInt();
		int B = in.nextInt();
		if(A==1){
			int[] a = new int[n];
			for(int i=0; i<n; i++) a[i] = in.nextInt();
			Arrays.sort(a);
			for(int i=0; i<n; i++){
				System.out.println(a[i]);
			}
			return;
		}
		D[] a = new D[n];
		double min = Integer.MAX_VALUE;
		double max = Integer.MIN_VALUE;
		for(int i=0; i<n; i++){
			int tmp = in.nextInt();
			a[i] = new D(Math.log10(tmp)/Math.log10(A), tmp);
			min = Math.min(min, a[i].a);
			max = Math.max(max, a[i].a);
		}
		Arrays.sort(a);
		while(max-min>=1 && B>0){
			a[0].a++;
			B--;
			a[0].x++;
			Arrays.sort(a);
			min = a[0].a;
			max = a[a.length-1].a;
		}
		int each = B/n;
		B %= n;
		for(int i=0; i<n; i++){
			a[i].x += each;
		}
		while(B>0){
			a[0].a++;
			B--;
			a[0].x++;
			Arrays.sort(a);
		}
		Arrays.sort(a);
		final int mod = 1000000007;
		for(int i=0; i<n; i++){
			System.out.println(modpow(A, a[i].x, mod)*a[i].origin%mod);
		}
	}
	
	long modpow(int n, int a, int mod){
		long res = 1;
		while(a > 0){
			if((a&1)==1) res = (res*n)%mod;
			n = (int)(((long)n*n)%mod);
			a >>= 1;
		}
		return res;
	}
}

class D implements Comparable<D>{
	double a;
	int x;
	int origin;
	D(double a, int origin){
		this.a = a;
		this.origin = origin;
	}
	@Override
	public int compareTo(D o) {
		return Double.compare(a, o.a);
	}
	@Override
	public String toString() {
		return String.valueOf(a);
	}
}

class MultiSet<T> extends HashMap<T, Integer>{
	@Override
	public Integer get(Object key){return containsKey(key)?super.get(key):0;}
	public void add(T key,int v){put(key,get(key)+v);}
	public void add(T key){put(key,get(key)+1);}
	public void sub(T key)
	{final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
}
class Timer{
	long time;
	public void set(){time=System.currentTimeMillis();}
	public long stop(){return time=System.currentTimeMillis()-time;}
	public void print()
	{System.out.println("Time: "+(System.currentTimeMillis()-time)+"ms");}
	@Override public String toString(){return"Time: "+time+"ms";}
}
class Writer extends PrintWriter{
	public Writer(String filename)throws IOException
	{super(new BufferedWriter(new FileWriter(filename)));}
	public Writer()throws IOException{super(System.out);}
}
class ContestScanner {
	private InputStreamReader in;private int c=-2;
	public ContestScanner()throws IOException 
	{in=new InputStreamReader(System.in);}
	public ContestScanner(String filename)throws IOException
	{in=new InputStreamReader(new FileInputStream(filename));}
	public String nextToken()throws IOException {
		StringBuilder sb=new StringBuilder();
		while((c=in.read())!=-1&&Character.isWhitespace(c));
		while(c!=-1&&!Character.isWhitespace(c)){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public String readLine()throws IOException{
		StringBuilder sb=new StringBuilder();if(c==-2)c=in.read();
		while(c!=-1&&c!='\n'&&c!='\r'){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public long nextLong()throws IOException,NumberFormatException
	{return Long.parseLong(nextToken());}
	public int nextInt()throws NumberFormatException,IOException
	{return(int)nextLong();}
	public double nextDouble()throws NumberFormatException,IOException 
	{return Double.parseDouble(nextToken());}
}