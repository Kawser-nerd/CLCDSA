import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
	int H,W,K;
	int[] dx = {0,0,-1,1},dy = {-1,1,0,0};
	char[][] ch;
	boolean[][] canGo;

	public boolean isRange(int x,int y){
		return x >= 0 && x < W && y >= 0 && y < H;
	}

	public void first_bfs(int sx,int sy){
		ArrayDeque<Long> q = new ArrayDeque<Long>();
		q.add(sx * 1000000000L + sy * 1000000L + 0);

		while(q.size() > 0){
			long p = q.poll();

			int x = (int)(p/1000000000L);
			int y = (int)((p/1000000L)%1000);
			int c = (int)(p%1000000);

			if(canGo[y][x])continue;
			canGo[y][x] = true;
			for(int i = 0;i < 4;i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(isRange(nx,ny) && !canGo[ny][nx] && ch[ny][nx] == '.' && c + 1 <= K){
					q.add(nx * 1000000000L + ny * 1000000L + c+1);
				}
			}
		}
	}

	public void solve(){
		H = nextInt();
		W = nextInt();
		K = nextInt();

		ch = new char[H][];
		for(int i = 0;i < H;i++){
			ch[i] = next().toCharArray();
		}

		int sx = -1,sy = -1;
		for(int i = 0;i < H;i++){
			for(int j = 0;j < W;j++){
				if(ch[i][j] == 'S'){
					sx = j;
					sy = i;
				}
			}
		}
		canGo = new boolean[H][W];
		first_bfs(sx,sy);

		ArrayList<Integer> points = new ArrayList<Integer>();
		for(int i = 0;i < H;i++){
			for(int j = 0;j < W;j++){
				if(canGo[i][j]){
					points.add(j * 1000 + i);
				}
			}
		}

		int min = Integer.MAX_VALUE;

		for(int p : points){
			int x = p / 1000;
			int y = p % 1000;

			if(x == 0 || y == 0 || x == W-1 || y == H-1){
				min = 1;
				continue;
			}

			int x1 = x;
			int y1 = y;
			int x2 = W-x-1;
			int y2 = H-y-1;

			int minDis = Math.min(Math.min(x1,y1), Math.min(x2, y2));
			min = Math.min(min, ((int)Math.ceil(minDis*1.0/K))+1);
		}

		out.println(min);
	}

	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
	}

	/* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}

	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}