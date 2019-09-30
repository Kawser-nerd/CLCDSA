import java.util.*;

/**
 * Created by mizuk on 2017/07/26.
 */
public class Main {

    private static int N;
    private static ArrayList<Integer> arrayList = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();

        for(int i=0;i<N;i++) {
            arrayList.add(scan.nextInt());
        }
    }

    public static void main(String args[]){
        //??
        input();

        ArrayList<Integer> b = new ArrayList<>();

        if(N % 2 == 0){
            for (int i=N-1;i>=0;i-=2) b.add(arrayList.get(i));
            for (int i=0;i<N;i+=2) b.add(arrayList.get(i));
        } else {
            for (int i=N-1;i>=0;i-=2) b.add(arrayList.get(i));
            for (int i=1;i<N;i+=2) b.add(arrayList.get(i));
        }

        // ??
        for (int i=0;i<N;i++){
            System.out.print(b.get(i) + " ");
        }
    }
}