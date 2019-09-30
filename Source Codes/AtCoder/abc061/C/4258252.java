import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    long[] array = new long[100001];
    for(int i = 0; i < n; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      array[a] += b;
    }
    long sum = 0;
    for(int i = 1; i <= 100000; i++){
      sum += array[i];
      if(sum >= k){
        System.out.println(i);
        break;
      }
    }
  }
}