import java.util.*;
class Main{
    static Scanner sc = new Scanner(System.in);
    /*
     * ?? -> nextInt() (???????ni())
     * ?? -> next()
     * 1? -> nextLine()
     * ?? : nextLIne?next(),nextInt()???????????????????????????????
     */

    public static void main(String[] args){
        int H = ni();
        int W = ni();

        char[][] A = new char[H][W];
        for(int i=0;i<H;i++){
            A[i] = sc.next().toCharArray();
        }

        for(int x1=0;x1<H;x1++) for(int y1=0;y1<W;y1++){
            for(int x2=0;x2<H;x2++) for(int y2=0;y2<W;y2++){
                if(x1<x2 && y2 < y1 && A[x1][y1]=='#' && A[x2][y2]=='#'){
                    System.out.println("Impossible");
                    return;
                }
            }
        }

        System.out.println("Possible");
    }

    public static int ni(){
        return Integer.parseInt(sc.next());
    }
}