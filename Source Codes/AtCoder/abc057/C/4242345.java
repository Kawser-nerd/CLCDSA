import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long N = sc.nextLong();
    long tmp = 1;
    for(int i = 2; i <= Math.sqrt(N); i++){
      if(N % i == 0){
        tmp = i;
      }
    }
    System.out.println(f(tmp, N/tmp));
  }
  
  public static int f(long a, long b){
    int cnt1 = 0;
    int cnt2 = 0;
    while(a != 0){
      cnt1++;
      a /= 10;
    }
    while(b != 0){
      cnt2++;
      b /= 10;
    }
    return Math.max(cnt1, cnt2);
  }
}