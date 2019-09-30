import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        Map<Integer,Integer> map = new TreeMap<>(Collections.reverseOrder());
        for(int i = 0; i < N; i++){
            map.put(sc.nextInt(), i + 1);
        }

        for(int i : map.values()){
            System.out.println(i);
        }
    }
}