import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        s = s.replaceAll("," , " ");
        System.out.println(s);
    }
}