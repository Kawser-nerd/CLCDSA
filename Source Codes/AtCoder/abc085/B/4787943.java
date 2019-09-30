import java.util.HashSet;
import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashSet<Integer> hs = new HashSet<Integer>();

        for(int i = 0; i < N; i++) {
            hs.add(sc.nextInt());
        }

        sc.close();

        System.out.println(hs.size());    
    }
}