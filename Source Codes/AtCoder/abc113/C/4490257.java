import java.io.IOException;
import java.io.InputStream;
import java.util.*;

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
        return minus ? -n : n;
      }else{
        throw new NumberFormatException();
      }
      b = readByte();
    }
  }
  public int nextInt() {
    return (int)nextLong();
  }
}

public class Main {

  static FastScanner sc = new FastScanner();

  public static void main(String[] args) {

    int N = sc.nextInt();
    int M = sc.nextInt();

    ArrayList<City> cities = new ArrayList();
    for (int i=0; i<M; i++) {
      cities.add(new City(i, sc.nextInt(), sc.nextInt()));
    }

    cities.sort((x, y) -> {
      if (x.p == y.p) {
        return x.y - y.y;
      } else {
        return x.p - y.p;
      }
    });

    String[] ids = new String[M];

    int count = 0;
    for (int i=0; i<M; i++) {
      City c = cities.get(i);
      if (i == 0 || c.p != cities.get(i-1).p) count = 0;
      else count++;
      ids[c.i] = padding0(c.p, 6) + padding0(count+1, 6);
    }

    for (int i=0; i<M; i++) {
      System.out.println(ids[i]);
    }

  }

  static String padding0(int n, int m) {
    String s = Integer.toString(n);
    while (m - s.length() > 0) s = "0" + s;
    return s;
  }


  static class City {
    int i, p, y;
    City (int i, int p, int y) {
      this.i = i;
      this.p = p;
      this.y = y;
    }
  }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.