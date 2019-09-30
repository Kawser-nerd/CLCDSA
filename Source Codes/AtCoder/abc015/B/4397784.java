import java.util.*;
public class Main{
public static void main(String[]args) {
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int count=0,sum=0;
  for(int i=0;i<n;i++){
    int a=sc.nextInt();
  if(a!=0){
  count++;sum+=a;
  }
  }
  System.out.println((int)(Math.ceil((double)sum/count)));
}	}