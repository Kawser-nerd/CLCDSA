import java.util.*;
import java.math.*;
import java.io.*;

public class B {
	static final int[] DX = {-1, -1, 0, 0, 1, 1};
	static final int[] DY = {-1, 0, -1, 1, 0, 1};
	
	boolean isOK(int ox, int oy) {
		return ox >= 0 && oy >= 0 && ox < maxCoord && oy < maxCoord &&
				ox - oy < sideLen && oy - ox < sideLen;
	}
	
	class Position {
		int x, y;

		public Position(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
		ArrayList<Position> getNeighbours() {
			ArrayList<Position> nei = new ArrayList<B.Position>();
			for (int dir = 0; dir < DX.length; ++dir) {
				int ox = x + DX[dir], oy = y + DY[dir];
				if (isOK(ox, oy)) {
					nei.add(new Position(ox, oy));
				}
			}
			return nei;
		}
		
		int getCornerMask() {
			if (x == 0 && y == 0) {
				return (1 << 0);
			} else if (x == 0 && y == sideLen - 1) {
				return (1 << 1);
			} else if (x == sideLen - 1 && y == 0) {
				return (1 << 2);
			} else if (x == sideLen - 1 && y == maxCoord - 1) {
				return (1 << 3);
			} else if (x == maxCoord - 1 && y == sideLen - 1) {
				return (1 << 4);
			} else if (x == maxCoord - 1 && y == maxCoord - 1) {
				return (1 << 5);
			}
			return 0;
		}
		
		int getSideMask() {
			if (getCornerMask() > 0) {
				return 0;
			} else if (x == 0) {
				return (1 << 0);
			} else if (y == 0) {
				return (1 << 1);
			} else if (x == maxCoord - 1) {
				return (1 << 2);
			} else if (y == maxCoord - 1) {
				return (1 << 3);
			} else if (x - y == sideLen - 1) {
				return (1 << 4);
			} else if (y - x == sideLen - 1) {
				return (1 << 5);
			}
			return 0;
		}
		
		int getStateMask() {
			return getSideMask() | (getCornerMask() << 6);
		}
	}
	
	int tt = 0;
	
	int sideLen, numMoves;
	int maxCoord;
	int[] moveX, moveY;
	int[][] step;
	int[][] stateMask;
	int[][] visited;
	boolean[] isFork, isBridge;

