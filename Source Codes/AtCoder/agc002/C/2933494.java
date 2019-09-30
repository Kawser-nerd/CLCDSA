import java.io.*;
import java.util.*;

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
    int l = cin.nextInt();
    int[] a = new int[n];

    for (int i = 0; i < n; ++i) {
      a[i] = cin.nextInt();
    }

    int p = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i-1] + a[i] >= l) {
        p = i;
        break;
      }
    }

    if (p == 0) {
      cout.printf("Impossible\n");
    } else {
      cout.printf("Possible\n");
      for (int i = 1; i < p; ++i) {
        cout.println(i);
      }
      for (int i = n-1; i >= p+1; --i) {
        cout.println(i);
      }
      cout.println(p);
    }
  }
}

class InputReader {
  private BufferedReader reader;
  private StringTokenizer tokenizer;
  private int BUFFER_SIZE = 32768;

  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), BUFFER_SIZE);
    tokenizer = null;
  }

  public boolean hasNext() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      String line;
      try {
        line = reader.readLine();
        if (line == null) {
          return false;
        }
        tokenizer = new StringTokenizer(line);
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return true;
  }

  public String next() {
    if (!hasNext()) {
      return null;
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(this.next());
  }
}