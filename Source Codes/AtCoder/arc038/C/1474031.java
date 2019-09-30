import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int[][] cup = sc.nextIntTable(N - 1, 2);
    
    SegmentTreeRMQ st = new SegmentTreeRMQ(100001);
    st.update(0, 0);

    int[] grundy = new int[N];
    for (int i = 1; i < N; i ++) {
      int C = cup[i - 1][0];

      int left = 0;
      int right = 100001;
      while (right - left > 1) {
        int k = left + right >> 1;
        if (st.min(0, k) >= i - C) {
          left = k;
        } else {
          right = k;
        }
      }
      
      grundy[i] = left;
      st.update(left, i);
    }
    
    int g = 0;
    for (int i = 1; i < N; i ++) {
      int A = cup[i - 1][1];
      if (A % 2 == 1) {
        g ^= grundy[i];
      }
    }
    System.out.println(g == 0 ? "Second" : "First");
  }
}

class SegmentTreeRMQ {
  public int M, H, N;
  public int[] st;
  
  public SegmentTreeRMQ(int n)
  {
      N = n;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new int[M];
      Arrays.fill(st, 0, M, -1);
  }
  
  public SegmentTreeRMQ(int[] a)
  {
      N = a.length;
      M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
      H = M>>>1;
      st = new int[M];
      for(int i = 0;i < N;i++){
          st[H+i] = a[i];
      }
      Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
      for(int i = H-1;i >= 1;i--)propagate(i);
  }
  
  public void update(int pos, int x)
  {
      st[H+pos] = x;
      for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
  }
  
  private void propagate(int i)
  {
      st[i] = Math.min(st[2*i], st[2*i+1]);
  }
  
  public int minx(int l, int r){
      int min = Integer.MAX_VALUE;
      if(l >= r)return min;
      while(l != 0){
          int f = l&-l;
          if(l+f > r)break;
          int v = st[(H+l)/f];
          if(v < min)min = v;
          l += f;
      }
      
      while(l < r){
          int f = r&-r;
          int v = st[(H+r)/f-1];
          if(v < min)min = v;
          r -= f;
      }
      return min;
  }
  
  public int min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
  
  private int min(int l, int r, int cl, int cr, int cur)
  {
      if(l <= cl && cr <= r){
          return st[cur];
      }else{
          int mid = cl+cr>>>1;
          int ret = Integer.MAX_VALUE;
          if(cl < r && l < mid){
              ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
          }
          if(mid < r && l < cr){
              ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
          }
          return ret;
      }
  }
  
  public int firstle(int l, int v) {
      int cur = H+l;
      while(true){
          if(st[cur] <= v){
              if(cur < H){
                  cur = 2*cur;
              }else{
                  return cur-H;
              }
          }else{
              cur++;
              if((cur&cur-1) == 0)return -1;
              if((cur&1)==0)cur>>>=1;
          }
      }
  }
  
  public int lastle(int l, int v) {
      int cur = H+l;
      while(true){
          if(st[cur] <= v){
              if(cur < H){
                  cur = 2*cur+1;
              }else{
                  return cur-H;
              }
          }else{
              if((cur&cur-1) == 0)return -1;
              cur--;
              if((cur&1)==1)cur>>>=1;
          }
      }
  }
}

class FastScanner {
  public static String debug = null;

  private final InputStream in = System.in;
  private int ptr = 0;
  private int buflen = 0;
  private byte[] buffer = new byte[1024];
  private boolean eos = false;

  private boolean hasNextByte() {
    if (ptr < buflen) {
      return true;
    } else {
      ptr = 0;
      try {
        if (debug != null) {
          buflen = debug.length();
          buffer = debug.getBytes();
          debug = "";
          eos = true;
        } else {
          buflen = in.read(buffer);
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
      if (buflen < 0) {
        eos = true;
        return false;
      } else if (buflen == 0) {
        return false;
      }
    }
    return true;
  }

  private int readByte() {
    if (hasNextByte())
      return buffer[ptr++];
    else
      return -1;
  }

  private static boolean isPrintableChar(int c) {
    return 33 <= c && c <= 126;
  }

  private void skipUnprintable() {
    while (hasNextByte() && !isPrintableChar(buffer[ptr]))
      ptr++;
  }

  public boolean isEOS() {
    return this.eos;
  }

  public boolean hasNext() {
    skipUnprintable();
    return hasNextByte();
  }

  public String next() {
    if (!hasNext())
      throw new NoSuchElementException();
    StringBuilder sb = new StringBuilder();
    int b = readByte();
    while (isPrintableChar(b)) {
      sb.appendCodePoint(b);
      b = readByte();
    }
    return sb.toString();
  }

  public long nextLong() {
    if (!hasNext())
      throw new NoSuchElementException();
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
    while (true) {
      if ('0' <= b && b <= '9') {
        n *= 10;
        n += b - '0';
      } else if (b == -1 || !isPrintableChar(b)) {
        return minus ? -n : n;
      } else {
        throw new NumberFormatException();
      }
      b = readByte();
    }
  }

  public int nextInt() {
    return (int) nextLong();
  }

  public long[] nextLongList(int n) {
    return nextLongTable(1, n)[0];
  }

  public int[] nextIntList(int n) {
    return nextIntTable(1, n)[0];
  }

  public long[][] nextLongTable(int n, int m) {
    long[][] ret = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextLong();
      }
    }
    return ret;
  }

  public int[][] nextIntTable(int n, int m) {
    int[][] ret = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret[i][j] = nextInt();
      }
    }
    return ret;
  }
}