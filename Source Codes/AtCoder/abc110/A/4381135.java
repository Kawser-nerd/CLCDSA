import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int num[] = new int[3];
        
        for(int i = 0; i < 3; i++) num[i] = sc.nextInt();
        Arrays.sort(num);
        int ans = num[2] * 10 + num[1] + num[0];
        
        System.out.println(ans);

    }
}