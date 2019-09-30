import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();int m=sc.nextInt();int x=sc.nextInt();
  int po[]=new int[n+1];
  for(int i=0;i<m;i++){
  po[sc.nextInt()]++;
  }
  int r=0,l=0;
  for(int i=x;i<=n;i++){
  	r+=po[i];
  }
  for(int i=0;i<=x;i++){
  	l+=po[i];
  }
  System.out.println(Math.min(r,l));
}
}