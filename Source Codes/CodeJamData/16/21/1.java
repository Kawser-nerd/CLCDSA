import java.io.*;
import java.util.*;

public class getdigits {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String NAME = "A-large";
  public static String[] nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  public static int[][] counts;

  private static void main2() throws IOException {
    char[] x = in.next().toCharArray();
    int[] freq = new int[26];
    for (char c : x) {
      freq[c-'A']++;
    }
    int[] n = new int[10];
    n[0] = freq['Z'-'A'];
    for (char c : nums[0].toCharArray()) freq[c-'A'] -= n[0];
    n[6] = freq['X'-'A'];
    for (char c : nums[6].toCharArray()) freq[c-'A'] -= n[6];
    n[2] = freq['W'-'A'];
    for (char c : nums[2].toCharArray()) freq[c-'A'] -= n[2];
    n[4] = freq['U'-'A'];
    for (char c : nums[4].toCharArray()) freq[c-'A'] -= n[4];
    n[5] = freq['F'-'A'];
    for (char c : nums[5].toCharArray()) freq[c-'A'] -= n[5];
    n[8] = freq['G'-'A'];
    for (char c : nums[8].toCharArray()) freq[c-'A'] -= n[8];
    n[3] = freq['H'-'A'];
    for (char c : nums[3].toCharArray()) freq[c-'A'] -= n[3];
    n[1] = freq['O'-'A'];
    for (char c : nums[1].toCharArray()) freq[c-'A'] -= n[1];
    n[7] = freq['V'-'A'];
    for (char c : nums[7].toCharArray()) freq[c-'A'] -= n[7];
    n[9] = freq['I'-'A'];
    for (char c : nums[9].toCharArray()) freq[c-'A'] -= n[9];
    for (int i = 0; i <= 9; i++) {
      while(n[i]-->0) out.print((char)('0'+i));
    }
    out.println();
    
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
