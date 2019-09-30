import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long r = 0;
    long[] arr = new long[n];

    for (int i = 0; i < n; i++){
      if(i < 2){
        arr[i] = 0;
      } else if(i == 2){
        arr[i] = 1;
      } else {
        arr[i] = (arr[i-3] + arr[i-2] + arr[i-1] ) % 10007;
      }
      r = arr[i];
    }

    System.out.println(r);
    
  }
}