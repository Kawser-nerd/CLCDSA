import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      int[] a = new int[N];
      int[] b = new int[N];
      for(int i = 0; i<N; i++) a[i] = Integer.parseInt(sc.next());
      for(int i = 0; i<N; i++) b[i] = Integer.parseInt(sc.next());
      for(int i = 1; i<N; i++) a[i] = a[i]+a[i-1];
      for(int i = N-2; i>=0; i--) b[i] = b[i]+b[i+1];
      int sum = Integer.MIN_VALUE/2;
      for(int i = 0; i<N; i++) sum = Math.max(sum, a[i]+b[i]);
      System.out.println(sum);
  }
}