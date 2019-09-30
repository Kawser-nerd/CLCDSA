import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n[] = new int[3];
        int cnt = 3;
        for(int i=0;i<3;i++)
            n[i] = sc.nextInt();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(n[i]>n[j])
                    cnt--;
            }
            System.out.println(cnt);
            cnt = 3;
        }
    }
}