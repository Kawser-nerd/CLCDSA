import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int h=scanner.nextInt();
		int w=scanner.nextInt();
		int d=scanner.nextInt();
		int[][] a=new int[h][w];
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				a[i][j]=scanner.nextInt()-1;
			}
		}
		int q=scanner.nextInt();
		int[] l=new int[q];
		int[] r=new int[q];
		for(int i=0;i<q;i++) {
			l[i]=scanner.nextInt()-1;
			r[i]=scanner.nextInt()-1;
		}
		Map<Integer,Point>map=new HashMap<>();
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				Point p=new Point(j,i);
				map.put(a[i][j], p);
			}
		}
		StringBuilder sb=new StringBuilder();
		int[][] mp=new int[d+1][h*w/d+1];
		for(int i=0;i<d;i++) {
			int pre=i;
			int preX=map.get(pre).x;
			int preY=map.get(pre).y;
			while(true) {
				int now=pre+d;
				int nowi=now/d;
				int prei=pre/d;
				if(now>h*w-1) {
					break;
				}
				int nowX=map.get(now).x;
				int nowY=map.get(now).y;
				mp[i][nowi]=mp[i][prei]+Math.abs(nowX-preX)+Math.abs(nowY-preY);
				pre=now;
				preX=nowX;
				preY=nowY;
			}
		}
		for(int i=0;i<q;i++) {
			sb.append(mp[l[i]%d][r[i]/d]-mp[l[i]%d][l[i]/d]+"\n");
		}
		System.out.println(sb);
	}
}
class Point {
	int x, y;

	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
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