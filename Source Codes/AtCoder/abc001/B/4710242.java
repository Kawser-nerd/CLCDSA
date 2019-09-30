//?????
import java.util.*;
class Main{
  public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    float km= sc.nextInt() * (float)0.001;
    if (km<0.1) {
      System.out.println("00");
    }else if(km<=5.0){
      String output= String.valueOf((int)(km * 10));
      int len= output.length();
      if (len==1) {
        System.out.println("0" + output);
      }else{
        System.out.println(output);
      }
    }else if(km<=30.0){
      System.out.println((int)(km + 50));
    }else if (km<=70.0) {
      System.out.println((int)((km - 30)/5 + 80));
    }else{
      System.out.println(89);
    }
  }
}