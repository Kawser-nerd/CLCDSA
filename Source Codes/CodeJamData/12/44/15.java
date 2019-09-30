package d;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class D {
	static class Pos implements Comparable<Pos> {
		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}

		int x, y;
		
		@Override
		public int hashCode() {
			return 31 * x + y;
		}
		
		@Override
		public boolean equals(Object obj) {
			Pos other = (Pos) obj;
			return x == other.x && y == other.y;
		}

		@Override
		public int compareTo(Pos o) {
			if (x < o.x) return -1;
			if (x > o.x) return 1;
			if (y < o.y) return -1;
			if (y > o.y) return 1;
			return 0;
		}
	}
	
	static class State {
		State(Pos[] pos) {
			this.pos = pos;
		}
		
		Pos[] pos;
		
		@Override
		public int hashCode() {
			return Arrays.hashCode(pos);
		}
		
		@Override
		public boolean equals(Object obj) {
			return Arrays.equals(pos, ((State)obj).pos);
		}
	}

	static int determine(Pos cave, boolean[][] passable) {
		int h = passable.length;
		int w = passable[0].length;
		
		boolean[][] reachable = new boolean[h][w];
		
		ArrayDeque<Pos> q = new ArrayDeque<Pos>();
		ArrayList<Pos> all = new ArrayList<Pos>();
		q.add(cave);
		while (!q.isEmpty()) {
			Pos pos = q.removeFirst();
			if (reachable[pos.y][pos.x])
				continue;
			
			reachable[pos.y][pos.x] = true;
			all.add(pos);
			
			if (passable[pos.y - 1][pos.x]) q.add(new Pos(pos.x, pos.y - 1));
			if (passable[pos.y][pos.x - 1]) q.add(new Pos(pos.x - 1, pos.y));
			if (passable[pos.y][pos.x + 1]) q.add(new Pos(pos.x + 1, pos.y));
		}
		
		if (all.size() == 1)
			return 1;
		
		HashSet<State> seen = new HashSet<State>();
		ArrayDeque<Pos[]> qq = new ArrayDeque<Pos[]>();
		Pos[] initial = all.toArray(new Pos[all.size()]);
		Arrays.sort(initial);
		qq.add(initial);
		HashSet<Pos> newPos = new HashSet<Pos>();
		while (!qq.isEmpty()) {
			Pos[] now = qq.removeFirst();
			
			nextDir:
			for (int dir = -1; dir <= 1; dir++) {
				newPos.clear();
				
				for (Pos p : now) {
					int newX = p.x + dir;
					int newY = p.y + (dir == 0 ? 1 : 0);
					
					if (!passable[newY][newX]) {
						newX = p.x;
						newY = p.y;
					}
					
					if (!reachable[newY][newX])
						continue nextDir;
					
					newPos.add(new Pos(newX, newY));
				}
				
				Pos[] newPoss = newPos.toArray(new Pos[newPos.size()]);
				if (newPoss.length == 1 && cave.equals(newPoss[0]))
					return all.size();
				
				Arrays.sort(newPoss);
				if (!Arrays.equals(newPoss, now)) {
					if (seen.add(new State(newPoss)))
						qq.add(newPoss);
				}
			}
		}
		
		return -all.size();
	}
	
	static void go(LineNumberReader reader, Appendable writer) throws Exception {
		int nCases = Integer.parseInt(reader.readLine().trim());
		for (int c = 1; c <= nCases; c++) {
			String[] tmp = reader.readLine().trim().split(" ");
			int rows = Integer.parseInt(tmp[0]);
			int cols = Integer.parseInt(tmp[1]);
			
			Pos[] caves = new Pos[10];
			boolean[][] passable = new boolean[rows][cols];
			for (int y = 0; y < rows; y++) {
				String s = reader.readLine();
				for (int x = 0; x < cols; x++) {
					char cc = s.charAt(x);
					if (cc == '#') {
						passable[y][x] = false;
					} else {
						passable[y][x] = true;
						if (cc != '.') {
							caves[cc - '0'] =  new Pos(x, y);
						}
					}
				}
			}
			
			writer.append("Case #" + c + ":\n");
			for (int a = 0; a < 10; a++) {
				Pos cave = caves[a];
				if (cave == null)
					break;
				
				int res = determine(cave, passable);
				if (res > 0) {
					writer.append(a + ": " + res + " Lucky\n");
				} else {
					writer.append(a + ": " + (-res) + " Unlucky\n");
				}
			}
		}
	}
	
	static void process(File in, File out) throws Exception {
		LineNumberReader reader = new LineNumberReader(new FileReader(in));

		final FileWriter w = new FileWriter(out);
		
		Appendable writer = new Appendable() {
			@Override
			public Appendable append(CharSequence csq, int start, int end) throws IOException {
				w.write((String)csq, start, end);
				System.out.print(csq.subSequence(start, end));
				return this;
			}
			
			@Override
			public Appendable append(char c) throws IOException {
				return append("" + c);
			}
			
			@Override
			public Appendable append(CharSequence csq) throws IOException {
				return append(csq, 0, csq.length());
			}
		};
		
		go(reader, writer);
		
		w.close();
	}
	
	public static void main(String[] args) throws Exception {
		File dir = new File("/home/mitja/codejam/d");
		for (File f : dir.listFiles()) {
			if (f.isDirectory() || !f.getName().endsWith(".in"))
				continue;
			
			File out = new File(f.getParentFile(), f.getName() + ".out");
			
			System.out.println(f.getName() + " ==> " + out.getName());
			
			process(f, out);
		}
	}
}
