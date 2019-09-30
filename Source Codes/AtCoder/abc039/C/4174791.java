import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    char[] s = scanner.next().toCharArray();
    String[] a = new String[] {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
    int w1 = -1, w2 = -1;
    for (int i = 0; i < s.length - 1; i++) {
      if (s[i] == 'W' && s[i + 1] == 'W') {
        if (w1 < 0) w1 = i;
        else if (w2 < 0) w2 = i;
      }
    }
    if (w2 - w1 == 7) {
      System.out.println(a[2 - w1 / 2]);
    } else {
      System.out.println(a[6 - w1 / 2]);
    }
  }
}