import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String po=sc.next();
  po=po.replace("ch","");
  po=po.replace("o","");
  po=po.replace("k","");
  po=po.replace("u","");
  System.out.println((po.equals(""))?"YES":"NO");
 }}