import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String po=sc.nextLine();
  int size=po.length()-2;
  System.out.println(po.substring(0,1)+size+po.substring(po.length()-1));
}}