import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int colors[] = new int[scanner.nextInt()];
        //????
        int c = scanner.nextInt();
        //??????
        int colorconut1[] = new int[10];
        //?????????????
        int colorconut2[] = new int[10];
        //?????
        for (int i = 0;i < colors.length;++i){
            colors[i] = scanner.nextInt() - 1;
            //1~10???????0~9???
            if(i % 2 == 0){
                ++colorconut1[colors[i]];
            }
            else{
                ++colorconut2[colors[i]];
            }
            //?????
        }
        int m1index = 0,m1 = 0,m2index = 0,m2 = 0;
        for (int i = 0;i < 10;++i){
            if(colorconut1[i] > m1){
                m1 = colorconut1[i];
                m1index = i;
            }
        }
        for (int i = 0;i < 10;++i){
            if(colorconut2[i] > m2){
                m2 = colorconut2[i];
                m2index = i;
            }
        }
        if(m1index == m2index){
            int m1sindex = 0,m1s = 0,m2sindex = 0,m2s = 0;
            for (int i = 0;i < 10;++i){
                if(m1index == i){
                    continue;
                }
                if(colorconut1[i] > m1s){
                    m1s = colorconut1[i];
                    m1sindex = i;
                }
            }
            for (int i = 0;i < 10;++i){
                if(m2index == i){
                    continue;
                }
                if(colorconut2[i] > m2s){
                    m2s = colorconut2[i];
                    m2sindex = i;
                }
            }
            if(m1s > m2s){
                m1 = m1s;
            }
            else{
                m2 = m2s;
            }
        }
        m1 = (colors.length + (colors.length % 2 == 1 ? 1 : 0)) / 2 - m1;
        m2 = (colors.length + (colors.length % 2 == 0 ? 0 : -1)) / 2 - m2;
        System.out.println((m1 + m2) * c);
    }
}