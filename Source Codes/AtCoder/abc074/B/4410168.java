import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  int a=0;
  for(int i=0;i<n;i++){
    int po=sc.nextInt();
  a+=Math.min(po,m-po);
  }
  System.out.println(a*2);
}
}