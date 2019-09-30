import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  long n=Long.parseLong(sc.next());
  long a=Long.parseLong(sc.next());
  n-=1;
  long ans=a;
  for(int i=0;i<n;i++)ans*=(a-1);
  System.out.println(ans);
}
}