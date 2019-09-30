
package lab6zp;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


//Zachary Polansky
//CSC171
//Lab02
//LinkedList





public class Lab6ZP {

   
    
    
    
    
    public static  void  main(String[] args) {
        
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      for(int i=0; i<n; i++){
        long k = in.nextInt();
        long c = in.nextInt();
        int s = in.nextInt();
        System.out.print("Case #" + (i+1) + ": ");
        if(c*s<k){
            System.out.println("IMPOSSIBLE");
        }
        else{
            long val=0;
            while(s>0){
                long exp=1;
                long total=0;
                while(exp<Math.pow(k,c)){
                    total+=val*exp;
                    exp*=k;
                    if(val<k-1){
                        val++;
                    }
                }
                s--;
                System.out.print(total+1);
                if(total+1==Math.pow(k,c)){
                    s=0;
                }
                if(s!=0){
                    System.out.print(" ");
                }
                else{
                    System.out.println();
                }
            }
        }
      }
      
    }
       
        
    }
    
  
