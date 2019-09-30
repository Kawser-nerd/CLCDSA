import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String s = sc.next(); 
        int first = s.indexOf("A");
        int last = s.lastIndexOf("Z");
        
        System.out.println(last - first + 1);
    }
}