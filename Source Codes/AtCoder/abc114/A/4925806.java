import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x;
        x=s.nextInt();
        if(x==3||x==5||x==7){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }  
}