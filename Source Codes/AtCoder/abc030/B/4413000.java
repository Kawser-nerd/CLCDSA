import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  double po=Math.abs((double)(sc.nextInt()%12)*30-(double)sc.nextInt()*(11.0/2));
System.out.println(Math.min(po,360.0-po));   
}}