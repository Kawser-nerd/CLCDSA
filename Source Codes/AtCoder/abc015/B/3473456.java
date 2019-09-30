import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] A = new int[N];
    int sum = 0;
    int count = 0;
    for(int i = 0; i < N; i++){
      A[i] = scanner.nextInt();
    }
    for(int i = 0; i < N; i++){
      if(A[i]!=0){
        sum += A[i];
        count++;
      }
    }
    System.out.println((sum+count-1)/count);
  }
}