import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        //(txa,tya),(txb,tby),t,v,n
        double txa = scan.nextInt();
        double tya = scan.nextInt();
        double txb = scan.nextInt();
        double tyb = scan.nextInt();
        int t = scan.nextInt();
        int v = scan.nextInt();
        int n = scan.nextInt();

        String flag = "NO";

        for(int i = 0; i < n; i++){
            //(x1,y1)
            double x1 = scan.nextInt();
            double y1 = scan.nextInt();

            double wark1 = Math.sqrt(Math.pow(x1 - txa,2) + Math.pow(y1 - tya,2));
            double wark2 = Math.sqrt(Math.pow(txb - x1,2) + Math.pow(tyb - y1,2));

            if(v * t >= wark1 + wark2){
                flag = "YES";
            }

            
        }
        System.out.println(flag);
    }
}