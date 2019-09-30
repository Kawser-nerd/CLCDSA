import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);

        //????????????
        Set<Integer> set = new HashSet<>();
        //a,b,c???
        set.add(sc.nextInt());  
        set.add(sc.nextInt());
        set.add(sc.nextInt());

        System.out.println(set.size());
    }
}