import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x=0;
       try{
           x=System.in.read();
       }
       catch(IOException e){
           System.err.println( "????????" );
       }
        System.out.println((char)x=='A'?"T":(char)x=='T'?"A":(char)x=='C'?"G":"C");
 
    }  
}