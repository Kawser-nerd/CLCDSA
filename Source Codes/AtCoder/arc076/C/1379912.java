import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
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
	List<Pair> list = new ArrayList<>();
	void solve() throws IOException {
		int r = in.nextInt();
		int c = in.nextInt();
		int n = in.nextInt();
		h = c;
		w = r;
		for(int i = 0; i < n; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			if(!onEdge(x1, y1) || !onEdge(x2, y2)) continue;
			int p1 = id(x1, y1);
			int p2 = id(x2, y2);
			list.add(new Pair(i, p1));
			list.add(new Pair(i, p2));
		}
		Collections.sort(list);
		int[] st = new int[list.size()];
		int sp = 0;
		for(Pair p: list) {
			if(sp == 0 || st[sp - 1] != p.id) {
				st[sp++] = p.id;
			} else {
				sp--;
			}
		}
		if(sp == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
	
	int h, w;
	boolean onEdge(int x, int y) {
		return x == 0 || x == w || y == 0 || y == h;
	}
	
	int id(int x, int y) {
		if(x == 0) {
			return y;
		} else if(y == h) {
			return h + x;
		} else if(x == w) {
			return h + w + h - y;
		} else {
			return h * 2 + w * 2 - x;
		}
	}
}

class Pair implements Comparable<Pair> {
	int id, p;
	public Pair(int id, int p) {
		this.id = id;
		this.p = p;
	}
	
	@Override
	public int compareTo(Pair o) {
		return p - o.p;
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