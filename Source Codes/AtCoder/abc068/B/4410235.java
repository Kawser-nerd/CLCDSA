import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int a=sc.nextInt();
  int i;
  for(i=0;Math.pow(2,i+1)<=a;i++){}
    System.out.println((int)Math.pow(2,i));
}
}