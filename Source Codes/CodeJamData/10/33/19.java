import java.awt.Point;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class C {

	private static final String HEX = "0123456789ABCDEF";
	
	private static final int[][] BITS = {
		{0, 0, 0, 0},
		{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 1, 1},
		{0, 1, 0, 0},
		{0, 1, 0, 1},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{1, 0, 0, 0},
		{1, 0, 0, 1},
		{1, 0, 1, 0},
		{1, 0, 1, 1},
		{1, 1, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 1, 0},
		{1, 1, 1, 1},
	};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			Map<Integer, Integer> ans = new HashMap<Integer, Integer>();
			
			int M = sc.nextInt();
			int N = sc.nextInt();
			boolean[][] map = new boolean[M][N];
			
			for (int i = 0; i < M; ++i) {
				String s = sc.next();
				for (int j = 0; j * 4 < N; j++) {
					char c = s.charAt(j);
					int[] bs = BITS[HEX.indexOf(c)];
					for (int k = 0; k < 4; ++k) {
						map[i][j * 4 + k] = (bs[k] == 0);
					}
				}
			}
			
//			System.out.println(M + " " + N);
//			for (int i = 0; i < M; ++i) {
//				for (int j = 0; j < N; ++j) {
//					if (map[i][j]) {
//						System.out.print("0 ");
//					} else {
//						System.out.print("1 ");
//					}
//				}
//				System.out.println();
//			}
			
			int[][] size = new int[M][N];
			Map<Point, Integer> ptree = new HashMap<Point, Integer>();
			Map<Integer, List<Point>> stree = new HashMap<Integer, List<Point>>();
			for (int i = M - 1; i >= 0; --i) {
				for (int j = N - 1; j >= 0; --j) {
					int E = 1, S = 1, SE = 0;
					{
						int x = i, y = j + 1;
						boolean last = map[i][j];
						while (y < N && map[x][y] != last) {
							last = map[x][y];
							E++; y++;
						}
					}
					{
						int x = i + 1, y = j;
						boolean last = map[i][j];
						while (x < M && map[x][y] != last) {
							last = map[x][y];
							S++; x++;
						}
					}
					{
						int x = i + 1, y = j + 1;
						if (x < M && y < N) {
							if (map[x][y] == map[i][j]) {
								SE = size[x][y];
							}
						}
					}
					size[i][j] =  Math.min(S, Math.min(E, SE + 1));
					Point me = new Point(i, j);
					ptree.put(me, size[i][j]);
					if (size[i][j] > 1) {
						if (!stree.containsKey(size[i][j])) {
							stree.put(size[i][j], new ArrayList<Point>());
						}
						stree.get(size[i][j]).add(me);
					}
				}
			}

//			for (int i = 0; i < M; ++i) {
//				for (int j = 0; j < N; ++j) {
//					System.out.print(ptree.get(new Point(i, j)) + " ");
//				}
//				System.out.println();
//			}
			
			int one = M * N;
			{
				List<Integer> list = new ArrayList<Integer>(stree.keySet());
				Collections.sort(list, Collections.reverseOrder());
				for (int sz : list) {
					List<Point> lp = stree.get(sz);
					Collections.sort(lp, new Comparator<Point>(){
						@Override
						public int compare(Point a, Point b) {
							if (a.x == b.x) {
								return a.y - b.y;
							} else {
								return a.x - b.x;
							}
						}
						
					});
					for (Point p : lp) {
						boolean valid = true;
						for (int x = 0; x < sz; ++x) {
							for (int y = 0; y < sz; ++y) {
								Point q = new Point(p.x + x, p.y + y);
								if (!ptree.containsKey(q)) {
									valid = false;
									break;
								}
							}
							if (!valid) {
								break;
							}
						}
						if (valid) {
							for (int x = 0; x < sz; ++x) {
								for (int y = 0; y < sz; ++y) {
									Point q = new Point(p.x + x, p.y + y);
									ptree.remove(q);
								}
							}
							if (!ans.containsKey(sz)) {
								ans.put(sz, 0);
							}
							ans.put(sz, ans.get(sz) + 1);
//							System.out.println("###\t" + sz + "\t" + p);
							one -= sz * sz;
						} else {
							if (!stree.containsKey(sz - 1)) {
								stree.put(sz - 1, new ArrayList<Point>());
							}
							stree.get(sz - 1).add(new Point(p.x, p.y));
						}
					}
				}
			}
			
			if (one > 0) {
				ans.put(1, one);
			}
			
			System.out.println("Case #" + t + ": " + ans.size());
			List<Integer> list = new ArrayList<Integer>(ans.keySet());
			Collections.sort(list, Collections.reverseOrder());
			for (int i : list) {
				System.out.println(i + " " + ans.get(i));
			}
		}
	}
	
}
