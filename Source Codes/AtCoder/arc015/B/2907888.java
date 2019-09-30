public class Main{
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int N = sc.nextInt();
        double mLT1[] = new double[N];
        double mST1[] = new double[N];
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        int c5 = 0;
        int c6 = 0;
        for(int i = 0; i < N; i++){
            mLT1[i] = sc.nextDouble();
            mST1[i] = sc.nextDouble();
            if(35 <= mLT1[i]){
                c1++;
            }
            if(30 <= mLT1[i] & mLT1[i] < 35){
                c2++;
            }
            if(25 <= mLT1[i] & mLT1[i] < 30){
                c3++;
            }
            if(25 <= mST1[i]){
                c4++;
            }
            if(0 <= mLT1[i] & mST1[i] < 0){
                c5++;
            }
            if(mLT1[i] < 0){
                c6++;
            }

        }
        System.out.println(c1 + " " + c2 + " " + c3 + " " + c4 + " " + c5 + " " + c6);

        
    }
}