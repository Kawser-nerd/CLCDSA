import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] change = new String[10];
    String[] dec = new String[10];
    for(int i = 0; i < 10; i++) {
      int b = sc.nextInt();
      change[b] = String.valueOf(i);
      dec[i] = String.valueOf(b);
    }
    int N = sc.nextInt();
    int[] a = new int[N];
    for(int i = 0; i < N; i++) {
      String d = String.valueOf(sc.nextInt());
      String num = "";
      for(int j = 0; j < d.length(); j++) {
        num += change[Integer.parseInt(String.valueOf(d.charAt(j)))];
      }
      a[i] = Integer.parseInt(num);
    }
    Arrays.sort(a);
    for(int i = 0; i < N; i++) {
      String d = String.valueOf(a[i]);
      String num = "";
      for(int j = 0; j < d.length(); j++) {
        num += dec[Integer.parseInt(String.valueOf(d.charAt(j)))];
      }
      System.out.println(num);
    }
  }
}