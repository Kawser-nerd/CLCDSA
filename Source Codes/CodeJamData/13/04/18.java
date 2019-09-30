import java.io.*;
import java.util.*;

public class Treasure {
  // <editor-fold defaultstate="collapsed" desc="Input/Output Class">
  private static class In {
    //  Constant
    private static final int BUFFER_SIZE = (1 << 20);
    private static final int LINE_SIZE = (1 << 20);

    //  Attribute
    private static InputStream in;
    private static byte[] buffer;
    private static char[] temp;
    private static int pos;
    private static int size;
    
    //  Initialization
    static {
      try {
        in = new BufferedInputStream(new FileInputStream("C:/Users/A/Desktop/data.in"));
        buffer = new byte[BUFFER_SIZE];
        temp = new char[LINE_SIZE];
        pos = 0;
        size = 0;
      } catch (FileNotFoundException ex) {
        throw new RuntimeException(ex);
      }
    }

    //  Method
    public static int nextInt() throws IOException {
      int ret = 0;
      boolean isNumber = false;
      boolean isNegative = false;

      try {
        byte c;

        //  Skip Blank
        do {
          c = read();
        } while (c <= ' ');

        //  Valid Number
        isNumber = true;

          //  Negative
        if (c == '-') {
          isNegative = true;
          c = read();
        }

          //  Number
        do {
          ret = ret * 10 + c - '0';
          c = read();
        } while (c > ' ');
      } catch (EOFException e) {
      }

      return isNumber ? (isNegative ? -ret : ret) : -1;
    }

    public static long nextLong() throws IOException {
      long ret = 0;
      boolean isNumber = false;
      boolean isNegative = false;

      try {
        byte c;

        //  Skip Blank
        do {
          c = read();
        } while (c <= ' ');

        //  Valid Number
        isNumber = true;

          //  Negative
        if (c == '-') {
          isNegative = true;
          c = read();
        }

        //  Number
        do {
          ret = ret * 10 + c - '0';
          c = read();
        } while (c > ' ');
      } catch (EOFException e) {
      }

      return isNumber ? (isNegative ? -ret : ret) : -1L;
    }

    public static double nextDouble() throws IOException {
      double ret = 0;
      boolean isNumber = false;
      boolean isNegative = false;

      try {
        byte c;

        //  Skip Blank
        do {
          c = read();
        } while (c <= ' ');

        //  Valid Number
        isNumber = true;

          //  Negative
        if (c == '-') {
          isNegative = true;
          c = read();
        }

          //  Number
        do {
          ret = ret * 10 + c - '0';
          c = read();
        } while (c >= '0' && c <= '9');

          //  Decimal Point
        if (c == '.') {
          double mul = 0.1;

          while ((c = read()) > ' ') {
            ret += (c - '0') * mul;
            mul *= 0.1;
          }
        }
      } catch (EOFException e) {
      }

      return isNumber ? (isNegative ? -ret : ret) : -1.0;
    }

    public static char nextChar() throws IOException {
      try {
        return (char) read();
      } catch (EOFException e) {
        return (char) -1;
      }
    }
    
    public static char[] nextCharArray() throws IOException {
      int length = 0;

      try {
        byte c;

        //  Skip Blank
        do {
          c = read();
        } while (c <= ' ');

        //  Valid String
        do {
          if (length == temp.length) {
            char[] temp2 = temp;
            
            temp = new char[length*2];
            
            System.arraycopy(temp2, 0, temp, 0, length);
          }
          
          temp[length] = (char) c;
          length++;

          c = read();
        } while (c > ' ');
      } catch (EOFException e) {
      }

      if (length > 0) {
        char[] ret = new char[length];
        
        System.arraycopy(temp, 0, ret, 0, length);
        
        return ret;
      } else {
        return null;
      }
    }
    
    public static char[] nextLine() throws IOException {
      boolean isEnd = false;
      int length = 0;

      try {
        byte c;

        while ((c = read()) != '\n' && c != '\r') {
          if (length == temp.length) {
            char[] temp2 = temp;
            
            temp = new char[length*2];
            
            System.arraycopy(temp2, 0, temp, 0, length);
          }
          
          temp[length] = (char) c;
          length++;
        }
      } catch (EOFException e) {
        isEnd = true;
      }
        
      //  Return
      if (length > 0 || !isEnd) {
        char[] ret = new char[length];

        System.arraycopy(temp, 0, ret, 0, length);

        return ret;
      } else {
        return null;
      }
    }
    
    private static byte read() throws IOException {
      if (pos == size) {
        fill();
      }

      return buffer[pos++];
    }

    private static void fill() throws IOException {
      if (pos > 0 && in.available() == 0) {
        throw new EOFException();
      }

      pos = 0;
      size = in.read(buffer, pos, BUFFER_SIZE);
    }
    
    //  Singleton
    private In() {
    }
  }

  private static class Out {
    //  Constant
    private static final int BUFFER_SIZE = (1 << 20);
    private static final int NUMBER_SIZE = (1 << 12);

      //  Boolean
    private static final char[] TRUE = {'t', 'r', 'u', 'e'};
    private static final char[] FALSE = {'f', 'a', 'l', 's', 'e'};

