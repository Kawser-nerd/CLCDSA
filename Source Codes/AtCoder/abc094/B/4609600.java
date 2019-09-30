import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[] a = new int[m];
    for(int i = 0; i < m; i++){
      a[i] = sc.nextInt();
    }
    int num = ~Arrays.binarySearch(a, x);
    System.out.println(Math.min(num, m - num));
  }
}