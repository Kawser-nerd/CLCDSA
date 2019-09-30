import java.util.*;

public class Main {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] inputs = input.split(" ");
        int count = Integer.valueOf(inputs[0]);
        int score = Integer.valueOf(inputs[1]);
        int[] a = new int[count];
        int[] b = new int[count];

        for( int i = 0 ; i<count ; i++) {
            String data = sc.nextLine();
            String[] datas = data.split(" ");
            a[i] = Integer.valueOf(datas[0]);
            b[i] = Integer.valueOf(datas[1]);
        }



        int maxA  = Integer.MIN_VALUE;

        for( int i = 0 ; i<count; i++ ) {
            if(a[i]>maxA) {
                maxA = a[i];
            }
            else if ( a[i] == maxA ){

            }
        }

        int moves = 0;

        Arrays.sort(b);
        int[] j = new int[count];
        for(int i = 0; i<count ;i++)
        {
            j[count-i-1] = b[i];
        }
        b = j;

            for( int i = 0; i<count ;i++)   {
                if(b[i]>=maxA) {
                    moves = moves+1;

                    score = score - b[i];
                    if(score<=0) {
                        break;
                    }
                }
            }
        if( score> 0 ) {
            int extraMoves  = score/maxA;
            if(score-(extraMoves*maxA)>0)
                moves = moves +extraMoves+1;
            else
                moves = moves+extraMoves;
        }
        System.out.println(moves);

    }
}