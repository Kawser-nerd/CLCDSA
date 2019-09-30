import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class C implements Runnable {
	BufferedReader in;
	BufferedWriter out;

	public void solve() throws Exception {
		HashMap<Integer, Integer> cur = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> next = new HashMap<Integer, Integer>();
		int n = Integer.parseInt(readword());
		ArrayList<Integer> coordsCur = new ArrayList<Integer>();
		ArrayList<Integer> coordsNext = new ArrayList<Integer>();
		for( int i = 0; i < n; i++ ) {
			int coord = Integer.parseInt(readword());
			int count = Integer.parseInt(readword());
			coordsCur.add(coord);
			cur.put(coord, count);
		}
		long result = 0;
		coordsNext.clear();
		next.clear();
		while( true ) {
			boolean isEnd = true;
			for( int i = 0; i < coordsCur.size(); i++ ) {
				int x = coordsCur.get(i);
				int y = cur.get(coordsCur.get(i));
				if( y >= 2 ) {
					isEnd = false;
					if( !next.containsKey(x-1)) {
						next.put(x-1, 0);
						coordsNext.add(x-1);
					}
					next.put(x-1,next.get(x-1) + y / 2);
					if( !next.containsKey(x+1)) {
						next.put(x+1, 0);
						coordsNext.add(x+1);
					}
					next.put(x+1,next.get(x+1) + y / 2);
				}
				if( y % 2 != 0 ) {
					if( !next.containsKey(x)) {
						next.put(x,0);
						coordsNext.add(x);
					}
					next.put(x,next.get(x) + 1);
				}
				result += y / 2;
			}
			if( isEnd ) break;
			coordsCur = coordsNext;
			cur = next;
			coordsNext = new ArrayList<Integer>();
			next = new HashMap<Integer, Integer>();
		}
		out.write(result + "\n");
	}

	public String readword() throws IOException {
		int c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		StringBuilder bld = new StringBuilder();
		while (c > ' ') {
			bld.append((char) c);
			c = in.read();
		}
		return bld.toString();
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(this.getClass().getName()
					+ ".in"));
			out = new BufferedWriter(new FileWriter(this.getClass().getName()
					+ ".out"));
			int tn = Integer.parseInt(readword());
			for (int i = 0; i < tn; i++) {
				out.write("Case #" + (i + 1) + ": ");
				solve();
			}
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		new Thread(new C()).start();
	}
}
