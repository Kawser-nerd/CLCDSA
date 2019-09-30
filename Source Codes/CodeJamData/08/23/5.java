import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;

	public class Tree {
		int tr[];
		int osn;
		Tree(int osn) {
			this.osn = osn;
			tr = new int[osn*2];
		}
		void update(int v, int dx) {
			v += osn;
			tr[v] += dx;
			while( v != 1) {
				v = v / 2;
				tr[v] = tr[v*2] + tr[v*2+1];
			}
		}
		int query(int stPos, int need ) {
			stPos += osn;
			while (true) {
				if( tr[stPos] >= need ) {
					break;
				} else {
					if( stPos % 2 == 1 ) {
						need -= tr[stPos];
					}
					stPos = (stPos + 1) / 2;
				}
			}
			
			while( stPos < osn ) {
				if( tr[stPos*2] >= need ) {
					stPos = stPos*2;
				} else {
					need -= tr[stPos*2];
					stPos = stPos*2+1;
				}
			}
			return stPos - osn;
		}
	}
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c < ' ' ) c = in.read();
		if (c < 0) return "";
		StringBuilder builder = new StringBuilder();
		while (c > ' ') {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	public void solve() throws Exception {
		Tree tr = new Tree( 1<<21 );
		int k = Integer.parseInt(readword());
		int res[] = new int[k];
		for(int i = 0; i < 2*k; i++) {
			tr.update(i,1);
		}
		
		int curPos = 0;
		for(int i = 0; i < k; i++) {
			res[curPos] = i;
			tr.update(curPos, -1);
			tr.update(curPos + k, -1);
			if( i == k-1) break;
			int need = (i+2)%(k-i-1);
			if(need == 0) need = k-i-1;
			int nextPos = tr.query(curPos,need);
			if( nextPos >= k ) nextPos -= k;
			curPos = nextPos;
		}
		int n = Integer.parseInt(readword());
		for(int i = 0; i < n; i++) {
			int tt = Integer.parseInt(readword());
			out.write(" " + (res[tt-1] + 1));
		}
		out.write("\n");
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
			int n = Integer.parseInt(readword());
			for(int i = 0; i < n; i++) {
				out.write("Case #" + (i+1) +":");
				solve();
			}
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

}
