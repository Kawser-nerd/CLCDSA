import java.lang.reflect.Array;
import java.util.*;



public class Main {
    private void print(ArrayList<Integer> arrayMid) {
        StringBuilder Mid = new StringBuilder();
        for (int i = 0; i < arrayMid.size(); i++) {
            Mid.append(arrayMid.get(i) + " ");
        }
        System.out.println(Mid);
    }

    private void Even(int K, int N) {
        ArrayList<Integer> arrayMid = new ArrayList<Integer>(N);
        arrayMid.add(0, K / 2);
        for (int i = 1; i < N; i ++) {
            arrayMid.add(i, K);
        }
        print(arrayMid);
    }

    private void Odd(int K, int N) {
        ArrayList<Integer> arrayMid = new ArrayList<Integer>(N);
        for (int i = 0; i < N; i++) {
            arrayMid.add(i, (K + 1) / 2);

        }
        for (int i = 0; i < N / 2; i++) {
            if (arrayMid.get(arrayMid.size() - 1) == 1) arrayMid.remove(arrayMid.size() - 1);
            else {
                arrayMid.set((arrayMid.size() - 1), arrayMid.get(arrayMid.size() - 1) - 1);
                for (int j = arrayMid.size(); j < N; j++) arrayMid.add(j, K);
            }
        }
        print(arrayMid);
    }

    private void Judge(int K, int N) {
        if (K % 2 == 0) Even(K, N);
        else Odd(K, N);
    }

    public static void main (String[] args) {
        Scanner input  = new Scanner(System.in);
        int[] in = new int[2];
        for (int i = 0; i < 2; i++) {
            in[i] = input.nextInt();
        }
        Main myEncyclopedia = new Main();
        myEncyclopedia.Judge(in[0], in[1]);
        input.close();
    }

}