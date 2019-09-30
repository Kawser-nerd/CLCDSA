import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();

  public static void main(String[] args) {

    int N = sc.nextInt(); //???
    int M = sc.nextInt(); //???

    ArrayList<Integer[]>[] prefectures = new ArrayList[N]; //[0] ???? [1] ?
    for (int i = 0; i < N; i++) {
      prefectures[i] = new ArrayList();
    }

    for (int i = 0; i < M; i++) {
      int p = sc.nextInt() - 1;
      int y = sc.nextInt();
      if (prefectures[p].size() == 0) {
        prefectures[p].add(new Integer[]{i, y});
        continue;
      }

      int lowIndex = 0;
      int highIndex = prefectures[p].size()-1;
      int index = 0;

      if (y < prefectures[p].get(0)[1]) {
        index = 0;
      } else if (y > prefectures[p].get(highIndex)[1]) {
        index = highIndex + 1;
      } else {
        while (lowIndex <= highIndex) {

          if (highIndex == lowIndex + 1) {
            index = highIndex;
            break;
          }

          int midIndex = (lowIndex + highIndex) / 2;

          int midY = prefectures[p].get(midIndex)[1];

          if (midY < y) {
            lowIndex = midIndex;
          } else {
            highIndex = midIndex;
          }

        }
      }

      prefectures[p].add(index, new Integer[]{i, y});

    }

    String[] ids = new String[M];
    for (int i = 0; i < N; i++) {
      ListIterator<Integer[]> iterator = prefectures[i].listIterator();
      while(iterator.hasNext()) {
        Integer[] city = iterator.next();
        ids[city[0]] = padding0(i + 1, 6) + padding0(iterator.nextIndex(), 6);
      }
    }

    for (int i = 0; i < M; i++) {
      System.out.println(ids[i]);
    }

  }

  static String padding0(int n, int m) {
    String s = Integer.toString(n);
    while (m - s.length() > 0) s = "0" + s;
    return s;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.