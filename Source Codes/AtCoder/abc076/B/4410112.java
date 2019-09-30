import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  int a=1;
  for(int i=0;i<n;i++){
  a=(a<m)?a*2:a+m;
  }
  System.out.println(a);
}
}