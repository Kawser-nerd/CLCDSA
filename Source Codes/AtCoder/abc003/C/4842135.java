import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    Integer arr[] = new Integer[N];

    double r = 0;

    for (int i = 0; i < N; i++) {
      arr[i] = sc.nextInt();
    }
    Arrays.sort(arr,Comparator.reverseOrder());

    for (int j = K - 1; 0 <= j; j--){
      r = (r + (double) arr[j]) / 2;
    }

    System.out.println(r);
  }
}