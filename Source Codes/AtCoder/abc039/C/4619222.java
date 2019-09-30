import java.util.*;
public class Main{
public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  String po=sc.nextLine().substring(0,12);
  if(po.equals("WBWBWWBWBWBW"))System.out.println("Do");
  else if(po.equals("WBWWBWBWBWWB"))System.out.println("Re");
  else if(po.equals("WWBWBWWBWBWB"))System.out.println("Si");
  else if(po.equals("WWBWBWBWWBWB"))System.out.println("Mi");
  else if(po.equals("WBWBWBWWBWBW"))System.out.println("Fa");
  else if(po.equals("WBWBWWBWBWWB"))System.out.println("So");
  else if(po.equals("WBWWBWBWWBWB"))System.out.println("La");
}
}