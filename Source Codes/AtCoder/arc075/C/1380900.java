import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class Main {
	static ContestScanner in;
	static Writer out;
	public static void main(String[] args) {
		Main main = new Main();
		try {
			in = new ContestScanner();
			out = new Writer();
			main.solve();
			out.close();
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	void solve() throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		long[] a = new long[n + 1];
		Pair[] pair = new Pair[n + 1];
		pair[0] = new Pair(0, 0);
		for(int i = 1; i <= n; i++) {
			a[i] = in.nextLong() - k;
			a[i] += a[i - 1];
			pair[i] = new Pair(a[i], i);
		}
		Arrays.sort(pair);
		BIT bit = new BIT(n + 1);
		long ans = 0;
		for(Pair p: pair) {
			ans += bit.sum((int)p.b);
			bit.add((int)p.b, 1);
		}
		System.out.println(ans);
	}
}

class Pair implements Comparable<Pair> {
	long a, b;
	Pair(long a, long b) {
		this.a = a;
		this.b = b;
	}
	@Override
	public int compareTo(Pair o) {
		if(a != o.a) return Long.compare(a, o.a);
		return Long.compare(b, o.b);
	}
}


class BIT{
	int n;
	int[] bit;
	public BIT(int n){
		this.n = n;
		bit = new int[n+1];
	}
	
	void add(int idx, int val){
		for(int i=idx+1; i<=n; i+=i&(-i)) bit[i-1] += val;
	}
	
	int sum(int idx){
		int res = 0;
		for(int i=idx+1; i>0; i-=i&(-i)) res += bit[i-1];
		return res;
	}
	
	int sum(int begin, int end){
		if(begin == 0) return sum(end);
		return sum(end)-sum(begin-1);
	}
}


@SuppressWarnings("serial")
class MultiSet<T> extends HashMap<T, Integer>{
	@Override public Integer get(Object key){return containsKey(key)?super.get(key):0;}
	public void add(T key,int v){put(key,get(key)+v);}
	public void add(T key){put(key,get(key)+1);}
	public void sub(T key){final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
	public MultiSet<T> merge(MultiSet<T> set)
	{MultiSet<T>s,l;if(this.size()<set.size()){s=this;l=set;}else{s=set;l=this;}
	for(Entry<T,Integer>e:s.entrySet())l.add(e.getKey(),e.getValue());return l;}
}

class Writer extends PrintWriter{
	public Writer(String filename)throws IOException
	{super(new BufferedWriter(new FileWriter(filename)));}
	public Writer()throws IOException{super(System.out);}
}
class ContestScanner implements Closeable{
	private BufferedReader in;private int c=-2;
	public ContestScanner()throws IOException 
	{in=new BufferedReader(new InputStreamReader(System.in));}
	public ContestScanner(String filename)throws IOException
	{in=new BufferedReader(new InputStreamReader(new FileInputStream(filename)));}
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
	public void close() throws IOException {in.close();}
}