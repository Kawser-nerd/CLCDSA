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
		out.print("Case #"+test+": ");
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i=0; i<n; i++) a[i] = nextInt();
		for (int i=0; i<n; i++) b[i] = nextInt();
		Arrays.sort(a);
		Arrays.sort(b);
		long res = 0;
		for (int i=0; i<n; i++) res += 1l*a[i]*b[n-1-i];
		out.println(res);	
	}
	
}      
} 



















