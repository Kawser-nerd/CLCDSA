import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  long ans=1;
  for(int i=0;i<n;i++){
  ans*=(i+1);
    ans%=1000000007;
  }System.out.println(ans);
}
}