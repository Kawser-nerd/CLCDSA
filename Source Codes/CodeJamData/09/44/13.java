import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class D {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("D-small.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("D-small.out"));
		
		
		int cases = Integer.parseInt(br.readLine());
		
		for (int itr = 1; itr <= cases; itr++) {
			int flowers = Integer.parseInt(br.readLine());
			int[] x = new int [flowers];
			int[] y = new int [flowers];
			int[] r = new int [flowers];
			for (int i = 0; i < flowers; i++) {
				String[] sp = br.readLine().split(" ");
				x[i] = Integer.parseInt(sp[0]);
				y[i] = Integer.parseInt(sp[1]);
				r[i] = Integer.parseInt(sp[2]);
			}
			
			double out = 0;
			if (flowers < 3)
				out = Math.max(r[0], r[flowers-1]);
			else {
				//flowers == 3
				out = 1e100;
				for (int i = 0; i < flowers; i++) {
					int j = (i == 0) ? 1 : 0;
					int k = (i == 2) ? 1 : 2;
					double d = Math.sqrt((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]));
					out = Math.min(out, Math.max(r[i], (d+r[j]+r[k])/2));
				}
			}
			ps.println("Case #" + itr + ": " + out);
		}
		
		br.close();
		ps.close();
	}

}
