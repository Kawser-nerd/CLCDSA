import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.next();
        System.out.println(str.replaceAll("ch", "").replaceAll("o", "").replaceAll("k", "").replaceAll("u", "").length()==0?"YES":"NO");
        
    }

}