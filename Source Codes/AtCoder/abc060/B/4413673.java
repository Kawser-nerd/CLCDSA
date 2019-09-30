import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int a=sc.nextInt();
  int b=sc.nextInt();
  int c=sc.nextInt();
  boolean po=false;
  for(int i=1;i<=b;i++){
  	if((a*i)%b==c)po=true;
  }
  System.out.println(po?"YES":"NO");
  }}