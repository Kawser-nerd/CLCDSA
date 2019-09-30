import java.util.*;
public class Main{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int p[]=new int[n];
  int sum=0;
  for(int i=0;i<n;i++){p[i]=sc.nextInt();sum+=p[i];}
  int m=sc.nextInt();
  for(int i=0;i<m;i++){
  	int a=sc.nextInt();
    int b=sc.nextInt();
    System.out.println(sum-p[a-1]+b);
  }
}
}