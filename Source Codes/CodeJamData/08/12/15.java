import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class Solution implements Runnable {
	private static final String INPUT_FILE_NAME = "b.big.in.txt";
	private static final String OUTPUT_FILE_NAME = "b.big.out.txt";
	
	private BufferedReader rd;
	private PrintWriter wr;

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	void solve() throws IOException {
		rd = new BufferedReader(new FileReader(Solution.INPUT_FILE_NAME));
		wr = new PrintWriter(Solution.OUTPUT_FILE_NAME);
		
		String line = rd.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int nn = Integer.parseInt(st.nextToken());
		for (int ii = 0; ii < nn; ++ii) {
			subSolve(ii);
		}
		
		rd.close();
		wr.close();
	}

	private void subSolve(int ii) throws IOException {
		String line = rd.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int n = Integer.parseInt(st.nextToken());
		
		line = rd.readLine();
		st = new StringTokenizer(line);
		int m = Integer.parseInt(st.nextToken());
		
		TreeSet<Integer> wantMalted[] = new TreeSet[m]; 
		TreeSet<Integer> wantUnmalted[] = new TreeSet[m];
		boolean[] satisfied = new boolean[m];
		for (int i = 0; i < m; ++i) {
			satisfied[i] = false;
		}
		
		boolean[] malted = new boolean[n];
		for (int i = 0; i < n; ++i) {
			malted[i] = false;
		}
		
		for (int i = 0; i < m; ++i) {
			wantMalted[i] = new TreeSet<Integer>();
			wantUnmalted[i] = new TreeSet<Integer>();
		}
		
		for (int i = 0; i < m; ++i) {
			line = rd.readLine();
			st = new StringTokenizer(line);
			int t = Integer.parseInt(st.nextToken());
			
			for (int j = 0; j < t; ++j) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
			
				if (y == 0) {
					wantUnmalted[i].add(x - 1);
				} else {
					wantMalted[i].add(x - 1);
				}
			}
		}

		boolean wasChanges = true;
		while (wasChanges) {
			wasChanges = false;
			for (int i = 0; i < m; ++i) {
				if (satisfied[i]) {
					continue;
				}
					
				if ((wantMalted[i].size() > 0) && (wantUnmalted[i].size() == 0)) {
					int maltedIndex = wantMalted[i].first();
					malted[maltedIndex] = true;
					satisfied[i] = true;
					
					wasChanges = true;
					
					for (int j = 0; j < m; ++j) {
						if (satisfied[j]) {
							continue;
						}
						
						if (wantMalted[j].contains(maltedIndex)) {
							satisfied[j] = true;
						} else {
							wantUnmalted[j].remove(maltedIndex);
						}
					}
				} else if ((wantMalted[i].size() == 0) && (wantUnmalted[i].size() == 0)) {
					wr.println(String.format("Case #%d: IMPOSSIBLE", ii + 1));
					return;
				}
			}
		}
		
		for (int i = 0; i < m; ++i) {
			if (satisfied[i]) {
				continue;
			}
			if ((wantMalted[i].size() == 0) && (wantUnmalted[i].size() == 0)) {
				wr.println(String.format("Case #%d: IMPOSSIBLE", ii + 1));
				return;
			}
		}
		
		
		wr.print(String.format("Case #%d:", ii + 1));
		for (int i = 0; i < n; ++i) {
			if (malted[i]) {
				wr.print(" 1");
			} else {
				wr.print(" 0");
			}
		}
		wr.println();
	}
}
