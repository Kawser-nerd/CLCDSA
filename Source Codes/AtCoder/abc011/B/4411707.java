import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String s=sc.next();
  char po[]=s.toCharArray();
  for(int i=0;i<po.length;i++)
    if(i==0)System.out.print((po[i]<96)?(char)po[i]:(char)(po[i]-32));
  else System.out.print((po[i]<96)?(char)(po[i]+32):(char)po[i]);
  System.out.println();
}}