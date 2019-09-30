import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
  static Scanner sc = new Scanner(System.in);
  static int N;

  public static void main(String[] args) {
    System.out.println(solve());
  }

  static int solve() {
    char[] A = sc.next().toCharArray();
    char[] B = sc.next().toCharArray();
    N = A.length;
    int lastOnePos = N;
    for (int i = N - 1; i >= 0; i--) {
      if (B[i] == '1') {
        lastOnePos = i;
        break;
      }
    }
    if (lastOnePos == N) {
      for (char c : A) {
        if (c == '1') {
          return -1;
        }
      }
      return 0;
    }
    int ans = solve(A, B, lastOnePos);
    for (int i = 0; i < N / 2; i++) {
      char tmp = A[i];
      A[i] = A[N - 1 - i];
      A[N - 1 - i] = tmp;
      tmp = B[i];
      B[i] = B[N - 1 - i];
      B[N - 1 - i] = tmp;
    }
    for (int i = N - 1; i >= 0; i--) {
      if (B[i] == '1') {
        lastOnePos = i;
        break;
      }
    }
    return Math.min(ans, solve(A, B, lastOnePos));
  }

  static int solve(char[] A, char[] B, int lastOnePos) {
    int ans = N;
    for (int i = 0; i < N; i++) {
      if (A[i] != B[i]) ++ans;
    }
    int[] prevPos = new int[N];
    int[] nextPos = new int[N];
    int p = lastOnePos - N;
    for (int i = 0; i < N; i++) {
      if (B[i] == '1') p = i;
      prevPos[i] = p;
    }
    int n = 0;
    while (B[n] == '0') {
      ++n;
    }
    n += N;
    for (int i = N - 1; i >= 0; i--) {
      if (B[i] == '1') n = i;
      nextPos[i] = n;
    }
    ArrayList<Integer> rest = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      rest.clear();
      int diff = 0;
      for (int j = 0; j < N; j++) {
        if (A[j] != B[(j - i + N) % N]) {
          ++diff;
          if (j - prevPos[j] > i) {
            rest.add(((j - prevPos[j] - i) << 16) | (nextPos[j] - j));
          }
        }
      }
      int move;
      if (!rest.isEmpty()) {
        Collections.sort(rest);
        int[] revMax = new int[rest.size() + 1];
        for (int j = rest.size() - 1; j >= 0; j--) {
          revMax[j] = Math.max(revMax[j + 1], rest.get(j) & 0xFFFF);
        }
        move = revMax[0];
        for (int j = 0; j < rest.size(); j++) {
          move = Math.min(move, (rest.get(j) >> 16) + revMax[j + 1]);
        }
      } else {
        move = 0;
      }
//      System.out.println(rest);
//      System.out.println(i + " " + diff + " " + move);
      ans = Math.min(ans, diff + move * 2 + i);
    }
    return ans;
  }

}