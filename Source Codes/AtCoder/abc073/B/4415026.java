import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int a=sc.nextInt(),ans=a;
  for(int i=0;i<a;i++){
  ans+=-sc.nextInt()+sc.nextInt();
  }
  System.out.println(ans);
}}