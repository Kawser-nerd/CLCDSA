import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
  int d=sc.nextInt();
  int x=sc.nextInt();
  int po[]=new int[n];
  for(int i=0;i<n;i++){
  po[i]=sc.nextInt();
  }
  int ans=n;
  d--;
  for(int i=0;i<n;i++){
  ans+=d/po[i];
  }
  System.out.println(ans+x);
}
}