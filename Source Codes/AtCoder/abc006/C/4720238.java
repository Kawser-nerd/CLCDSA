import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  int m=sc.nextInt();
  if(n*2>m||n*4<m){
  	System.out.println("-1 -1 -1");
  }
  else{
  	if(3*n<=m){
    System.out.println("0 "+(4*n-m)+" "+(m-3*n));
    }
    else{
    System.out.println((3*n-m)+" "+(m-2*n)+" 0");
    }
  }
}
}