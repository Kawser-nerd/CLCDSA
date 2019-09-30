import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] l = new int[n];
    for (int i = 0; i < n; i++) {
      l[i] = scanner.nextInt();
    }
    scanner.close();
    int max = 0;
    for (int i = 0; i < n; i++) {
      if (max < l[i]) {
        max = l[i];
      }
    }
    if (n == 1) {
      System.out.println(max);
      return;
    }
    int count = 0;
    for (int i = max; i > 0; i--) {
      for (int j = 0; j < n - 1; j++) {
        if (l[j] == i) {
          if (l[j + 1] == i) {
            l[j]--;
          } else {
            l[j]--;
            count++;
          }
        }
      }
      if (l[n - 1] == i) {
        l[n - 1]--;
        count++;
      }
    }
    System.out.println(count);

  }

}