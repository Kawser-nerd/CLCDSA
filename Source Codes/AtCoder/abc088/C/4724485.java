import java.util.Scanner;

public class Main {

    public static void main (String [] args){
        Scanner  sc = new Scanner(System.in);
        String ans ="Yes";
        int list[][] =new int[3][3];
        for (int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int num = sc.nextInt();
                list[i][j] =num;
            }
        }
        int tmpListA [] = new int[3];
        int tmpListB [] = new int[3];
        tmpListA[0]=0;
        for (int i=0;i<3;i++) {
                tmpListB[i] = list[0][i] -tmpListA[0];
                tmpListA[i] = list[i][0] - tmpListB[0];
        }
        for (int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(list[i][j] == (tmpListA[i]+tmpListB[j])) {
                    continue;
                }else {
                    ans = "No";
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}