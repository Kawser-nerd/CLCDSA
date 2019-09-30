import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  int po[]=new int[n];
  for(int i=0;i<m;i++){
  int a=sc.nextInt()-1;
    int b=sc.nextInt()-1;
    int c=sc.nextInt();
    for(int j=a;j<=b;j++)po[j]=c;
  }
  for(int i=0;i<n;i++)
  System.out.println(po[i]);
}
}