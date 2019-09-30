/**
 * Created at 0:51 on 2019/03/08
 */

import java.awt.*;
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {

  static FastScanner sc = new FastScanner();

  static int H, W;

  public static void main(String[] args) {

    H = sc.nextInt();
    W = sc.nextInt();

    int[][] board = new int[H][W];

    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        board[i][j] = sc.nextInt() % 2;
      }
    }

    ArrayList<String> commands = new ArrayList();
    Point p = new Point(0, 0);
    Point next;
    while((next = move(p.x, p.y)) != null) {
      if (board[p.y][p.x] == 1) {
        board[next.y][next.x] = (board[next.y][next.x] + 1) % 2;
        commands.add(command(p.y, p.x, next.y, next.x));
      }
      p = next;
    }

    System.out.println(commands.size());
    for (int i=0; i<commands.size(); i++) {
      System.out.println(commands.get(i));
    }

  }

  static int dir = 1;
  static Point move(int x, int y) {
    Point next = new Point(x, y);
    if ((dir == 1 && x == W - 1) || (dir == -1 && x == 0)) {
      next.y += 1;
      dir *= -1;
      if (next.y >= H) {
        return null;
      }
    } else {
      next.x += dir;
    }
    return next;
  }

  static String command(int y1, int x1, int y2, int x2) {
    return (y1+1) + " " + (x1+1) + " " + (y2+1) + " " + (x2+1);
  }

  static class Debugger {

    static long startTime;
    static boolean on = true;

    //????????????(??????????????)
    static void start() {
      startTime = System.currentTimeMillis();
    }

    static void printTime() {
      if (on) System.out.println("(" + (System.currentTimeMillis() - startTime) + "ms)");
    }

    static void toggle() {
      on = !on;
    }

  }

  static class BigInt extends BigInteger {

    BigInteger MOD = new BigInteger("1000000007");

    public BigInt(long l) {
      super(Long.toString(l));
    }

    public BigInt mod() {
      return (BigInt) super.mod(MOD);
    }

    public BigInt add(long l) {
      return add(new BigInt(l));
    }

    public BigInt add(BigInt i) {
      return (BigInt) super.add(i);
    }

    public BigInt subtract(long l) {
      return subtract(new BigInt(l));
    }

    public BigInt subtract(BigInt i) {
      return (BigInt) super.subtract(i);
    }

    public BigInt multiply(long l) {
      return multiply(new BigInt(l));
    }

    public BigInt multiply(BigInt i) {
      return (BigInt) super.multiply(i);
    }

    public BigInt divide(long l) {
      return divide(new BigInt(l));
    }

    public BigInt divide(BigInt i) {
      return (BigInt) super.divide(i);
    }

    public BigInt abs() {
      return (BigInt) super.abs();
    }

  }

  /*
    add()????????????????????????????????????
    (???????????????????)
    Comparator?0???????????????????
    (TreeSet, TreeMap?????????)
   */
  static class TreeList<E> extends ArrayList<E> {

    Comparator<? super E> comparator;

    TreeList(Comparator<? super E> c) {
      super();
      comparator = c;
    }

    /*
      ?????????????????
     */
    public boolean add(E e) {
      int lowIndex = 0;
      int highIndex = size() - 1;
      int index = 0;

      if (size() == 0) {
        super.add(e);
        return true;
      }

      if (comparator.compare(e, get(0)) < 0) {
        index = 0;
      } else if (comparator.compare(e, get(highIndex)) > 0) {
        index = highIndex + 1;
      } else {
        while (lowIndex <= highIndex) {

          if (highIndex == lowIndex + 1 || highIndex == lowIndex) {
            index = highIndex;
            break;
          }

          int midIndex = (lowIndex + highIndex) / 2;
          ;

          if (comparator.compare(e, get(midIndex)) > 0) {
            lowIndex = midIndex;
          } else {
            highIndex = midIndex;
          }

        }
      }

      super.add(index, e);
      return true;
    }

  }

  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
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

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
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
  }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.