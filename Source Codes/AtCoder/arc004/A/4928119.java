import java.util.Scanner;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x[] = new int[n];
        int y[] = new int[n];
        
        for(int i = 0; i < n; i++){
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        
        double line = 0.0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
            	double line2 = (double)Math.pow(x[i] - x[j],2) + (double)Math.pow(y[i] - y[j],2);
                if(line < line2){
                    line = line2;
                }
            }
        }
        
        double answer = Math.sqrt(line);
        System.out.println(answer);
    }
}