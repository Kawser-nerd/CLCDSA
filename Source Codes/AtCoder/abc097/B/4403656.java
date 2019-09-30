import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        set.add(1);
        for(int i = 2 ; i <= Math.sqrt(n) ; i++){
            for(int j = i*i ; j <= n; j*=i){
                set.add(j);
            }
        }
        System.out.println(set.last());

    }
}