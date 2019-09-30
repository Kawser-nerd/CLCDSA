import java.io.File;
import java.io.FileInputStream;
import java.util.Scanner;
import java.util.Set;
import java.util.Map.Entry;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main {
	static long wsum = 0;
	static long bsum = 0;
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		
		if(N <= 2){
			System.out.println(1);
			return;
		}
		
		int ans = 1;
		boolean pIsInc = true;
		boolean isInc = true;
		boolean start = false;
		int pA = sc.nextInt();
		
		for(int i = 1; i < N; i++){
			int A = sc.nextInt();
			if(!start){
				if(A != pA){
					if(A > pA) pIsInc = true;
					else pIsInc = false;
					start = true;
				}
			}else{
				if(A > pA && !pIsInc){
					start = false;
					ans++;
				}else if(A < pA && pIsInc){
					start = false;
					ans++;
				}
			}
			
			pA = A;
		}
		System.out.println(ans);
	}
	
	static void sumWB(int n, int m){
		if(n % 2 == 0 && m % 2 == 0){
			wsum = n * m / 2;
			bsum = n * m / 2;
		}else if(n % 2 == 0 && m % 2 == 1){
			wsum = n * (m + 1) / 2 - 2;
			bsum = n * (m + 1) / 2 - 2;
		}else if(n % 2 == 1 && m % 2 == 0){
			wsum = (n + 1) * m / 2 - 2;
			bsum = (n + 1) * m / 2 - 2;
		}else if(n % 2 == 1 && m % 2 == 1){
			int wn = (n + 1) / 2;
			int wdn = n;
			wsum = wn + wdn * (m - 1) / 2;
			bsum = n * m - wsum;
		}
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