import java.util.Map.Entry;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] a = new int[H][W];
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				a[i][j] = sc.nextInt();
			}
		}
		ArrayList<String> ans = new ArrayList<>();
		int num = 0;
		
		for(int i = 0; i < H; i++){
			if(i % 2 == 0){
				for(int j = 0; j < W; j++){
					if(a[i][j] % 2 == 1){
						int x, y, xx, yy;
						if(j != W-1){
							y = i; x = j; xx = j + 1; yy = i;
						}else{
							y = i; x = j; xx = j; yy = i + 1;
							if(yy == H) break;
						}
						a[y][x]--;
						a[yy][xx]++;
						ans.add((y+1) + " " + (x+1) + " " + (yy+1) + " " + (xx+1) + "\n");
						num++;
					}
				}
			}else{
				for(int j = W - 1; j >= 0; j--){
					if(a[i][j] % 2 == 1){
						int x, y, xx, yy;
						if(j != 0){
							y = i; x = j; xx = j - 1; yy = i;
						}else{
							y = i; x = j; xx = j; yy = i + 1;
							if(yy == H) break;
						}
						a[y][x]--;
						a[yy][xx]++;
						ans.add((y+1) + " " + (x+1) + " " + (yy+1) + " " + (xx+1) + "\n");
						num++;
					}
				}
			}
		}
		
		System.out.println(num);
		for(String s : ans) System.out.print(s);
		
		/*
		System.out.println();
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
		*/
	}
}

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