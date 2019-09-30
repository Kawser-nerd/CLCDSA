import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.NavigableSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Rect implements Comparable<Rect> {
		
		final long x1, y1, x2, y2;

		Rect(long x1, long y1, long x2, long y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
		
		public int compareTo(Rect o) {
			return x1 > o.x1 ? 1 : x1 < o.x1 ? -1 : 0;
		}
		
//		static String num(long num) {
//			if (num == Long.MIN_VALUE) {
//				return "-inf";
//			}
//			if (num == Long.MAX_VALUE) {
//				return "inf";
//			}
//			return Long.toString(num);
//		}
//		
//		public String toString() {
//			return "(" + num(x1) + " " + num(y1) + ")-(" + num(x2) + " " + num(y2) + ")";
//		}
	}
	static final Rect SPACE = new Rect(Long.MIN_VALUE, Long.MIN_VALUE, Long.MAX_VALUE, Long.MAX_VALUE);
	
	static void addRect(Collection<Rect> set, long x1, long y1, long x2, long y2) {
		if (x1 <= x2 && y1 <= y2) {
			set.add(new Rect(x1, y1, x2, y2));
		}
	}
	
//	static final int DX[] = {0, 1, 0, -1, 0};
//	static final int DY[] = {0, 0, 1, 0, -1};
//	
	static void solve() throws Exception {
//		System.err.println("===");
		int n = nextInt();
		long x[] = new long[n];
		long y[] = new long[n];
		int bit[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextLong();
			y[i] = nextLong();
			bit[i] = "#".equals(next()) ? 1 : 0;
		}
		long ansX = Long.MIN_VALUE;
		long ansY = Long.MIN_VALUE;
		List<Rect> nRects = new ArrayList<Rect>();
		for (int xbit = 0; xbit < 2; xbit++) {
			for (int ybit = 0; ybit < 2; ybit++) {
//				System.err.println("Testing bits " + xbit + " " + ybit);
				NavigableSet<Rect> rectUp = new TreeSet<Rect>();
				NavigableSet<Rect> rectDown = new TreeSet<Rect>();
				rectUp.add(SPACE);
				rectDown.add(SPACE);
				for (int i = 0; i < n; i++) {
					boolean goodX = ((x[i] ^ xbit ^ bit[i]) & 1) == 0;
					boolean goodY = ((y[i] ^ ybit ^ bit[i]) & 1) == 0;
					long nx = x[i] + y[i];
					long ny = x[i] - y[i];
					Rect point = new Rect(nx, 0, 0, 0);
					if (!goodX) {
//						System.err.println("Split down at (" + nx + " " + ny + ")");
						Rect pin = rectDown.floor(point);
						if (pin != null && pin.x1 <= nx && pin.x2 >= nx) {
							rectDown.remove(pin);
							addRect(rectDown, pin.x1, pin.y1, nx - 1, pin.y2);
							addRect(rectDown, nx + 1, pin.y1, pin.x2, pin.y2);
						}
						for (Iterator<Rect> it = rectDown.tailSet(point).iterator(); it.hasNext(); ) {
							Rect r = it.next();
							if (r.y2 < ny) {
								break;
							}
							it.remove();
							addRect(nRects, r.x1, r.y1, r.x2, ny - 1);
						}
						rectDown.addAll(nRects);
						nRects.clear();
						for (Iterator<Rect> it = rectDown.descendingSet().tailSet(point).iterator(); it.hasNext(); ) {
							Rect r = it.next();
							if (r.y1 > ny) {
								break;
							}
							it.remove();
							addRect(nRects, r.x1, ny + 1, r.x2, r.y2);
						}
						rectDown.addAll(nRects);
						nRects.clear();
					}
					if (!goodY) {
//						System.err.println("Split up at (" + nx + " " + ny + ")");
						Rect pin = rectUp.floor(point);
						if (pin != null && pin.x1 <= nx && pin.x2 >= nx) {
							rectUp.remove(pin);
							addRect(rectUp, pin.x1, pin.y1, nx - 1, pin.y2);
							addRect(rectUp, nx + 1, pin.y1, pin.x2, pin.y2);
						}
						for (Iterator<Rect> it = rectUp.tailSet(point).iterator(); it.hasNext(); ) {
							Rect r = it.next();
							if (r.y1 > ny) {
								break;
							}
							it.remove();
							addRect(nRects, r.x1, ny + 1, r.x2, r.y2);
						}
						rectUp.addAll(nRects);
						nRects.clear();
						for (Iterator<Rect> it = rectUp.descendingSet().tailSet(point).iterator(); it.hasNext(); ) {
							Rect r = it.next();
							if (r.y2 < ny) {
								break;
							}
							it.remove();
							addRect(nRects, r.x1, r.y1, r.x2, ny - 1);
						}
						rectUp.addAll(nRects);
						nRects.clear();
					}
				}
//				System.err.println("Up: " + rectUp);
//				System.err.println("Down: " + rectDown);
				Iterator<Rect> rUpIt = rectUp.iterator();
				Iterator<Rect> rDownIt = rectDown.iterator();
				Rect rUpCur = rUpIt.next();
				Rect rDownCur = rDownIt.next();
				while (true) {
					long x1 = max(rUpCur.x1, rDownCur.x1);
					long y1 = max(rUpCur.y1, rDownCur.y1);
					long x2 = min(rUpCur.x2, rDownCur.x2);
					long y2 = min(rUpCur.y2, rDownCur.y2);
//					System.err.println("Considering (" + Rect.num(x1) + " " + Rect.num(y1) + ")-(" + Rect.num(x2) + " " + Rect.num(y2) + ")");
					if (x1 <= x2 && y1 <= y2) {
						long bestXs[] = {x1, x2, 0, y1, y2, -y1, -y2};
						long bestYs[] = {y1, y2, 0, x1, x2, -x1, -x2};
						for (long bestX: bestXs) {
							if (abs(bestX) - 1 >= Long.MAX_VALUE - 1) {
								continue;
							}
							for (long bestY: bestYs) {
								if (abs(bestY) - 1 >= Long.MAX_VALUE - 1) {
									continue;
								}
								for (int dx = -4; dx <= 4; dx++) {
									for (int dy = -4; dy <= 4; dy++) {
										long curX = bestX + dx;
										long curY = bestY + dy;
										if (curX >= x1 && curX <= x2 && curY >= y1 && curY <= y2 &&
											((curX ^ curY) & 1) == 0) {
											long realX = (curX + curY) >> 1;
											long realY = (curX - curY) >> 1;
											if (((realX ^ xbit) & 1) == 0 && ((realY ^ ybit) & 1) == 0) {
//												System.err.println("Good point: (" + realX + " " + realY + ")");
												if (ansX != Long.MIN_VALUE) {
													if (abs(ansX) + abs(ansY) < abs(realX) + abs(realY)) {
														continue;
													}
													if (abs(ansX) + abs(ansY) == abs(realX) + abs(realY)) {
														if (ansX > realX) {
															continue;
														}
														if (ansX == realX) {
															if (ansY > realY) {
																continue;
															}
														}
													}
												}
												ansX = realX;
												ansY = realY;
											}
										}
									}
								}
							}
						}
					}
					if (rUpCur.x2 < rDownCur.x2) {
						if (!rUpIt.hasNext()) {
							break;
						}
						rUpCur = rUpIt.next();
					} else {
						if (!rDownIt.hasNext()) {
							break;
						}
						rDownCur = rDownIt.next();
					}
				}
			}
		}
		printCase();
		if (ansX == Long.MIN_VALUE) {
			out.println("Too damaged");
		} else {
//			if (!dumbCheck(x, y, bit, ansX, ansY)) {
//				System.err.println("Oops");
//			}
			out.println(ansX + " " + ansY);
		}
	}
	
//	static boolean dumbCheck(long x[], long y[], int bit[], long checkX, long checkY) {
//		long range = max(abs(checkX), abs(checkY)) + 10;
//		boolean good = false;
//		boolean bad = false;
//		int n = x.length;
//		long checkDist = abs(checkX) + abs(checkY);
//		for (long cx = -range; cx <= range; cx++) {
//			check: for (long cy = -range; cy <= range; cy++) {
//				for (int i = 0; i < n; i++) {
//					long dx = abs(x[i] - cx);
//					long dy = abs(y[i] - cy);
//					if (bit[i] != (max(dx, dy) & 1)) {
////						if (cx == checkX && cy == checkY) {
////							System.err.println("Fail");
////						}
//						continue check;
//					}
//				}
//				if (cx == checkX && cy == checkY) {
//					good = true;
//				}
//				long cdist = abs(cx) + abs(cy);
//				if (cdist < checkDist || cdist == checkDist && (cx > checkX || cx == checkX && cy > checkY)) {
//					System.err.println("(" + cx + " " + cy + ") vs (" + checkX + " " + checkY + ")");
//					bad = true;
//				}
//			}
//		}
//		return good && !bad;
//	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}