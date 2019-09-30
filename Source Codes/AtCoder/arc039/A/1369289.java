import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
      Scanner sc = new Scanner(System.in);          
      
      int A = sc.nextInt();
      int B = sc.nextInt();
      
      String Aafter = String.valueOf(A);
      String Bafter = String.valueOf(B);
      
      int max = Integer.parseInt(Aafter) - Integer.parseInt(Bafter);
      
      String AA = "";
      
      if(A < 900){
          AA = "9";
          AA += String.valueOf(Aafter.charAt(1));
          AA += String.valueOf(Aafter.charAt(2));
          max = Math.max(max,Integer.parseInt(AA) - Integer.parseInt(Bafter));
      }else if(A < 990){
          AA = "99" + String.valueOf(Aafter.charAt(2));
          max = Math.max(max,Integer.parseInt(AA) - Integer.parseInt(Bafter));
      }else if(A >= 990){
          AA = "999";
          max = Math.max(max,Integer.parseInt(AA) - Integer.parseInt(Bafter));
      }
      
      if(B >=200){
          Bafter = "1" + String.valueOf(Bafter.charAt(1)) + String.valueOf(Bafter.charAt(2));
          max = Math.max(max,Integer.parseInt(Aafter) - Integer.parseInt(Bafter));
      }else if(B >= 110 && B <= 200){
          Bafter = "10" + String.valueOf(Bafter.charAt(2));
          max = Math.max(max,Integer.parseInt(Aafter)  - Integer.parseInt(Bafter));
      }else if(B < 110){
          Bafter = "100";
          max = Math.max(max,Integer.parseInt(Aafter)  - Integer.parseInt(Bafter));          
      }
      
      System.out.println(max);
      
    }      
}