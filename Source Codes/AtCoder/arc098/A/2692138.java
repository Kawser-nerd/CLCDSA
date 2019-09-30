import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    char[] s = scanner.next().toCharArray();
    int cnt = 0;
    for (int i = 1; i < N; i++) {
      if (s[i] == 'E') cnt++;
    }
    int min = cnt;
    for (int i = 1; i < N; i++) {
      if (s[i - 1] == 'W') cnt++;
      if (s[i] == 'E') cnt--;
      if (cnt < min) min = cnt;
    }
    System.out.println(min);
  }
}