package r1a;

import java.util.Scanner;

public class A {
  static long gcd(long a , long b){
    if(b == 0)return a;
    return gcd(b , a % b);
  }
  
  static boolean solve(long N , long PD , long PG){
    long dcoeff = 100 / gcd(100 , PD);
    long gcoeff = 100 / gcd(100 , PG);
    long dw = dcoeff * PD / 100;
    long gw = gcoeff * PG / 100;
    long dl = dcoeff - dw;
    long gl = gcoeff - gw;
//    System.out.println(dw+" "+gw+" "+dl+" "+gl);
    if(gw == 0 && dw != 0)return false;
    if(gl == 0 && dl != 0)return false;
    if(dcoeff > N)return false;
    return true;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      long N = sc.nextLong();
      int PD = sc.nextInt();
      int PG = sc.nextInt();
      if(solve(N, PD, PG)){
        System.out.printf("Case #%d: Possible\n", cn);
      }else{
        System.out.printf("Case #%d: Broken\n", cn);        
      }
    }
  }
}
