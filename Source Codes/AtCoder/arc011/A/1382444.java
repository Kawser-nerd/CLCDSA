import java.util.*;

public class Main{
  public static void main(String[] args){
    int m,n,N,sum,rest;

    Scanner sc = new Scanner(System.in);
    m=sc.nextInt();
    n=sc.nextInt();
    N=sc.nextInt();
    sum=N;
    while(N>=m){
      sum+=(N/m)*n;
      rest=N%m;
      N=(N/m)*n + rest;
    }
    System.out.println(sum);
    sc.close();
  }
}