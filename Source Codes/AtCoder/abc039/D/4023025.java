import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] pic = new char[H][W];
		boolean[][] isWhite = new boolean[H][W];
		
		for(int i = 0; i < H; i++){
			String line = sc.next();
			for(int j = 0; j < W; j++){
				pic[i][j] = line.charAt(j);
				if(pic[i][j] == '.'){
					int[] dx = {0, 1, 1, 0, -1, -1, -1, 0, 1};
					int[] dy = {0, 0, -1, -1, -1, 0, 1, 1, 1};
					for(int k = 0; k < 9; k++){
						if(i+dy[k] < 0 || i+dy[k] >= H || j+dx[k] < 0 || j+dx[k] >= W) continue;
							isWhite[i+dy[k]][j+dx[k]] = true;
					}
				}
			}
		}
		
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(pic[i][j] == '#'){
					boolean canBlack = false;
					int[] dx = {0, 1, 1, 0, -1, -1, -1, 0, 1};
					int[] dy = {0, 0, -1, -1, -1, 0, 1, 1, 1};
					for(int k = 0; k < 9; k++){
						if(i+dy[k] < 0 || i+dy[k] >= H || j+dx[k] < 0 || j+dx[k] >= W) continue;
						if(!isWhite[i+dy[k]][j+dx[k]]){
							canBlack = true;
							break;
						}
					}
					
					if(!canBlack){
						System.out.println("impossible");
						return;
					}
				}
			}
		}
		
		System.out.println("possible");
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(isWhite[i][j]) System.out.print(".");
				else System.out.print("#");
			}
			System.out.println();
		}
		
	}//end main
	
}//end Main

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
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
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
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
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}