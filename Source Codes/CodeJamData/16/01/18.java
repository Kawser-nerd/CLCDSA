
package lab6zp;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


//Zachary Polansky
//CSC171
//Lab02
//LinkedList





public class Lab6ZP {

    static boolean[] b = new boolean[10];
  
    public static boolean mark(int i){
        while(i>0){
            b[i%10]=true;
            i/=10;
        }
        for(int j=0; j<10; j++){
            if(!b[j]){
                return false;
            }
        }
        return true;
        
    }
  
    
    public static  void  main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                b[j]=false;
            }
            int k = in.nextInt();
            if(k==0){
                System.out.println("Case #" + (i+1) + ": " + "INSOMNIA");
            }
            else{
                int times=1;
                while(!mark(k*times)){
                    times++;
                }
                System.out.println("Case #" + (i+1) + ": " + times*k);
                
            }
        }
       
        
    }
    
  
} 