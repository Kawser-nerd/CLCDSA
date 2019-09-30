import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> list_a = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            int din = sc.nextInt();
            list_a.add(din);
        }
        
        Collections.sort(list_a);
        int ans = 0;
        for(int i = 1; i < n; i++){
            //char c = (i == n - 1)? '\n' : ' ';
            //System.out.print(list_a.get(i));
            //System.out.print(c);
            ans += list_a.get(i) - list_a.get(i - 1);
        }
        System.out.println(ans);
    }    
}