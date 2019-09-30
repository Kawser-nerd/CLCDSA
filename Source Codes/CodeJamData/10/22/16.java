import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;
public class B  extends AbstractCodeJamSolver {
	
	int n,k,b,t;
	int[] x = new int[50];
	int[] v = new int[50];
	
	void input() {
		n = in.nextInt();
		k = in.nextInt();
		b = in.nextInt();
		t = in.nextInt();
		for(int i=0;i<n;i++)
			x[i] = in.nextInt();
		for(int i=0;i<n;i++)
			v[i] = in.nextInt();			
	}
	
	public void solve() {
		int casen = in.nextInt();
		for(int casei=1;casei<=casen;casei++) {
			input();
			
			int pass = 0;
			int nopass = 0;
			int swap = 0;
			for(int i=n-1;i>=0 && pass < k;i--) {
				if(v[i]*t >= b - x[i]) {
					pass++;
					swap += nopass;
				} else {
					nopass++;				
				}			
			}
			out.print("Case #" + casei + ": ");
			if(pass >= k) {
				out.println(swap);				
			} else {
				out.println("IMPOSSIBLE");
			}
		}		
	}
	
	static public void main(String[] args) throws IOException {
		new B().launch("B.txt");
	}
}
abstract class AbstractCodeJamSolver {
	
	protected Scanner in;
	protected PrintStream out = System.out;

	abstract public void solve(); 
	
	protected void print(Object o) {
		out.print(o);
	}
	
	protected void println() {
		out.println();
	}
	
	protected void println(Object o) {
		out.println(o);
	}
	
	protected void printf(String f, Object... o) {
		out.format(f, o);
	}


	final public void launch(String inputFileName) throws FileNotFoundException {
		in = new Scanner(new File(inputFileName));
		solve();
	}
}

