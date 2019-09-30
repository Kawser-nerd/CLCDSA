import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt();
    int b = scan.nextInt();
    int c = scan.nextInt();
    int x = scan.nextInt();
    int y = scan.nextInt();

    long ans = Long.MAX_VALUE;

//x,y<=10^5??????k=2*10^5
    for(int k = 0; k <= 100000; k++){
      long sum = c*2*k + a*Math.max(x-k, 0) + b*Math.max(y-k, 0);
      ans = Math.min(ans, sum);
    }

    System.out.println(ans);
  }
}