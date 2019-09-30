import java.util.*;
public class Main{public static void main(String[]args){
Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  Map<Integer,Integer>po=new HashMap<Integer,Integer>();
  int count=0;
  for(int i=0;i<n;i++){
    int m=sc.nextInt();
  if(po.containsKey(m))count++;
    else po.put(m,m);
  }
  System.out.println(count);
  }}