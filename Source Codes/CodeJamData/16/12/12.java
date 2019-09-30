
package lab6zp;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


//Welp. As long as I know you look through my code:

//In CSC 172,
//Dan tries to pass a note to Maria
//Jack intercepts it and starts opening it up
//Dan: "Hey, you can't read that! It's private!"
//Jack: "But we're in the same class!"

//Ba dum tss.


//Okay now seriously why are you in my code.
//Stop looking, it's just so bad.
//I literally haven't even written it yet.
//But I know it's probably going to be just so bad.
//So don't.

/*
     Zachary Polansky
     CSC171
     Lab06
     Queue
*/




public class Lab6ZP {
    
    
    
    
    
    public static  void  main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.next());
        
        for(int i=0; i<n; i++){
            int m = Integer.parseInt(in.next());
            boolean[] k = new boolean[2501];
            for(int j=0; j<2501; j++){
                k[j]=false;
            }
            for(int j=0; j<2*m*m-m; j++){
                int l = Integer.parseInt(in.next());
                k[l] = !k[l];
            }
            System.out.print("Case #" + (i+1) + ": ");
            for(int j=0; j<2501; j++){
                if(k[j]){
                System.out.print(j + " ");
                       }
                
            }
            System.out.println();
        }
      
    }
       
        
}
    
  
