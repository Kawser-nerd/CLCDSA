import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        char x=s.nextLine().charAt(0);
        
        System.out.println(x=='A'?"T":x=='T'?"A":x=='C'?"G":"C");

    }  
}