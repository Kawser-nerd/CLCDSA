import java.util.Scanner;

public class Main{
  static int n;
  static int[] a;
  static final int MAX = 100000;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    int[] count = new int[MAX + 1 + 1];
    for(int i = 0; i < n; i++){
      int v = a[i] + 1;
      ++count[v];
      ++count[v + 1];
      ++count[v - 1];
    }

    int max = 0;
    for(int i = 0; i < count.length; i++){
      max = Math.max(max, count[i]);
    }

    System.out.println(max);
  }
}