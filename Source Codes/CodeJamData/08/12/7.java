import java.io.*;         
import java.util.*;         
import java.math.*;         
        
public class Main implements Runnable  {   

	
	
StreamTokenizer ST;      
PrintWriter out;      
BufferedReader br;   
Scanner in;   
String FileName = "test";   
int inf = 1000000000;   

int nextInt() throws IOException{      
    ST.nextToken();      
    return (int)ST.nval;      
}      
String next() throws IOException{      
    ST.nextToken();      
    return ST.sval;      
}      
double nextD() throws IOException{      
    ST.nextToken();      
    return ST.nval;      
}      
public static void main(String[] args) throws IOException {       
    new Thread(new Main()).start();      
}      
public void run()  {      
    try {      
        out = new PrintWriter(new BufferedWriter(new FileWriter(new File("output.txt"))));      
        br = new BufferedReader(new FileReader("input.txt"));      
        in = new Scanner(br);   
        ST = new StreamTokenizer(br);      
        solve();      
        out.close();              
    }         
    catch (IOException e) {        
    throw new IllegalStateException(e);       
    }      
}      

public void solve() throws IOException {
	int tests = nextInt();
	for (int test=1; test<=tests; test++) {
		out.print("Case #"+test+":");
		int m = nextInt();
		int n = nextInt();		
		int[] fav = new int[n];
		boolean[] res = new boolean[m];
		Arrays.fill(fav, -1);
		boolean[][] a = new boolean[n][m];
		TreeSet<Integer>[] t = new TreeSet[n];
		for (int i=0; i<n; i++) t[i] = new TreeSet<Integer>();
		for (int i=0; i<n; i++) {
			int k = nextInt();
			while (k-->0) {
				int x = nextInt()-1;
				int tp = nextInt();
				if (tp==1) {
					fav[i] = x;
				} else {
					a[i][x] = true;
					t[i].add(x);					
				}
			}
		}
		
					
		boolean[] f = new boolean[n];
		boolean ok = true;
		for (int st=0; st<=n; st++) {
			int add = -1;
			for (int i=0; i<n; i++)
				if (!f[i] && t[i].size()==0) {
					if (fav[i]==-1) ok = false; else add = fav[i];
				}
			if (!ok) break;
			if (add<0) break;
			res[add] = true;
			for (int i=0; i<n; i++)
				if (!f[i])
					if (fav[i]==add) f[i] = true; else
						if (a[i][add]) t[i].remove(add);					
		}
		if (ok) {
			for (int i=0; i<m; i++)
				if (res[i]) out.print(" 1"); else out.print(" 0");
		} else out.print(" IMPOSSIBLE");
		out.println();
		
		
	
	}
	
}      
} 



















