package round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class P2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("round3/p2.in"));
		
		FileWriter out = new FileWriter("p2.out");
		
		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			
			int res = solveOne(br);
			System.out.println("Case #" + i + ": " + (res==INF?"THE CAKE IS A LIE":res));
			out.write("Case #" + i + ": " + (res==INF?"THE CAKE IS A LIE":res) + "\n");
		}
		br.close();
		out.close();
	}

	private static int R, C;
	private static final int KY = 100;
	private static String maze[];

	private static char get(int x, int y) {
		if (x<0 || x>=C || y<0 || y>=R)
			return '#';
		return maze[y].charAt(x);
	}
	
	private static int INF = 1000000;
	private static Map<Integer, Set<Integer>> moves;
	private static int xx, yx, kx;
	private static int solveOne(BufferedReader br) throws Exception {
		String p[] = br.readLine().split("\\s+");
		R = Integer.parseInt(p[0]);
		C = Integer.parseInt(p[1]);
		maze = new String[R];
		
		int xo=0, yo=0;
		xx=0;
		yx=0;
		for (int i=0; i<R; i++) {
			maze[i] = br.readLine();
			for (int j=0; j<maze[i].length(); j++) {
				char c = maze[i].charAt(j);
				if (c=='O') {
					xo = j;
					yo = i;
				} else if (c=='X') {
					xx = j;
					yx = i;
				}
			}
		}
		kx = xx+KY*yx;
		moves = new HashMap<Integer, Set<Integer>>();
		for (int y=0; y<R; y++) {
			for (int x=0; x<C; x++) {
				if (get(x, y)=='#') continue;
				int k0 = y*KY+x;
				
				boolean hasborder = false;
				for (int dx=-1; dx<=1; dx++) {
					for (int dy=-1; dy<=1; dy++) {
						if ((dx!=0 && dy!=0) || (dx==0 && dy==0)) continue;
						int y2 = y+dy;
						int x2 = x+dx;
						if (get(x2, y2)=='#') {
							hasborder = true;
						} else {
							int k1 = y2*KY+x2;
							doAdd(k0, k1);
						}
					}
				}
				if (hasborder) {
					for (int dx=-1; dx<=1; dx++) {
						for (int dy=-1; dy<=1; dy++) {
							if ((dx!=0 && dy!=0) || (dx==0 && dy==0)) continue;
							int y2 = y+dy;
							int x2 = x+dx;
							if (get(x2, y2)=='#') continue;
							while (get(x2+dx, y2+dy)!='#') {
								x2+=dx;
								y2+=dy;
							}
							int k1 = y2*KY+x2;
							doAdd(k0, k1);							
						}
					}
				}
			}
		}
		return doIt(xo, yo);
	}
	
	private static class Item {
		public int x, y, d;

		public Item(int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.d = d;
		}		
	}
		
	private static int doIt(int x, int y) {
		LinkedList<Item> que = new LinkedList<Item>();
		que.add(new Item(x, y, 0));
		Set<Integer> visited = new HashSet<Integer>();
		while (que.size()>0) {
			Item it = que.remove();
			int key = it.x+KY*it.y;
			if (visited.contains(key)) continue;
			visited.add(key);
//			System.out.println(it.x + " " + it.y + " " + it.d);
			if (key==kx)
				return it.d;
			if (moves.containsKey(key)) {
				for (Integer xx : moves.get(key)) {
					int x0 = xx % KY;
					int y0 = xx / KY;
					que.add(new Item(x0, y0, it.d+1));
				}
			}
		}
		return INF;
	}

	private static void doAdd(int k0, int k1) {
		if (!moves.containsKey(k0))
			moves.put(k0, new HashSet<Integer>());
		
		moves.get(k0).add(k1);		
	}
}
