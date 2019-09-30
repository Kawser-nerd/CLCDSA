import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main implements Runnable {
	static ContestScanner in;
	static Writer out;
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 16 * 1024 * 1024).start();
	}
	
	public void run() {
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
//		debug();
//		N = 10;// for debug
		// 1?????????
		long ans = !next(10) ? oneDig() : sumDig();
		out.println("! " + ans);
		out.flush();
	}
	
	void debug() throws IOException {
		for(int i = 1; i <= 100000; i++) {
			N = i;
//			System.out.println("test: " + i);
			long ans = !next(10) ? oneDig() : sumDig();
//			out.println("! " + ans);
//			out.flush();
			if(ans != N) {
				System.err.println(N);
			}
		}
	}
	
	long inf = 1000000000;
	long sumDig() {
		// 1????????????
		long top = -1;
		for(int i = 1; i <= 9; i++) {
			if(!next(i)) {
				top = i - 1;
				break;
			}
		}
		if(top == -1) top = 9;
		int topD = (int) top;
		// ????
		for(int i = 0; i < 10; i++) {
			if(!next(top * 10)) break;
			top *= 10;
		}
		if(top > inf) {
			top = tail0(topD);
			if(top == 1) return 1;
		}
		
		long left = top;
		long right = left + (long)Math.pow(10, (int)Math.log10(left)) - 1;
		long ans = 0;
//		System.out.println(left + " " + right);
		while(left <= right) {
			long mid = (left + right) / 2;
			if(!next(mid * 10)) {
				ans = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if(ans == 0) ans = top;
		else ans++;
		return ans;
	}
	
	long tail0(long top) {
		if(top == 9) {
			for(int i = 0; i < 10; i++) {
				top *= 10;
				if(!next(top - 1)) break;
			}
			if(top > inf) return 1;
			return top / 10;
		} else {
			long oldTop = top;
			top++;
			for(int i = 0; i < 10; i++) {
				if(next(top * 10)) break;
				top *= 10;
				oldTop *= 10;
			}
			return oldTop * 10;
		}
	}
	
	int oneDig() {
		// 2 - 9 ???
		int top = -1;
		for(int i = 1; i <= 9; i++) {
			if(next(i * 10)) {
				top = i;
				break;
			}
		}
		return top;
	}
	
	int N = -1;
	boolean next(long n) {
		if(N > 0) {
			if(n <= N && Long.toString(n).compareTo("" + N) <= 0
					|| n > N && Long.toString(n).compareTo("" + N) > 0) return true;
			return false;
		}
		try {
			out.println("? " + n);
			out.flush();
			boolean ans = in.nextToken().equals("Y");
			return ans;
		} catch(IOException e) {
			e.printStackTrace();
		}
		return false;
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