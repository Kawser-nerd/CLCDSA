import java.util.*;
public class Main{
  public static int sumOfDigits(int n){
    int sum = 0;
    while(n>0){
      sum+=n%10;
      n/=10;
    }
    return sum;
  }
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int ans = Integer.MAX_VALUE;
    for(int i=1;i<N;i++){
      int sumA = sumOfDigits(i);
      int sumB = sumOfDigits(N-i);
      if(ans>sumA+sumB)ans = sumA+sumB;
    }
    System.out.println(ans);
  }
}