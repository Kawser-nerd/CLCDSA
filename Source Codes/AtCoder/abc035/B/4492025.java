/**
 * Created at 11:48 on 2019/03/07
 */

import java.io.*;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();

  public static void main(String[] args) {

    String S = sc.next();
    int T = sc.nextInt();

    int x = 0, y = 0;
    int q = 0; //???
    for (int i=0; i<S.length(); i++) {
      switch (S.charAt(i)) {
        case 'L':
          x--;break;
        case 'R':
          x++;break;
        case 'U':
          y++;break;
        case 'D':
          y--;break;
        case '?':
          q++;break;
      }
    }

    if (T == 1) {
      System.out.println(d(x, y) + q);
    } else if (T == 2) {
      if (d(x, y) >= q) {
        System.out.println(d(x, y) - q);
      } else {
        System.out.println((q - d(x, y)) % 2);
      }
    }

  }

  static int d(int x, int y) {
    return Math.abs(x) + Math.abs(y);
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

}