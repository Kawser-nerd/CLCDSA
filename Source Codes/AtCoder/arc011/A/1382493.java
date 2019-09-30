import java.util.Scanner;
public class Main{
  public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int m = sc.nextInt();
  int n = sc.nextInt();
  int N = sc.nextInt();
  int sum=N;
  int e;
  while(N>=m){
      e = N%m;
      sum += (N-e)/m*n;
      N = e+(N-e)/m*n;
  }
  System.out.println(sum);
    }
}