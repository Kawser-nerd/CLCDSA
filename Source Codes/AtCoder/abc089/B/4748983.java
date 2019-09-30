import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        String a[] = new String[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.next();
        }

        Set<String> set = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            set.add(a[i]);
        }
        
        if(set.size() == 4){
            System.out.println("Four");
        }else{
            System.out.println("Three");
        }

        sc.close();
    }
}