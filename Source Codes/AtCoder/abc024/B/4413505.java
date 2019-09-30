import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int t=sc.nextInt();
  int po[]=new int[n];
  for(int i=0;i<n;i++){
    po[i]=sc.nextInt();
  }
  int ans=0;
  for(int i=1;i<n;i++){
  ans+=Math.min(po[i]-po[i-1],t);
  }
  System.out.println(ans+t);
  }}