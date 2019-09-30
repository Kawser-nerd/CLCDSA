import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String a=sc.nextLine();
int ans = Integer.parseInt(Integer.toBinaryString(Integer.parseInt(a)),2)-1;
  System.out.println(""+""+""+""+""+""+""+""+ans);
}}