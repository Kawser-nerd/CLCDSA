import java.util.*;

public class Main {
    private static int N;
    private static int M;
    private static int x;
    private static int a;
    private static int p;
    private static int map[][];
    private static ArrayList<Integer> temp = new ArrayList<>();
    private static HashMap<Integer , ArrayList<Integer>> hashMap = new HashMap<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        M = scan.nextInt();
        x = scan.nextInt();
        a = scan.nextInt();
        p = scan.nextInt();

        map = new int[N][M];
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (i == 0 && j == 0) map[i][j] = x;
                else {
                    if (j == 0) map[i][j] = (map[i-1][M-1] + a) % p;
                    else map[i][j] = (map[i][j-1] + a) % p;
                }
                temp.add(map[i][j]);
            }
        }
    }

    public static void main(String args[]) {
        //??
        input();

        for (int i=0;i<N;i++) hashMap.put(i , new ArrayList<>());
        Collections.sort(temp);

        if(a % p == 0){
            if(map[0][1] >= x) System.out.println(0);
            else System.out.println(2*(N-1));
        }else {
            // ????
            int ans = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    int col = temp.indexOf(map[i][j]) / M;
                    ans += Math.abs(i - col);
                    ArrayList<Integer> arrayList = hashMap.get(col);
                    arrayList.add(j);
                    hashMap.put(col , arrayList);
                }
            }

            // ????
            for (int i=0;i<N;i++){
                ArrayList<Integer> arrayList = hashMap.get(i);
                int count[] = new int[M];
                for (int j=0;j<M;j++){
                    count[arrayList.get(j)]++;
                }
                for (int j=0;j<M;j++){
                    if (count[j] == 0){
                        int k = 0;
                        while (count[k++] < 2){}
                        ans += Math.abs(k-1 - j);
                        count[j]++;
                        count[k-1]--;
                    }
                }
            }
        /*for (Integer key : hashMap.keySet()) {
            System.out.println(key + " => " + hashMap.get(key));
        }*/
            System.out.println(ans);
        }
    }
}