
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
            boolean is = false;
            int m = Integer.parseInt(in.next());
            int[] k = new int[m];
            int[] h = new int[m];
            int min = -1;
            
            for(int j=0; j<m; j++){
                h[j]=0;
                k[j] = Integer.parseInt(in.next())-1;
                
                
            }
            System.out.print("Case #" + (i+1) + ": ");
            
                int fullcounter = 0;
                ArrayList<Integer> q = new ArrayList<>();
                for(int j=0; j<m; j++){
                    int p = j;
                    for(int z=0; z<m+2; z++){
                        if(k[k[p]]==p){
                            //System.out.println(j + " " + z + "!");
                            if(z>h[p]||!q.contains(p)){
                                fullcounter-=h[p];
                                fullcounter+=z;
                                if(!q.contains(p)){
                                    q.add(p);
                                    fullcounter++;
                                }
                                h[p] = z;
                            }
                            if(min<fullcounter){
                                min = fullcounter;
                            }
                            z=m+1;
                            continue;
                        }
                        p=k[p];
                        if(z>0 &&p==k[j]){
                            //System.out.println(j + " " + z);
                            if(min<z){
                                min = z;
                            }
                            z=m+1;
                        }
                        
                        
                    }
                }
                System.out.println(min);
            }
            
        
      
    }
       
        
}
    
  
