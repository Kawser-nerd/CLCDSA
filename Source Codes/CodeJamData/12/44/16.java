import java.math.MathContext;
import java.math.RoundingMode;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class D {
	private static Scanner sc;
//	private static long start;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; i++) {
//			start = System.currentTimeMillis();
			System.out.printf("Case #%d: %s\n", i + 1, exec());
//			long end = System.currentTimeMillis();
//			System.err.printf("Time taken: %.2f\n", .001 * (end - start));
		}
	}
	
	@SuppressWarnings("unused") private static final MathContext ROUND_CONTEXT = new MathContext(8, RoundingMode.HALF_EVEN);
	
	private static int h, w;
	private static char[][] g;
	
	public static String exec() {
		h = sc.nextInt();
		w = sc.nextInt();
		g = new char[h][w];
		int c = -1;
		int[] cs = new int[10];
		for (int y = 0; y < h; y++) {
			String in = sc.next();
			for (int x = 0; x < w; x++) {
				g[y][x] = in.charAt(x);
				if (Character.isDigit(g[y][x])) {
					int cID = g[y][x] - '0';
					c = Math.max(c, cID);
					cs[cID] = y * 1000 + x;
				}
			}
		}
		
		c++;
		
		StringBuilder sb = new StringBuilder();
		for (int cID = 0; cID < c; cID++) {
			boolean[][] reach = findReach(cs[cID]);
			int nc = 0;
			Set<Integer> orig = new HashSet<Integer>();
			for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) if (reach[y][x]) {
				nc++;
				orig.add(y * 1000 + x);
			}
			Set<Set<Integer>> visited = new HashSet<Set<Integer>>();
			
			Set<Set<Integer>> todo = new HashSet<Set<Integer>>();
			todo.add(orig);
			
			boolean lucky = false;
			
			while (true) {
				if (todo.isEmpty()) break;
				Set<Integer> pos = todo.iterator().next();
				todo.remove(pos);
				
				try {
					attemptNewPos(walkLeft(pos), visited, todo, orig);
					attemptNewPos(walkRight(pos), visited, todo, orig);
					attemptNewPos(walkDown(pos), visited, todo, orig);
				} catch (Lucky e) {
					lucky = true;
					break;
				}
				visited.add(pos);
			}
			
			sb.append(String.format("\n%d: %d %s", cID, nc, lucky ? "Lucky" : "Unlucky"));
		}
		
		return sb.toString();
	}
	
	private static class Lucky extends RuntimeException {}
	
	private static void attemptNewPos(Set<Integer> newPos, Set<Set<Integer>> visited, Set<Set<Integer>> todo, Set<Integer> orig) {
		if (visited.contains(newPos)) return;
		if (todo.contains(newPos)) return;
		
		for (int pos : newPos) if (!orig.contains(pos)) {
			visited.add(newPos);
			return;
		}
		
		if (newPos.size() == 1) throw new Lucky();
		todo.add(newPos);
	}
	
	private static Set<Integer> walkLeft(Set<Integer> pos) {
		Set<Integer> out = new HashSet<Integer>();
		for (int p : pos) {
			int y = p / 1000;
			int x = p % 1000;
			x--;
			if (g[y][x] == '#') x++;
			out.add(y * 1000 + x);
		}
		return out;
	}
	
	private static Set<Integer> walkRight(Set<Integer> pos) {
		Set<Integer> out = new HashSet<Integer>();
		for (int p : pos) {
			int y = p / 1000;
			int x = p % 1000;
			x++;
			if (g[y][x] == '#') x--;
			out.add(y * 1000 + x);
		}
		return out;
	}
	
	private static Set<Integer> walkDown(Set<Integer> pos) {
		Set<Integer> out = new HashSet<Integer>();
		for (int p : pos) {
			int y = p / 1000;
			int x = p % 1000;
			y++;
			if (g[y][x] == '#') y--;
			out.add(y * 1000 + x);
		}
		return out;
	}
	
	private static boolean[][] findReach(int i) {
		boolean[][] reach = new boolean[h][w];
		reach[i / 1000][i % 1000] = true;
		findReach0(reach, i / 1000, i % 1000);
		return reach;
	}
	
	private static void findReach0(boolean[][] reach, int y, int x) {
		//go left
		x--;
		if (g[y][x] != '#' && !reach[y][x]) {
			reach[y][x] = true;
			findReach0(reach, y, x);
		}
		//go right
		x += 2;
		if (g[y][x] != '#' && !reach[y][x]) {
			reach[y][x] = true;
			findReach0(reach, y, x);
		}
		//go up
		x--;
		y--;
		if (g[y][x] != '#' && !reach[y][x]) {
			reach[y][x] = true;
			findReach0(reach, y, x);
		}
	}
}
