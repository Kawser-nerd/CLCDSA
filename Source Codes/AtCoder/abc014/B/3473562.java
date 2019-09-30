import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int X = scanner.nextInt();
    int[] a = new int[n];
    int[] bit = new int[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
    }
    for(int i = n-1; i >=0; i--){
      bit[i] = X%2;
      X = X/2;
    }
    for(int i = 0; i<n; i++){
      if(bit[i]==1){
        sum += a[n-1-i];
      }
    }
    System.out.println(sum);
  }
}