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
	BigDecimal d = BigDecimal.valueOf(5);
	BigDecimal l = BigDecimal.valueOf(2);
	BigDecimal r = BigDecimal.valueOf(3);
	BigDecimal e = BigDecimal.valueOf(1);
	e = e.divide(BigDecimal.TEN.pow(100));
	
	while (r.subtract(l).compareTo(e)>0) {
		BigDecimal m = l.add(r).divide(BigDecimal.valueOf(2));
		if (m.multiply(m).compareTo(d)>0) r = m; else l = m;
	}
	//out.print(r);
	r = r.add(BigDecimal.valueOf(3));
	
	int tests = nextInt();
	for (int test=1; test<=tests; test++) {
		out.print("Case #"+test+": ");
		BigDecimal x = r.pow(nextInt());
		//out.println(x);
		String s = x.toString();
		s = "0"+s.substring(0,s.indexOf('.'));
		out.println(s.substring(s.length()-3,s.length()));		
	
	}
	
}      
} 



















