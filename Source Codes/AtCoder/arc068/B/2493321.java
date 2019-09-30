import java.util.*;
import java.lang.*;

class Main {
    
    public static void main(String[] areg) {
        Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
        int count = 0;
        HashSet<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            int j = sc.nextInt();
            if (set.contains(j))
                count++;
            else
                set.add(j);
        }
		sc.close();
        
        System.out.println(set.size() - (count % 2 == 0 ? 0 : 1));
    }
}