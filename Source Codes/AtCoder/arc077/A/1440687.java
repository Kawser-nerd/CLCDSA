import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    int i = 0;
    for(i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }

    for (i = n-1; i >= 0; i -= 2) {
      System.out.print(a[i] + " ");
    }
    if(i == -2) {
      for (i = 1; i < n; i += 2) {
        System.out.print(a[i] + " ");
      }
    }else if(i == -1) {
      for (i = 0; i < n; i += 2) {
        System.out.print(a[i] + " ");
      }
    }
    System.out.println();
  }
}