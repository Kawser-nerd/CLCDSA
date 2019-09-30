import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();

      if(w%16==0&&h%9==0){
        System.out.println("16:9");
      }else{
        System.out.println("4:3");
      }
      
  
    }
}