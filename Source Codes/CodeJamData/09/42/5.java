import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

class Line {
	boolean[] b;
 	
	public Line(String s) {
		b = new boolean[s.length()];
		for (int i = 0; i < s.length(); i++) b[i] = (s.charAt(i) == '#');
	}
 	
	public Line(int n) {
		b = new boolean[n];
	}
	
	public int hashCode() {
		int hash = 0;
		for (int i = 0; i < b.length; i++) {
			hash *= 2;
			if (b[i]) hash += 1;
		}
		
		return hash;
	}
	
	public Line clone() {
		Line line = new Line(b.length);
		
		for (int i = 0; i < b.length; i++) line.b[i] = b[i];
		
		return line;
	}
}

public class B {
	static int infi = Integer.MAX_VALUE/2;
	int r,c,f;
	String[] a;
	
	int[][][][] d;
	
	public int calc(int i, int j, Line cur, Line pod) {
		if (i == r-1) {
			return 0;
		}
		
		int h1 = cur.hashCode(), h2 = pod.hashCode();
		
		//System.out.println(i+" "+j+" "+h1+" "+h2+" "+Arrays.toString(pod.b));
		if (d[i][j][h1][h2] == -1) {
			d[i][j][h1][h2] = infi;
			
			// variants
			int ans = infi;
			
			if (!pod.b[j]) {
				//count how many padat'
				int count = 1;
				while ((i+count+1 < r) && (a[i+count+1].charAt(j) == '.')) count++;
				if (count <= f) {
					if (i+count+1 >= r) {
						ans = 0;
					} else {
					
					if (count == 1) {
						ans = calc(i+1, j, pod, new Line(a[i+2]));
					} else {
						ans = calc(i+count, j, new Line(a[i+count]), new Line(a[i+count+1]));
					}
					
					}
				}
			} else {
			// kopat' sleva
			if ((j != 0) && (pod.b[j-1]) && (!cur.b[j-1])) {
				Line line = pod.clone();
				line.b[j-1] = false;
				
				ans = Math.min(ans, calc(i,j,cur,line)+1);
			}
			// kopat' sprava
			if ((j != c-1) && (pod.b[j+1]) && (!cur.b[j+1])) {
				Line line = pod.clone();
				line.b[j+1] = false;
				
				ans = Math.min(ans, calc(i,j,cur,line)+1);
			}
			// idti vlevo
			if ((j != 0) && (!cur.b[j-1])) {
				ans = Math.min(ans, calc(i,j-1,cur,pod));
			}
			//idti vpravo
			if ((j != c-1) && (!cur.b[j+1])) {
				ans = Math.min(ans, calc(i,j+1,cur,pod));
			}
			}
			
			d[i][j][h1][h2] = ans;
		}
		
		return d[i][j][h1][h2];
	}
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
			
		int t = input.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			r = input.nextInt();
			c = input.nextInt();
			f = input.nextInt();
			
			a = new String[r];
			int max = 256;
			
			d = new int[r][c][max][max];
			for (int i = 0; i < r; i++)
				for (int i2 = 0; i2 < c; i2++) 
					for (int i3 = 0; i3 < max; i3++)
						for (int i4 = 0; i4 < max; i4++) d[i][i2][i3][i4] = -1;
			
			input.nextLine();
			for (int i = 0; i < r; i++) {
				a[i] = input.nextLine();
			}
			
			int ans = calc(0,0,new Line(a[0]), new Line(a[1]));
			
			output.print("Case #"+(tt+1)+": ");
			
			if (ans == infi) {
				output.println("No");
			} else {
				output.println("Yes "+ans);
			}	
		}
		
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new B()).run();
	}
}