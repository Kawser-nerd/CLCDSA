
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
    
    public static String solve(String s, int x){
        if(s.equals(".")){
            return "";
        }
        
        String t = "";
        char c = 'Z';
        c-=x;
        String[] u = s.split( Character.toString(c));
        for(int i=0; i<u.length-1; i++){
            t+=c;
        }
        
        for(int i=0; i<u.length; i++){
            if(i==0){
                t+=solve(u[i], x+1);
            }
            else{
                t+=remove(u[i]);
            }
        }
        return t;
    }
    
    public static String remove (String s){
        String t="";
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)!='.'){
                t+=s.charAt(i);
            }

        }
        return t;
    }
    
    public static String interlace(String s){
        String t = ".";
        for(int i=0; i<s.length(); i++){
            t+=s.charAt(i);
            t+=".";
        }
        return t;
    }
    
    public static  void  main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.next());
        for(int i=0; i<n; i++){
            String s = in.next();
            s = interlace(s);
            System.out.println("Case #" + (i+1) + ": " + solve(s, 0));
        }
      
    }
       
        
}
    
  