      //  Integer, Long
    private static final char[] INT_MIN_VALUE 
        = {'-', '2', '1', '4', '7', '4', '8', '3', '6', '4', '8'};
    private static final char[] LONG_MIN_VALUE 
        = {'-', '9', '2', '2', '3', '3', '7', '2', '0', '3', '6', '8', '5', '4', '7', '7', '5', '8', 
          '0', '8'};
    private static final int[] INT_SIZE_TABLE 
        = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, Integer.MAX_VALUE};
    private static final char[] DIGIT_TENS = {
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
      '2', '2', '2', '2', '2', '2', '2', '2', '2', '2',
      '3', '3', '3', '3', '3', '3', '3', '3', '3', '3',
      '4', '4', '4', '4', '4', '4', '4', '4', '4', '4',
      '5', '5', '5', '5', '5', '5', '5', '5', '5', '5',
      '6', '6', '6', '6', '6', '6', '6', '6', '6', '6',
      '7', '7', '7', '7', '7', '7', '7', '7', '7', '7',
      '8', '8', '8', '8', '8', '8', '8', '8', '8', '8',
      '9', '9', '9', '9', '9', '9', '9', '9', '9', '9',
    };
    private static final char[] DIGIT_ONES = {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    };
    private static final char[] DIGITS = {
      '0' , '1' , '2' , '3' , '4' , '5' ,
      '6' , '7' , '8' , '9' , 'a' , 'b' ,
      'c' , 'd' , 'e' , 'f' , 'g' , 'h' ,
      'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
      'o' , 'p' , 'q' , 'r' , 's' , 't' ,
      'u' , 'v' , 'w' , 'x' , 'y' , 'z'
    };

    private static int intStringSize(int x) {
      for (int i=0; ; i++) {
        if (x <= INT_SIZE_TABLE[i]) {
          return i+1;
        }
      }
    }

    private static void intGetChars(int i, int index, char[] buf) {
      int q, r;
      int charPos = index;
      char sign = 0;

      if (i < 0) {
        sign = '-';
        i = -i;
      }

      // Generate two digits per iteration
      while (i >= 65536) {
        q = i / 100;
        r = i - ((q << 6) + (q << 5) + (q << 2)); // really: r = i - (q * 100);
        i = q;
        buf [--charPos] = DIGIT_ONES[r];
        buf [--charPos] = DIGIT_TENS[r];
      }

      // Fall thru to fast mode for smaller numbers
      do {
        q = (i * 52429) >>> (16+3);
        r = i - ((q << 3) + (q << 1));  // r = i-(q*10) ...
        buf [--charPos] = DIGITS [r];
        i = q;
      } while (i != 0);

      if (sign != 0) {
        buf [--charPos] = sign;
      }
    }

    private static int longStringSize(long x) {
      long p = 10;

      for (int i=1; i<19; i++) {
        if (x < p) {
          return i;
        }

        p *= 10;
      }

      return 19;
    }

    private static void longGetChars(long i, int index, char[] buf) {
      long q;
      int r;
      int charPos = index;
      char sign = 0;

      if (i < 0) {
        sign = '-';
        i = -i;
      }

      // Get 2 digits/iteration using longs until quotient fits into an int
      while (i > Integer.MAX_VALUE) {
        q = i / 100;
        r = (int)(i - ((q << 6) + (q << 5) + (q << 2)));  // really: r = i - (q * 100);
        i = q;
        buf[--charPos] = DIGIT_ONES[r];
        buf[--charPos] = DIGIT_TENS[r];
      }

      // Get 2 digits/iteration using ints
      int q2;
      int i2 = (int) i;

      while (i2 >= 65536) {
        q2 = i2 / 100;
        r = i2 - ((q2 << 6) + (q2 << 5) + (q2 << 2)); // really: r = i2 - (q * 100);
        i2 = q2;
        buf[--charPos] = DIGIT_ONES[r];
        buf[--charPos] = DIGIT_TENS[r];
      }

      // Fall thru to fast mode for smaller numbers
      do {
        q2 = (i2 * 52429) >>> (16+3);
        r = i2 - ((q2 << 3) + (q2 << 1));  // r = i2-(q2*10) ...
        buf[--charPos] = DIGITS[r];
        i2 = q2;
      } while (i2 != 0);

      if (sign != 0) {
        buf[--charPos] = sign;
      }
    }

    //  Attribute
    private static OutputStream out;
    private static byte[] buffer = new byte[BUFFER_SIZE];
    private static char[] temp = new char[NUMBER_SIZE];
    private static int pos = 0;

    //  Initialization
    static {
      try {
        out = new BufferedOutputStream(new FileOutputStream("C:/Users/A/Desktop/data.out"));
        buffer = new byte[BUFFER_SIZE];
        temp = new char[NUMBER_SIZE];
        pos = 0;
      } catch (FileNotFoundException ex) {
        throw new RuntimeException(ex);
      }
    }
    
