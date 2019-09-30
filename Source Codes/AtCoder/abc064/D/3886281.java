import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    char[] s = scanner.next().toCharArray();

    int left = 0;
    int tmp = 0;
    for(char ch : s) {
      if (ch == '(') tmp--;
      else tmp++;
      left = Math.max(left, tmp);
    }
    int right = 0;
    tmp = 0;
    for (int i = N - 1; i >= 0; i--) {
      char ch = s[i];
      if (ch == ')') tmp--;
      else tmp++;
      right = Math.max(right, tmp);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < left; i++) sb.append('(');
    sb.append(s);
    for (int i = 0; i < right; i++) sb.append(')');
    System.out.println(sb.toString());
  }
}