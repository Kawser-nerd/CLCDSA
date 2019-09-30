import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String a=sc.nextLine();
  Map<String,Integer> p=new HashMap<String,Integer>();
  p.put("A",1);p.put("B",2);p.put("C",3);p.put("D",4);p.put("E",5);
  System.out.println(p.get(a));
}}