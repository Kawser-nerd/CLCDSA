import java.io.IOException;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;
public class Main{

	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		int[][] table = new int[H][W];
		int[][] visited = new int[H][W];
		int min = 100000;
		ArrayDeque<Integer> QX = new ArrayDeque<Integer>();
		ArrayDeque<Integer> QY = new ArrayDeque<Integer>();
		for(int i=0;i<H;i++){
			String S = sc.next();
			for(int j=0;j<W;j++){
				if(S.charAt(j)=='S'){
					QX.add(i);
					QY.add(j);
					visited[i][j] = 0;
					int ml = 10000;
					ml = Math.min(ml,i);
					ml = Math.min(ml,j);
					ml = Math.min(ml,H-1-i);
					ml = Math.min(ml,W-1-j);
					min = Math.min(min, ml);
				}else{
					visited[i][j] = -1;
					table[i][j] = S.charAt(j)=='.'?0:1;
				}
			}
		}
		int[] dx = {1,0,-1,0};
		int[] dy = {0,1,0,-1};
		while(!QX.isEmpty()){
			int x = QX.poll();
			int y = QY.poll();
			int t = visited[x][y];
			if(t!=K){
				for(int i=0;i<4;i++){
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<H&&ny>=0&&ny<W){
						if(visited[nx][ny]==-1&&table[nx][ny]==0){
							visited[nx][ny] = t+1;
							if(nx==0||nx==H-1||ny==0||ny==W-1){
								System.out.println(1);
								return;
							}else{
								int ml = 10000;
								ml = Math.min(ml,nx);
								ml = Math.min(ml,ny);
								ml = Math.min(ml,H-1-nx);
								ml = Math.min(ml,W-1-ny);
								min = Math.min(min, ml);
								QX.add(nx);
								QY.add(ny);
							}
						}
					}
				}
			}
		}
		System.out.println((min-1)/K+2);
	
	}
	


}


class FastScanner {
    private final java.io.InputStream in = System.in;
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
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
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
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
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
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}