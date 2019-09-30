import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int Q=scan.nextInt();
        while(Q-->0){
            long A = scan.nextLong();
            long B = scan.nextLong();
            long k = (A+B)/(Math.min(A,B)+1);
            if(k<=1){
                int C = scan.nextInt()-1;
                int D = scan.nextInt()-1;
                String even = (A>=B ? "A":"B");
                String odd = (A>=B ? "B":"A");
                String ans ="";
                for(int i=C;i<=D;++i){
                    if(i%2==0)ans+=even;
                    else ans+=odd;
                }
                System.out.println(ans);
                continue;
            }
            long n = (k*A-B)/(k*k-1);
            long m = (k*B-A)/(k*k-1);
            long a = A-n*k-m;
            long b = B-m*k-n;
            int C = scan.nextInt()-1;
            int D = scan.nextInt()-1;

            String ans ="";
            for(int i=C;i<=D;++i){
                if(i<n*(k+1)){
                    if((i+1)%(k+1)==0)ans+="B";
                    else ans+="A";
                }else if(i>=n*(k+1)+a+b){
                    long index=i-(n*(k+1))-a-b;
                    if(index%(k+1)==0)ans+="A";
                    else ans+="B";
                }else{
                    long index=i-n*(k+1);
                    if(index<a)ans+="A";
                    else ans+="B";
                }
            }
            System.out.println(ans);

        }
        
    }
}