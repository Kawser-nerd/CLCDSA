import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    InputReader cin = new InputReader(System.in);
    PrintWriter cout = new PrintWriter(System.out);

    Task task = new Task();
    task.run(cin, cout);

    cout.close();
  }
}

class Task {
  void run(InputReader cin, PrintWriter cout) {
    int n = cin.nextInt();
    int m = cin.nextInt();

    int[] n_ball = new int[n];
    boolean[] may_good = new boolean[n];

    Arrays.fill(n_ball, 1);
    Arrays.fill(may_good, false);
    may_good[0] = true;

    for (int i = 0; i < m; ++i) {
      int x = cin.nextInt() - 1;
      int y = cin.nextInt() - 1;
      n_ball[x] -= 1;
      n_ball[y] += 1;
      if (may_good[x]) {
        may_good[y] = true;
      }
      if (n_ball[x] == 0) {
        may_good[x] = false;
      }
    }

    int n_good = 0;
    for (int i = 0; i < n; ++i) {
      if (may_good[i]) {
        n_good += 1;
      }
    }

    cout.printf("%d\n", n_good);
  }
}

class InputReader {
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
    return Integer.parseInt(this.next());
  }
}