import java.util.*;
import java.lang.*;

class Main{
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int N = Integer.parseInt(sc.next());
      int[] a = new int[N+2];
      a[0] = 0;
      a[N+1] = 0;
      long sum = 0;
      for(int i = 1; i<N+1; i++){
        a[i] = Integer.parseInt(sc.next());
        sum += Math.abs(a[i] - a[i-1]);
        if(i == N) sum += Math.abs(a[i]);
      }
      long tmp  = sum;
      for(int i = 1; i<N+1; i++){
        tmp -= Math.abs(a[i]-a[i-1]);
        tmp -= Math.abs(a[i+1]-a[i]);
        tmp += Math.abs(a[i+1]-a[i-1]);
        System.out.println(tmp);
        tmp = sum;
      }
  }
}