package round2;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round2/D-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/round2/D-small-1.in"), new FileOutputStream("src/round2/D-small-1.out"));
//		io = new Kattio(new FileInputStream("src/round2/D-large-0.in"), new FileOutputStream("src/round2/D-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new D().solve(io);
		}
		io.close();
	}

	List<List<Integer>> edges;

	int countBits(long mask) {
		int cnt = 0;
		while (mask > 0) {
			cnt++;
			mask &= (mask - 1);
		}
		return cnt;
	}

	private void solve(Kattio io) {
		int N = io.getInt(), M = io.getInt();
		edges = new ArrayList<List<Integer>>();
		for (int i = 0; i < N; i++) {
		    edges.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < M; i++) {
			String word = io.getWord();
			String[] split = word.split(",");
			int x = Integer.parseInt(split[0]), y = Integer.parseInt(split[1]);
			edges.get(x).add(y);
			edges.get(y).add(x);
		}
		int[] dist = new int[N], threatCount = new int[N];
		boolean[] done = new boolean[N];
		long[] threatMask = new long[N], accThreatMask = new long[N];
		for (int i = 0; i < N; i++) {
		    dist[i] = Integer.MAX_VALUE;
			Collections.sort(edges.get(i));
			for (Integer t : edges.get(i)) {
				threatMask[i] |= (1L << t);
			}
		}
		threatMask[0] |= 1;
		threatMask[1] = 0;
		int[][] shared = new int[N][N];
		for (int i = 0; i < N; i++) {
		    for (int j = 0; j < N; j++) {
		   		int a = 0, b = 0;
				while (a < edges.get(i).size() && b < edges.get(j).size()) {
					int dif = edges.get(i).get(a) - edges.get(j).get(b);
					if (dif == 0) {
						shared[i][j]++;
						a++;
						b++;
					} else if (dif < 0) {
						a++;
					} else {
						b++;
					}
				}
		    }
		}


		dist[0] = 0;
		accThreatMask[0] = threatMask[0];
		threatCount[0] = countBits(accThreatMask[0]);

		while (!done[1]) {
			int best = Integer.MAX_VALUE, most = 0, selected = -1;
			for (int i = 0; i < N; i++) {
			    if (done[i]) continue;
				if (dist[i] < best || (dist[i] == best && threatCount[i] > most)) {
					best = dist[i];
					most = threatCount[i];
					selected = i;
				}
			}
			done[selected] = true;
			for (int t : edges.get(selected)) {
				long newThreatMask = accThreatMask[selected] | threatMask[t];
				int newThreatsCount = countBits(newThreatMask);
				if (best + 1 < dist[t]) {
					dist[t] = best + 1;
					accThreatMask[t] = newThreatMask;
					threatCount[t] = newThreatsCount;
				} else if (best + 1 == dist[t]) {
					if (newThreatsCount > threatCount[t]) {
						accThreatMask[t] = newThreatMask;
						threatCount[t] = newThreatsCount;
					}
				}
			}
		}

		int pathLen = dist[1];
		int threats = countBits(accThreatMask[1]) - pathLen;
		io.println((pathLen - 1) + " " + threats);
	}
}
