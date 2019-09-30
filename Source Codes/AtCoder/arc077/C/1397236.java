import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.Random;

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
		int m = in.nextInt();
		int[] a = new int[n];
		LazySegTree st = new LazySegTree(m * 2 + 2);
		long sum = 0;
		for(int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
			if(i > 0) {
				if(a[i - 1] < a[i]) {
					sum += a[i] - a[i - 1];
					st.add(a[i - 1] + 2, a[i], 1);
					if(a[i - 1] + 2 - a[i] - 1 < 0)
						st.add(a[i] + 1, a[i] + 1, a[i - 1] + 2 - a[i] - 1);
				} else {
					sum += a[i] + m - a[i - 1];
					st.add(a[i - 1] + 2, a[i] + m, 1);
					if(-(a[i] + m - a[i - 1] - 2) - 1 < 0)
						st.add(a[i] + m + 1, a[i] + m + 1, -(a[i] + m - a[i - 1] - 2) - 1);
				}
			}
		}
		long ans = 0;
		for(int i = 0; i < m; i++) {
			ans = Math.max(ans, st.sum(0, i) + st.sum(0, i + m));
		}
		System.out.println(sum - ans);
	}
}

class LazySegTree{
	// benchmark: (n=10^5, q=2*10^5) * 100try --- 13772ms ( 137ms/try)
	//			: (n=10^6, q=2*10^6) * 10try  --- 18512ms (1851ms/try)
	long[] value;
	long[] hold;
	int length, n, bits;
	public LazySegTree(int n) {
		for(length=1; length<n; length<<=1) bits++;
		length <<= 1;
		value = new long[length];
		hold = new long[length];
	}
	long get(int idx){
		return value[length>>1|idx];
	}
	void add(int l, int r, int v){ // r: inclusive
		add(l, r, v, bits, 0);
	}
	private void add(int l, int r, int v, int shift, int idx){
		if(r<l) return;
		final int index = idx|1<<bits-shift;
		if(r-l+1<(1<<shift)){
			final int nidx = idx<<1|1;
			add(l, Math.min(r, (nidx<<shift-1)-1), v, shift-1, nidx-1);
			add(Math.max(l, nidx<<shift-1), r, v, shift-1, nidx);
			value[index] = value[index<<1] + value[index<<1|1] + hold[index] * (1<<shift);
		}else{
			value[index] += v*(1<<shift);
			hold[index] += v;
		}
	}
	long sum(int l, int r){
		return sum(l, r, bits, 0, 0);
	}
	private long sum(int l, int r, int shift, int idx, long add){
		final int index = idx|1<<bits-shift;
		if(r<l){
			hold[index] += add;
			value[index] += add*(1<<shift);
			return 0;
		}
		value[index] += add*(1<<shift);
		if(r-l+1<(1<<shift)){
			final int nidx = idx<<1|1;
			final long next = hold[index]+add;
			hold[index] = 0;
			return sum(l, Math.min(r, (nidx<<shift-1)-1), shift-1, nidx-1, next)
					+ sum(Math.max(l, nidx<<shift-1), r, shift-1, nidx, next);
		}else{
			hold[index] += add;
			return value[index];
		}
	}
	void flat(){
		flat(1, length>>1, 0);
	}
	private void flat(int idx, int len, long add){
		value[idx] += add*len;
		final long next = add+hold[idx];
		if((idx<<1)>=length) return;
		hold[idx] = 0;
		flat(idx<<1, len>>1, next);
		flat(idx<<1|1, len>>1, next);
	}
	public String toString() {
		StringBuilder sb = new StringBuilder();
		int s = 1;
		for(int e=2; e<=length; e<<=1){
			for(;s<e; s++){
				sb.append(hold[s]+":"+value[s]+"\t");
			}sb.append("\n");
		}return sb.toString();
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