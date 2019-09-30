import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String str=sc.next();
        String str2 =str.replace("a","");
        String str3 = str2.replace("i","");
        String str4 =str3.replace("u","");
        String str5 =str4.replace("e","");
        String str6 =str5.replace("o","");
        
        System.out.println(str6);
    }
}