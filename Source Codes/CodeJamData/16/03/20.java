
package lab6zp;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


//Zachary Polansky
//CSC171
//Lab02
//LinkedList





public class Lab6ZP {

   
    public static String makeit(int i){
        String s = "11";
        int k = 14;
        while(k>0){
            k--;
            if(i%2==0){
                s+="11";
            
            }else{
                s+="00";
            }
            i/=2;
        }
        s+="11";
        return s;
    }
    
    
    
    public static  void  main(String[] args) {
        
        System.out.println("Case #1:");
        for(int i=0; i<500; i++){
            String s = makeit(i);
            System.out.println(s + " 3 4 5 6 7 8 9 10 11");
        }
       
        
    }
    
  
} 