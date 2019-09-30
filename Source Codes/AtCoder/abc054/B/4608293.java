import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        char [][]  nBoard = new char[n][];
        char [][]  mBoard = new char[m][];
        for (int i = 0; i < n; i++) {
            nBoard[i] = input.readLine().toCharArray();
        }
        for (int i = 0; i < m; i++) {
            mBoard[i] = input.readLine().toCharArray();
        }
        boolean state = false;
        TH:for (int i = 0; i < (n - m) + 1; i++) {
            for (int j = 0; j < (n - m) + 1; j++) {
                boolean state2 = true;
                MT:for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {
                        if (nBoard[i + k][j + l] != mBoard[k][l]){
                            state2 = false;
                                break MT;
                        }
                    }
                }
                if (state2){
                    state = true;
                    break TH;
                }

            }
        }
        System.out.println(state? "Yes" : "No");
    }
}