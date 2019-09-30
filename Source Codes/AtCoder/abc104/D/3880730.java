import java.util.Scanner;
class Main{
  public static void main(String[] args){
  	Scanner sc = new Scanner(System.in);
    String S = sc.next();
    StringBuffer sb = new StringBuffer(S);
    S = sb.reverse().toString();
    String[] T = S.split("");
    long C = 0;
    long BC = 0;
    long ABC = 0;
    long AB = 1;
    long X = 1;
    for (String i: T){
      if ("?".equals(i)) {
        ABC = (ABC * 3 + BC) % 1000000007;
        BC = (BC * 3 + C) % 1000000007;
        C = (C * 3 + X) % 1000000007;
        X = (X * 3) % 1000000007;
      } else if ("C".equals(i)) {
        AB = 0;
        C += X;
      } else if ("B".equals(i)) {
        BC += C;
      } else if ("A".equals(i)) {
        ABC += BC;
      }
 	}
  	System.out.println(ABC % 1000000007);
  }
}