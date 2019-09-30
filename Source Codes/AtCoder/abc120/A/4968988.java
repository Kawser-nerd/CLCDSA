import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int ans;
    if(B >= A * C){
      ans = C;
    } else {
      ans = (int) B / A;
    }
    System.out.println(ans);
  }
}