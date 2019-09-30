import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str=sc.next();
        String[] chars={"A","B","C","D","E","F"};
        for(int i=0;i<6;i++){
            System.out.print(str.length()-str.replaceAll(chars[i], "").length());
            if(i!=5)System.out.print(" ");
        }
        System.out.println();
    }
}