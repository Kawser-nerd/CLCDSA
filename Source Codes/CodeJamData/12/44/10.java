import java.io.*;
import java.util.*;

import javax.swing.text.*;

import static java.lang.Math.*;
import static java.lang.System.*;

public class ProblemD {


	public class Case {
		int w, h;
		char[][] mountain;
		int numCaves = 0;
		int[] caveX = new int[10];
		int[] caveY = new int[10];

		public void solve(int caseIndex) {

			println("Case #" + (caseIndex + 1) + ":");
			for (int cave = 0; cave < numCaves; cave++) {
				boolean result = false;
				LinkedHashSet<Pos> possibleStarts = new LinkedHashSet<Pos>();
				try {
					int x = caveX[cave];
					int y = caveY[cave];
					addPossibleStarts(x, y, possibleStarts);
	
					LinkedHashSet<Pos> positions = new LinkedHashSet<Pos>();
					ArrayList<Integer> moves = new ArrayList<Integer>();
					positions.add(new Pos(caveX[cave], caveY[cave]));
	
					new Search(possibleStarts).search(positions, moves);
				}
				catch (FoundSolutionException e) {
					result = true;
				}
				println(""+cave+": "+possibleStarts.size() + " " + (result ? "Lucky" : "Unlucky"));
//				if (cave == 1) return;
			}
		}

		boolean isPassable(int x, int y) {
			char ch = mountain[y][x];
			if (ch == '.') return true;
			if (ch >= '0' && ch <= '9') return true;
			return false;
		}

		boolean isPassable(Pos p) {
			return isPassable(p.x, p.y);			
		}

		void addPossibleStarts(int x, int y, LinkedHashSet<Pos> possibleStarts) {
			if (possibleStarts.contains(new Pos(x, y))) return;
			if (!isPassable(x, y)) return;
			possibleStarts.add(new Pos(x, y));
			addPossibleStarts(x - 1, y, possibleStarts);
			addPossibleStarts(x + 1, y, possibleStarts);
			addPossibleStarts(x, y - 1, possibleStarts);
		}

		class Search {
			LinkedHashSet<Pos> possibleStarts;
			LinkedHashSet<LinkedHashSet<Pos>> visited = new LinkedHashSet<LinkedHashSet<Pos>>();

			public Search(LinkedHashSet<Pos> possibleStarts) {
				this.possibleStarts = possibleStarts;
			}

			void search(LinkedHashSet<Pos> positions, ArrayList<Integer> moves) {
//				println(""+positions+", moves: "+moves);

				if (visited.contains(positions)) {
					return;
				}
				visited.add(new LinkedHashSet<Pos>(positions));

				boolean allStarts = true;
				for (Pos start : possibleStarts) {
					if (!positions.contains(start)) {
						allStarts = false;
						break;
					}
				}

				if (allStarts) {
//					for (int i = moves.size() - 1; i >= 0; i--) {
//						int move = moves.get(i);
//						if (move == 0) System.out.println("left");
//						if (move == 1) System.out.println("right");
//						if (move == 2) System.out.println("down");
//					}
					throw new FoundSolutionException();
				}

				tryMove(0, positions, getLeftPositions(positions), moves);
				tryMove(1, positions, getRightPositions(positions), moves);
				tryMove(2, positions, getDownPositions(positions), moves);
			}

			void tryMove(int move, LinkedHashSet<Pos> oldPositions, LinkedHashSet<Pos> newPositions, ArrayList<Integer> moves) {
				if (newPositions.isEmpty()) return;

				if (oldPositions.equals(newPositions)) {
					return;
				}

				moves.add(move);
				search(newPositions, moves);
				moves.remove(moves.size() - 1);
			}

			LinkedHashSet<Pos> getLeftPositions(LinkedHashSet<Pos> positions) {
				LinkedHashSet<Pos> result = new LinkedHashSet<Pos>();
				for (Pos p : positions) {
					if (!isPassable(p.x - 1, p.y)) {
						result.add(p);
					}
					if (isPassable(p.x + 1, p.y)) {
						result.add(new Pos(p.x + 1, p.y));
					}
				}
				return result;
			}

			LinkedHashSet<Pos> getRightPositions(LinkedHashSet<Pos> positions) {
				LinkedHashSet<Pos> result = new LinkedHashSet<Pos>();
				for (Pos p : positions) {
					if (!isPassable(p.x + 1, p.y)) {
						result.add(p);
					}
					if (isPassable(p.x - 1, p.y)) {
						result.add(new Pos(p.x - 1, p.y));
					}
				}
				return result;
			}

