import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long h = sc.nextLong();
    long[] a = new long[n];
    long[] b = new long[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextLong();
      b[i] = sc.nextLong();
    }
    Arrays.sort(a);
    Arrays.sort(b);

    long count = 0;
    for(int i = b.length - 1; i >= 0; i--){
      if(b[i] <= a[a.length - 1]) break;
      h -= b[i];
      count++;
      if(h <= 0){
        System.out.println(count);
        System.exit(0);
      }
    }
    
    System.out.println(count + (long)Math.ceil(h / (double)a[a.length - 1]));
  }
}