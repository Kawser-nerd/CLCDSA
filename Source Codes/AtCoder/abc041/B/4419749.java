import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();int a=sc.nextInt();int b=sc.nextInt();
  long ans=n;
  ans=(ans*a)%1000000007;
  ans=(ans*b)%1000000007;
  System.out.println(ans);
}
}