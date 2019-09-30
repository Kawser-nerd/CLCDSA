import java.util.*;

public class Main {
    private static int N;
    private static ArrayList<Integer> color = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();

        for (int i=0;i<N;i++){
            color.add(scan.nextInt());
        }
    }

    public static void main(String args[]) {
        //??
        input();

        int cnt0 = 0;
        int cnt1 = 0;

        for(int i = 0;i < N;i++){
            if(color.get(i) == 0) cnt0++;
            if(color.get(i) == 1) cnt1++;
        }

        if(cnt0 == N || cnt1 == N){
            System.out.println(-1);
            return;
        }

        int head = 0;
        for (int i=0;i<N;i++){
            if (color.get(i) != color.get(i+1)) {
                head = i + 1;
                break;
            }
        }
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i=head;i<N;i++) arrayList.add(color.get(i));
        for (int i=0;i<head;i++) arrayList.add(color.get(i));

        int max = 0;
        int count = 0;
        for (int i=0;i<N-1;i++){
            if (arrayList.get(i) == arrayList.get(i+1)) count++;
            else count = 0;
            max = Math.max(count , max);
        }

        System.out.println(max/2 + 1);
    }
}