			LinkedHashSet<Pos> getDownPositions(LinkedHashSet<Pos> positions) {
				LinkedHashSet<Pos> result = new LinkedHashSet<Pos>();
				for (Pos p : positions) {
					if (!isPassable(p.x, p.y + 1)) {
						result.add(p);
					}
					if (isPassable(p.x, p.y - 1)) {
						result.add(new Pos(p.x, p.y - 1));
					}
				}
				return result;
			}
		}

		class FoundSolutionException extends RuntimeException {
		}

		class Pos {
			int x, y;

			public Pos(int x, int y) {
				this.x = x;
				this.y = y;
			}

			@Override
			public int hashCode() {
				final int prime = 31;
				int result = 1;
				result = prime * result + getOuterType().hashCode();
				result = prime * result + x;
				result = prime * result + y;
				return result;
			}

			@Override
			public boolean equals(Object obj) {
				if (this == obj)
					return true;
				if (obj == null)
					return false;
				if (getClass() != obj.getClass())
					return false;
				Pos other = (Pos) obj;
				if (!getOuterType().equals(other.getOuterType()))
					return false;
				if (x != other.x)
					return false;
				if (y != other.y)
					return false;
				return true;
			}

			private Case getOuterType() {
				return Case.this;
			}

			public String toString() {
				return ""+x+","+y;
			}
		}

	}

	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			c.h = p.readInt();
			c.w = p.readInt();
			c.mountain = new char[c.h][c.w];
//			println("---------------------------------------");
//			println(""+caseIndex);
			for (int y = 0; y < c.h; y++) {
				String line = r.readLine();
				for (int x = 0; x < c.w; x++) {
					char ch = line.charAt(x);
					c.mountain[y][x] = ch;
					if (ch >= '0' && ch <= '9') {
						int cave = Integer.parseInt(""+ch);
						c.numCaves = max(c.numCaves, cave + 1);
						c.caveX[cave] = x;
						c.caveY[cave] = y;
					}
				}
			}

			c.solve(caseIndex);
//			return;
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemD().run();
		fileWriter.close();
	}

	public static class InputParser {
		String text;
		int pos;

		public InputParser(String text) {
			this.text = text;
		}

		public void skipSpaces() {
			while (pos < text.length()) {
				if (text.charAt(pos) != ' ') break;
				pos++;
			}
		}

		public String readUntil(char expectedChar) {
			StringBuilder b = new StringBuilder();
			while (pos < text.length()) {
				char ch = text.charAt(pos);
				if (ch == expectedChar) break;
				b.append(ch);
				pos++;
			}
			return b.toString();
		}

		public String readToken() {
			skipSpaces();
			return readUntil(' ');
		}

		public int readInt() {
			return Integer.parseInt(readToken());
		}

		public long readLong() {
			return Long.parseLong(readToken());
		}

		public char readChar() {
			char ch = text.charAt(pos);
			pos++;
			return ch;
		}

		public void readExpectedString(String s) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (readChar() != ch) throw new RuntimeException("Expected: "+ch);
			}
		}
	}

	public static PrintWriter fileWriter;

	public static void print(String text) {
		fileWriter.print(text);
		System.out.print(text);
	}

	public static void println(String text) {
		fileWriter.println(text);
		System.out.println(text);
	}

	public static <Key, Value> void addToMultiMapArrayList(Key key, Value value, Map<Key, ArrayList<Value>> map) {
		ArrayList<Value> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> void addToMultiMapLinkedHashSet(Key key, Value value, Map<Key, LinkedHashSet<Value>> map) {
		LinkedHashSet<Value> list = map.get(key);
		if (list == null) {
			list = new LinkedHashSet<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> ArrayList<Value> getMultiMapValues(Map<Key, Collection<Value>> map) {
		ArrayList<Value> result = new ArrayList<Value>();
		for (Collection<Value> list : map.values()) {
			result.addAll(list);
		}
		return result;
	}

//	binarySearch(, , 0.000000001, new Function<Double, Integer>() {
//		public Integer evaluate(Double key) {
//			return ;
//		}
//	});
	public static double binarySearch(double low, double high, double precision, Function<Double, Integer> f) {
		if (high < low) throw new RuntimeException("High ("+high+") cannot be smaller than low ("+low+")");
		{
			int lowValue = f.evaluate(low);
			if (lowValue == 0) return low;
			if (lowValue > 0) throw new RuntimeException("Unsuitable low: "+low);
		}
		{
			int highValue = f.evaluate(high);
			if (highValue == 0) return high;
			if (highValue < 0) throw new RuntimeException("Unsuitable high: "+high);
		}

		while (true) {
			double mid = (low + high) * 0.5;
			if (abs(high - low) < precision) {
				return mid;
			}

			int c = f.evaluate(mid);
			if (c < 0) low = mid;
			else if (c > 0) high = mid;
			else return mid;
		}
	}

	public static interface Function<Key, Value> {
		public Value evaluate(Key key);
	}

}



