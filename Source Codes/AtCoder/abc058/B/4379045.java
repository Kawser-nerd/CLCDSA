import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String O = sc.next();
        String E = sc.next();
        int Olen = O.length();
        int Elen = E.length();
        
        for(int i = 0; i < Elen; i++){
            System.out.print(O.charAt(i));
            System.out.print(E.charAt(i));
        }
        if(Olen> Elen) System.out.print(O.charAt(Olen -1 ));
    }
}