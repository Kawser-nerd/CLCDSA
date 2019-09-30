import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.Properties;

/**
 * Works good for CF
 * @author cykeltillsalu
 */
public class GCJ {

	//some local config
	static boolean test = true;
	static String testDataFile = "A-large.in";
	static String feedFile = "feed.txt";
	CompetitionType type = CompetitionType.CF;
	private static String ENDL = "\n";

	// solution
	private void solve() throws Throwable {
		out = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + "-res.txt")); 
		int n = iread();
		for (int i = 0; i < n; i++) {
			solveIt(i+1, out);
		}
		out.flush();
	}

	private void solveIt(int i, BufferedWriter out) throws Throwable {
		
		int cnt = Integer.MAX_VALUE;
		
		long a = lread();
		int n = iread();
		int[] size = new int[n];
		for (int j = 0; j < size.length; j++) {
			size[j] = iread();
		}
		Arrays.sort(size);
		boolean fail = false;
		int curcost = 0;
		for (int j = 0; j < n; j++) {
			cnt = Math.min(curcost + n - j, cnt);
			if(a == 1){
				fail = true;
				break;
			}
			while(a <= size[j]){
				a += a - 1;
				curcost ++;
			}
			a += size[j];
		}
		if(!fail){
			cnt = Math.min(cnt, curcost);
		}
		
		String ans = "Case #" + i +": " + cnt;
		System.out.println(ans);
		out.write(ans + "\n");
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		
		if(test){ //run all cases from testfile:
			new GCJ().solve();
		}
		out.close();
	}

	public GCJ() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
		}
	}

	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	
	enum CompetitionType {CF, OTHER};
}