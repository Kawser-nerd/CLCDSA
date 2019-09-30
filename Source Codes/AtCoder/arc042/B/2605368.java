import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int i, j;
    double p, q, n, a, b, c, d, ans;
    int pX[] = new int[12];
    int pY[] = new int[12];
    ans=10000000;
    p = sc.nextInt();
    q = sc.nextInt();
    n = sc.nextInt();
    for(i=0;i<n;i++){
      pX[i] = sc.nextInt();
      pY[i] = sc.nextInt();
    }

    for(i=0;i<n;i++){
      j=(i<n-1)?i+1:0;
      a=pX[j]-pX[i];
      b=pY[j]-pY[i];
      c = Math.sqrt(a*a+b*b);
      d=(a*(q-pY[i])+b*(pX[i]-p))/c;
      d=(d>=0)?d:-d;
      if(ans>d)ans=d;
    }
    System.out.println(ans);
  }
}