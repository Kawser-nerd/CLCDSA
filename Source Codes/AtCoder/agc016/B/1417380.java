import java.util.Scanner;

public class Main{
  static int n;
  static int[] a;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    int max = 0, min = n;
    for(int i = 0; i < n; i++){
      max = Math.max(max, a[i]);
      min = Math.min(min, a[i]);
    }

    if(max - min >= 2){
      System.out.println("No");
      return;
    }

    if(max == min){
      if(max == n - 1 || 2 * max <= n){
        System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }
    }
    else{
      int x = 0, y = 0;
      for(int i = 0; i < n; i++){
        if(a[i] == max){
          ++x;
        }
        if(a[i] == min){
          ++y;
        }
      }
      if(y < max && 2 * (max - y) <= x){
        System.out.println("Yes");
      }
      else{
        System.out.println("No");
      }
    }
  }
}