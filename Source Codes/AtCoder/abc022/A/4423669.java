import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int S = sc.nextInt();
        int T = sc.nextInt();
        int weight = sc.nextInt();
        int count = 0;
        for(int i = 0; i<N-1; i++) {
            if(weight >= S && weight <= T) {
                count++;
            }
            weight = weight + sc.nextInt();
        }
        if(weight >= S && weight <= T) {
            count++;
        }
        System.out.println(count);
    }
}