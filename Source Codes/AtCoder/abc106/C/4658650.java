import java.util.ArrayList;
import java.util.*;
public class Main {
  static Scanner sc = new Scanner(System.in);  
  static String i = sc.next();
  static long iga1 = sc.nextLong();
  
  
 public static void main(String[] args) {
  if(i.length() > iga1 ){
   String iti = i.substring(0,(int)iga1);
   String[] itibara = iti.split("");
   itiiti1(iga1,itibara);
   }else{
     String[] itibara = i.split("");
     itiiti1(iga1,itibara);
   }
 }
 static void itiiti1(long iga11,String[] itibara){
  if(iga11 > 1000000000){
    long count = 0L;
    for(long ii = 0;ii < iga11; ii++){
      if (itibara[(int)ii].equals("1")){
        count+=1;
      }else{
        System.out.println(itibara[(int)ii]);
        break;
      }
      if(count == iga11){
        System.out.println("1");
      }
    }  
      
  }else{
   long count = 0L;
   for(long ii = 0;ii < iga11; ii++){
     if (itibara[(int)ii].equals("1")){
       count+=1;
     }else{
       System.out.println(itibara[(int)ii]);
       break;
     }
   }
   if(count == iga11){
     System.out.println("1");
   }
  }
 }
}