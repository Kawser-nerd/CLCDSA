import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int A,B;
        A=s.nextInt();
        B=s.nextInt();
        
        if(B%A==0){
            System.out.println(A+B);
        }
        else{
            System.out.println(B-A);
        }
    }  
}