	private void solve() throws Exception {
		sideLen = nextInt();
		numMoves = nextInt();
		moveX = new int[numMoves];
		moveY = new int[numMoves];
		maxCoord = sideLen * 2 - 1;
		step = new int[maxCoord][maxCoord];
		for (int i = 0; i < numMoves; ++i) {
			moveX[i] = nextInt() - 1;
			moveY[i] = nextInt() - 1;
			step[moveX[i]][moveY[i]] = i + 1;
		}
		int minStep = Integer.MAX_VALUE;
		boolean bridgeFound = false;
		boolean forkFound = false;
		stateMask = new int[maxCoord][maxCoord];
		visited = new int[maxCoord][maxCoord];
		for (int i = 0; i < numMoves; ++i) {
			Position cur = new Position(moveX[i], moveY[i]);
			int mask = cur.getStateMask();
			for (Position o : cur.getNeighbours()) {
				mask |= stateMask[o.x][o.y];
			}
			if (isFork[mask]) {
				forkFound = true;
				minStep = i;
			}
			if (isBridge[mask]) {
				bridgeFound = true;
				minStep = i;
			}
			if (forkFound || bridgeFound) {
				break;
			} else {
				++tt;
				dfs(cur, mask, i + 1);
			}
		}
		boolean ringFound = false;
		int minRingStep = Integer.MAX_VALUE;
		/*if (hasRing(numMoves)) {
			ringFound = true;
			minRingStep = numMoves - 1;
		}
		for (int i = 0; i < numMoves; ++i) {
			Position cur = new Position(moveX[i], moveY[i]);
			ArrayList<Position> nei = cur.getNeighbours();
			if (nei.size() == 6) {
				boolean hasFree = false;
				for (Position o : nei) {
					if (step[o.x][o.y] == 0 || step[o.x][o.y] > i + 1) {
						hasFree = true;
						break;
					}
				}
				if (!hasFree) {
					ringFound = true;
					minRingStep = i - 1;
				}
			}
			if (ringFound) {
				break;
			}
		}
		if (ringFound) {
			int lo = 0, hi = minRingStep;
			while (hi - lo > 1) {
				int mid = (lo + hi) / 2;
				if (hasRing(mid + 1)) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			minRingStep = hi;
		}*/
		for (int i = 0; i < numMoves; ++i) {
			if (hasRing(i + 1)) {
				ringFound = true;
				minRingStep = i;
				break;
			}
		}
		if (ringFound) {
			if (minRingStep < minStep) {
				forkFound = false;
				bridgeFound = false;
				minStep = minRingStep;
			}
			if (minRingStep > minStep) {
				ringFound = false;
			}
		}
		if (!ringFound && !forkFound && !bridgeFound) {
			out.println("none");
		} else if (!ringFound && !forkFound) {
			out.println("bridge in move " + (minStep + 1));
		} else if (!ringFound && !bridgeFound) {
			out.println("fork in move " + (minStep + 1));
		} else if (!forkFound && !bridgeFound) {
			out.println("ring in move " + (minStep + 1));
		} else if (!ringFound) {
			out.println("bridge-fork in move " + (minStep + 1));
		} else if (!forkFound) {
			out.println("bridge-ring in move " + (minStep + 1));
		} else if (!bridgeFound) {
			out.println("fork-ring in move " + (minStep + 1));
		} else {
			out.println("bridge-fork-ring in move " + (minStep + 1));
		}
	}
	
	private boolean hasRing(int st) {
		++tt;
		for (int x = 0; x < maxCoord; ++x) {
			for (int y = 0; y < maxCoord; ++y) {
				if ((step[x][y] > 0 && step[x][y] <= st) || !isOK(x, y)) {
					continue;
				}
				Position cur = new Position(x, y);
				if (cur.getStateMask() > 0 && visited[x][y] != tt) {
					dfsFree(cur, st);
				}
			}
		}
		for (int x = 0; x < maxCoord; ++x) {
			for (int y = 0; y < maxCoord; ++y) {
				if ((step[x][y] > 0 && step[x][y] <= st) || !isOK(x, y)) {
					continue;
				}
				// Position cur = new Position(x, y);
				if (visited[x][y] != tt) {
					return true;
				}
			}
		}
		return false;
	}

	private void dfsFree(Position p, int st) {
		visited[p.x][p.y] = tt;
		for (Position o : p.getNeighbours()) {
			if ((step[o.x][o.y] == 0 || step[o.x][o.y] > st)
					&& visited[o.x][o.y] != tt) {
				dfsFree(o, st);
			}
		}
		
	}

	private void dfs(Position p, int mask, int st) {
		stateMask[p.x][p.y] = mask;
		visited[p.x][p.y] = tt;
		for (Position o : p.getNeighbours()) {
			if (step[o.x][o.y] > 0 && step[o.x][o.y] <= st
					&& visited[o.x][o.y] != tt && stateMask[o.x][o.y] != mask) {
				/*if ((mask & stateMask[o.x][o.y]) == mask) {
					throw new RuntimeException("???");
				}*/
				dfs(o, mask, st);
			}
		}
	}

	void precalc() {
		isFork = new boolean[1 << 12];
		isBridge = new boolean[1 << 12];
		for (int mask = 0; mask < isFork.length; ++mask) {
			int cornerMask = (mask >> 6);
			int sideMask = mask & ((1 << 6) - 1);
			isBridge[mask] = Integer.bitCount(cornerMask) >= 2;
			isFork[mask] = Integer.bitCount(sideMask) >= 3;
		}
	}

	public void run() {
		try {
			precalc();
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private B(String name) {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new B("b").run();
	}
}
