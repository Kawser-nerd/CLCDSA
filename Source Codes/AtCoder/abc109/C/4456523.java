import java.util.Scanner;
public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int X = sc.nextInt();
    int x[] = new int[N];
    int ans = 0;
    for(int i = 0;i < N;i++){
      x[i] = Math.abs(sc.nextInt() - X);
    }
    ans = x[0];
    for(int i = 1;i < N;i++){
      ans = gcd(ans,x[i]);
      if(ans == 1){
        break;
      }
    }
    System.out.println(ans);
  }
  static int gcd(int a,int b){
    if(a < b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b, a % b);
  }
}