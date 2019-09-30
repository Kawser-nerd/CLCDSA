import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
  long a = sc.nextLong();
  long k = sc.nextLong();
  if(k == 0)System.out.println(2000000000000l - a);
  else{
  for(long i = 1;;i++){
    if(a*Math.pow(k+1,i) + (Math.pow(k+1,i)-1)/k >= 2*Math.pow(10,12)){
      System.out.println(i);
      break;
    }
  }
  }
}}