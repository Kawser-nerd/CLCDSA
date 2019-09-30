import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		h=scanner.nextInt();
		w=scanner.nextInt();
		String[][] s=new String[h][w];
		for(int i=0;i<h;i++) {
			s[i]=scanner.next().split("");
		}
		graph=new long[h*w][h*w];
		for(int i=0;i<h*w;i++) {
			Arrays.fill(graph[i], Integer.MAX_VALUE);
		}
		int cnt=0;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(s[i][j].equals(".")) {
					cnt++;
					check4Neighborhood(s, j, i);
				}
			}
		}
		varsize=h*w;
		used=new boolean[h*w];
		dis=new long[h*w];
		dijkstra(0);
		System.out.println(dis[h*w-1]==Integer.MAX_VALUE?-1:cnt-1-dis[h*w-1]);
	}
	static int h;
	static int w;
	static long[][] graph;
	private static void check4Neighborhood(String[][] s, int x, int y) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i == 0 && j != 0) || (i != 0 && j == 0)) {
					int tarX = j + x;
					int tarY = i + y;
					if (0 <= tarX && tarX <= s[0].length - 1 && 0 <= tarY && tarY <= s.length - 1) {
						if (s[tarY][tarX].equals(".")) {
							graph[w*y+x][w*tarY+tarX]=1;
							graph[w*tarY+tarX][w*y+x]=1;
						}
					}
				}
			}
		}
	}
	static long[] dis;
	static boolean[] used;
	static int varsize;
	static void dijkstra(int s) {
		Arrays.fill(dis, Integer.MAX_VALUE);
		dis[s] = 0;

		while (true) {
			int var = -1;
			//?????????????????????????
			for (int u = 0; u < varsize; u++) {
				if (!used[u] && (var == -1 || dis[u] < dis[var]))
					var = u;
			}

			if (var == -1)
				break;
			used[var] = true;

			//??for????????var????u????????????
			for (int u = 0; u < varsize; u++) {
				dis[u] = Math.min(dis[u], dis[var] + graph[var][u]);
			}
		}
	}
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}