    //  Method
    public static void print(int i) throws IOException {
      if (i == Integer.MIN_VALUE) {
        print(INT_MIN_VALUE);
      } else {
        int size = (i < 0 ? intStringSize(-i) + 1 : intStringSize(i));

        intGetChars(i, size, temp);

        print(temp, 0, size);
      }
    }

    public static void print(long l) throws IOException {
      if (l == Long.MIN_VALUE) {
        print(LONG_MIN_VALUE);
      } else {
        int size = (l < 0 ? longStringSize(-l) + 1 : longStringSize(l));

        longGetChars(l, size, temp);

        print(temp, 0, size);
      }
    }

    public static void print(double d) throws IOException {
      throw new UnsupportedOperationException();
    }

    public static void print(char c) throws IOException {
      write(c);
    }

    public static void print(boolean b) throws IOException {
      if (b) {
        print(TRUE);
      } else {
        print(FALSE);
      }
    }

    public static void print(String s) throws IOException {
      int len = s.length();
      int left = BUFFER_SIZE-pos;

      if (len <= left) {
        System.arraycopy(s.getBytes(), 0, buffer, pos, len);
        pos += len;
      } else {
        for (int i = 0; i < len; i++) {
          write(s.charAt(i));
        }
      }
    }

    public static void print(Object o) throws IOException {
      print(String.valueOf(o));
    }

    public static void println() throws IOException {
      print('\n');
    }

    public static void println(int i) throws IOException {
      print(i);
      println();
    }

    public static void println(long l) throws IOException {
      print(l);
      println();
    }

    public static void println(double d) throws IOException {
      print(d);
      println();
    }

    public static void println(char c) throws IOException {
      print(c);
      println();
    }

    public static void println(boolean b) throws IOException {
      print(b);
      println();
    }

    public static void println(String s) throws IOException {
      print(s);
      println();
    }

    public static void println(Object o) throws IOException {
      print(String.valueOf(o));
      println();
    }

    private static void print(char[] cs) throws IOException {
      print(cs, 0, cs.length);
    }

    private static void print(char[] cs, int from, int to) throws IOException {
      for (int i = from; i < to; i++) {
        write(cs[i]);
      }
    }

    private static void write(char c) throws IOException {
      //  Full Case
      if (pos >= BUFFER_SIZE) {
        flush();
      }

      //  Fill Data
      buffer[pos++] = (byte) c;
    }

    public static void flush() throws IOException {
      if (pos > 0) {
        out.write(buffer, 0, pos);
        out.flush();
      }

      pos = 0;
    }
    
    //  Singleton
    private Out() {
    }
  }
  // </editor-fold>

  public static void main(String[] args) throws Exception {
    int numTest = In.nextInt();

    for (int no = 0; no < numTest; no++) {
      //  Input
      int k = In.nextInt();
      int n = In.nextInt();
      
      int[] numKey = new int[400];
      
      for (int i = 0; i < k; i++) {
        numKey[In.nextInt()-1]++;
      }
      
      int[] usedKey = new int[n];
      int[][] givenKeys = new int[n][];
      
      for (int i = 0; i < n; i++) {
        usedKey[i] = In.nextInt()-1;
        givenKeys[i] = new int[In.nextInt()];
        
        for (int j = 0; j < givenKeys[i].length; j++) {
          givenKeys[i][j] = In.nextInt()-1;
        }
      }

      //  Solve
      int[] openKey = new int[n];
      
      Arrays.fill(openKey, -1);
      
      int[] sol 
          = solve(usedKey, givenKeys, numKey, openKey, new boolean[n], 0, new HashSet<String>());

      //  Output
      Out.print("Case #");
      Out.print(no+1);
      Out.print(':');
      Out.print(' ');
      
      if (sol == null) {
        Out.println("IMPOSSIBLE");
      } else {
        Out.print(sol[0]+1);
        
        for (int i = 1; i < n; i++) {
          Out.print(' ');
          Out.print(sol[i]+1);
        }
        
        Out.println();
      }
    }
    
    Out.flush();
  }
  
  private static int[] solve(
      int[] usedKey, int[][] givenKeys, int[] numKey, int[] openKey, boolean[] isOpen, int pos, 
      Set<String> visited) {
    String key = Arrays.toString(isOpen);
    
    if (visited.contains(key)) {
      return null;
    } else if (pos == openKey.length) {
      return openKey;
    } else {
      visited.add(key);
      
      for (int i = 0; i < openKey.length; i++) {
        if (!isOpen[i] && numKey[usedKey[i]] >= 1) {
          numKey[usedKey[i]]--;
          
          for (int j = 0; j < givenKeys[i].length; j++) {
            numKey[givenKeys[i][j]]++;
          }
          
          openKey[pos] = i;
          isOpen[i] = true;
          
          int[] ret = solve(usedKey, givenKeys, numKey, openKey, isOpen, pos+1, visited);
          
          if (ret != null) {
            return ret;
          }
          
          isOpen[i] = false;
          openKey[pos] = -1;
          
          for (int j = 0; j < givenKeys[i].length; j++) {
            numKey[givenKeys[i][j]]--;
          }
          
          numKey[usedKey[i]]++;
        }
      }
      
      return null;
    }
  }
}