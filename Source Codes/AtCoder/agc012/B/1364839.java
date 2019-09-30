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
import java.util.HashMap;
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
		int m = in.nextInt();
		Data[][] frame = new Data[n][11];
		Data[][] frameIn = new Data[n][11];
		List<Integer>[] node = new List[n];
		for(int i = 0; i < n; i++) node[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			node[a].add(b);
			node[b].add(a);
		}
		int q = in.nextInt();
		int[] maxT = new int[n];
		Arrays.fill(maxT, -1);
		int[] maxC = new int[n];
		for(int i = 0; i < q; i++) {
			int v = in.nextInt() - 1;
			int d = in.nextInt();
			int c = in.nextInt();
			frameIn[v][d] = new Data(c, i);
		}
		for(int t = 0; t < 10; t++) {
			for(int i = 0; i < n; i++) {
				// move Data from frameIn to frame
				for(int j = 0; j <= 10; j++) {
					if(frameIn[i][j] == null) continue;
					Data d = frameIn[i][j];
					frameIn[i][j] = null;
					if(d.time > maxT[i]) {
						maxT[i] = d.time;
						maxC[i] = d.col;
					}
					if(frame[i][j] == null || frame[i][j].time < d.time) {
						frame[i][j] = d;
					}
				}
				
				// update network
				for(int v: node[i]) {
					for(int j = 1; j <= 10; j++) {
						if(frame[i][j] == null
								|| frameIn[v][j - 1] != null
								&& frameIn[v][j - 1].time >= frame[i][j].time)
							continue;
						frameIn[v][j - 1] = frame[i][j];
					}
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			out.println(maxC[i]);
		}
	}
}

class Data {
	int col, time;
	Data(int col, int time) {
		this.col = col;
		this.time = time;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.