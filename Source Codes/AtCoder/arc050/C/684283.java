import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;
 
public class Main {
	public static void main(String[] args) throws NumberFormatException,
	IOException {Solve solve = new Solve();solve.solve();}
}
class Solve{
	void dump(int[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(int[]a,int n){for(int i=0;i<a.length;i++)System.out.printf("%"+n+"d",a[i]);System.out.println();}
	void dump(long[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(char[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]);System.out.println();}
	String itob(int a,int l){return String.format("%"+l+"s",Integer.toBinaryString(a)).replace(' ','0');}
	void solve() throws NumberFormatException, IOException{
		final ContestScanner in = new ContestScanner();
		Writer out = new Writer();
		long a = in.nextLong();
		long b = in.nextLong();
		int m = in.nextInt();
		long d = gcd(a, b);
		long[][] f = {{1, 1}};
		long[][] x = {
				{1, 1},
				{0, 10}
		};
		long xm = modfib(a, m, f, x);
		x[1][1] = modpow(10, d, m);
		f[0][1] = 1;
		long ym = modfib(b/d, m, f, x);
		System.out.println(xm*ym%m);
	}
	
	int modpow(int n, long a, int mod){
		long res = 1;
		while(a > 0){
			if((a&1)==1) res = (res*n)%mod;
			n = (int)(((long)n*n)%mod);
			a >>= 1;
		}
		return (int)res;
	}
	
	final long[][] f = {{0, 1}};
	final long[][] a = {
			{0, 1},
			{1, 1}
	};
	long modfib(long n, long mod, long[][] f, long[][] a){
		n--;
		while(n>0){
			if((n&1)==1){
				f = mult(f, a, mod);
			}
			a = mult(a, a, mod);
			n >>= 1;
		}
		return f[0][1];
	}
	
	long[][] mult(long[][] a, long[][] b, long mod){
		long[][] res = new long[a.length][b[0].length];
		for(int i=0; i<a.length; i++){
			for(int k=0; k<a[0].length; k++){
				for(int j=0; j<b[0].length; j++){
					res[i][j] = (res[i][j]+a[i][k]*b[k][j])%mod;
				}
			}
		}
		return res;
	}
	
	long gcd(long a, long b){
		return b==0?a:gcd(b, a%b);
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