import java.util.*;

public class Main {
    private static double N;
    private static ArrayList<Integer> x = new ArrayList<>();
    private static ArrayList<Integer> y = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();

        for (int i=0;i<N;i++){
            x.add(scan.nextInt());
            y.add(scan.nextInt());
        }
    }

    public static void main(String args[]) {
        //??
        input();

        int ans = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    if (i != j && j!= k && i!= k){
                        long ax = x.get(k) - x.get(i); long ay = y.get(k) - y.get(i);
                        long bx = x.get(j) - x.get(i); long by = y.get(j) - y.get(i);
                        long area = Math.abs(ax*by - ay*bx);
                        if (area > 0 && area % 2 == 0) ans++;
                    }
                }
            }
        }
        System.out.println(ans / 6);
    }
}