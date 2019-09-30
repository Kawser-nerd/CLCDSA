import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {
	static ContestScanner in;
	static Writer out;
	public static void main(String[] args) {
		try {
			in = new ContestScanner();
			out = new Writer();
			new Main().solve();
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	void solve() throws IOException {
		int n = in.nextInt();
		tree = new List[n];
		for(int i = 0; i < n; i++) tree[i] = new ArrayList<>();
		for(int i = 0; i < n - 1; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			tree[a].add(b);
			tree[b].add(a);
		}
		int root = -1;
		for(int i = 0; i < n; i++) {
			if(tree[i].size() == 1) {
				root = i;
				break;
			}
		}
		System.out.println(dfs(root, -1) > 0 ? "First" : "Second");
		
	}
	
	List<Integer>[] tree;
	int dfs(int cur, int par) {
		int cnt = 0;
		for(int v: tree[cur]) {
			if(v == par) continue;
			cnt += dfs(v, cur);
		}
		return cnt > 1 ? cnt : (cnt ^ 1);
	}
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