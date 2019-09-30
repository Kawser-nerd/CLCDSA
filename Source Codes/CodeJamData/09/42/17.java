import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.UUID;


public class ADiggingProblem {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line = reader.readLine();
		int N = Integer.parseInt(line);
		for (int i=1; i<=N; i++) {
			int R,C,F;
			line = reader.readLine();
			StringTokenizer tok = new StringTokenizer(line);
			R = Integer.parseInt(tok.nextToken());
			C = Integer.parseInt(tok.nextToken());
			F = Integer.parseInt(tok.nextToken());
			SortedSet<State> queue = new TreeSet<State>();
			State original = new State();
			original.diggings=0;
			original.col=0;
			original.cave = new char[R][];
			for (int j=0; j < R; j++) {
				line = reader.readLine();
				original.cave[j] = line.toCharArray();
			}
			queue.add(original);
			int diggings = -1;
			while (diggings < 0 && !queue.isEmpty()) {
				State curr = queue.first();
				queue.remove(curr);
				for (int j=1; diggings < 0 && curr.col+j < C; j++) {
					if (curr.cave[0][curr.col+j]=='#') break;
					if (curr.cave[1][curr.col+j]=='.') {
						int k;
						for (k=1; k<curr.cave.length && curr.cave[k][curr.col+j]=='.';k++);
						if (k<=F+1) {
							if (k==curr.cave.length) {
								diggings = curr.diggings;
							}
							else {
								State newState = new State();
								newState.cave = new char[curr.cave.length-k+1][];
								System.arraycopy(curr.cave, k-1, newState.cave, 0, curr.cave.length-k+1);
								newState.col = curr.col+j;
								newState.diggings = curr.diggings;
								queue.add(newState);
							}
						}
						break;
					}
					else {
						if (curr.col+j+1 < C && curr.cave[0][curr.col+j+1]=='.' && curr.cave[1][curr.col+j+1]=='#') {
							State newState = new State();
							newState.cave = new char[curr.cave.length][C];
							for (int k=0; k< curr.cave.length; k++) {
								System.arraycopy(curr.cave[k], 0, newState.cave[k], 0, C);
							}
							newState.cave[1][curr.col+j+1]='.';
							newState.col = curr.col+j;
							newState.diggings = curr.diggings+1;
							queue.add(newState);
						}
						if (curr.cave[0][curr.col+j-1]=='.' && curr.cave[1][curr.col+j-1]=='#') {
							State newState = new State();
							newState.cave = new char[curr.cave.length][C];
							for (int k=0; k< curr.cave.length; k++) {
								System.arraycopy(curr.cave[k], 0, newState.cave[k], 0, C);
							}
							newState.cave[1][curr.col+j-1]='.';
							newState.col = curr.col+j;
							newState.diggings = curr.diggings+1;
							queue.add(newState);
						}
					}
				}
				for (int j=0; diggings < 0 && curr.col+j >= 0; j--) {
					if (curr.cave[0][curr.col+j]=='#') break;
					if (curr.cave[1][curr.col+j]=='.') {
						int k;
						for (k=1; k<curr.cave.length && curr.cave[k][curr.col+j]=='.';k++);
						if (k<=F+1) {
							if (k==curr.cave.length) {
								diggings = curr.diggings;
							}
							else {
								State newState = new State();
								newState.cave = new char[curr.cave.length-k+1][];
								System.arraycopy(curr.cave, k-1, newState.cave, 0, curr.cave.length-k+1);
								newState.col = curr.col+j;
								newState.diggings = curr.diggings;
								queue.add(newState);
							}
						}
						break;
					}
					else {
						if (curr.col+j+1 < C && curr.cave[0][curr.col+j+1]=='.' && curr.cave[1][curr.col+j+1]=='#') {
							State newState = new State();
							newState.cave = new char[curr.cave.length][C];
							for (int k=0; k< curr.cave.length; k++) {
								System.arraycopy(curr.cave[k], 0, newState.cave[k], 0, C);
							}
							newState.cave[1][curr.col+j+1]='.';
							newState.col = curr.col+j;
							newState.diggings = curr.diggings+1;
							queue.add(newState);
						}
						if (curr.col+j-1 >= 0 && curr.cave[0][curr.col+j-1]=='.' && curr.cave[1][curr.col+j-1]=='#') {
							State newState = new State();
							newState.cave = new char[curr.cave.length][C];
							for (int k=0; k< curr.cave.length; k++) {
								System.arraycopy(curr.cave[k], 0, newState.cave[k], 0, C);
							}
							newState.cave[1][curr.col+j-1]='.';
							newState.col = curr.col+j;
							newState.diggings = curr.diggings+1;
							queue.add(newState);
						}
					}
				}
			}
			if (diggings == -1) {
				System.out.printf("Case #%d: No\n", i);
			}
			else {
				System.out.printf("Case #%d: Yes %d\n", i, diggings);
			}
		}
	}

	private static class State implements Comparable<State> {
		final UUID id = UUID.randomUUID();
		char[][] cave;
		int col;
		int diggings;
		
		public int compareTo(State o) {
			if (this.diggings==o.diggings) {
				return this.id.compareTo(o.id);
			}
			return this.diggings-o.diggings;
		}
	}
}
