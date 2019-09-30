import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int D;
        D=s.nextInt();
        if(D==25){
            System.out.println("Christmas");
        }
        else if(D==24){
            System.out.println("Christmas Eve");
        }
        else if(D==23){
             System.out.println("Christmas Eve Eve");
        }
        else{
             System.out.println("Christmas Eve Eve Eve");
        }
    }  
}