import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class A {
    public static void main(String args[]) throws Exception {
        Scanner in=new Scanner(new File("A.in"));
        FileWriter fw=new FileWriter("A.out");
        PrintWriter out=new PrintWriter(fw);
        int test=in.nextInt();
        for (int t=1;t<=test;t++) {
            long counts[]=new long[9];
            long n=in.nextLong();
            long A=in.nextLong();
            long B=in.nextLong();
            long C=in.nextLong();
            long D=in.nextLong();
            long x=in.nextLong();
            long y=in.nextLong();
            long M=in.nextLong();
            for (int i=0;i<n;i++) {
                int index=(int)((x%3+3)%3*3+(y%3+3)%3);
                counts[index]++;
                x=(A*x+B)%M;
                y=(C*y+D)%M;                
            }
            long result=0;
            for (int i=0;i<9;i++) {
                for (int j=i;j<9;j++) {
                    for (int k=j;k<9;k++) {
                        if ((i/3+j/3+k/3)%3==0 && (i%3+j%3+k%3)%3==0) {
                            if (i==j && j==k) {
                                if (counts[i]>=3) {
                                    result+=counts[i]*(counts[i]-1)*(counts[i]-2)/6;
                                }
                            }
                            else if (i==j && j!=k) {
                                if (counts[i]>=2) {
                                    result+=counts[i]*(counts[i]-1)/2*counts[k];
                                }
                            }
                            else if (i!=j && j==k) {
                                if (counts[j]>=2) {
                                    result+=counts[i]*counts[j]*(counts[j]-1)/2;
                                }
                            }
                            else {
                                result+=counts[i]*counts[j]*counts[k];
                            }
                        }
                    }
                }
            }
            out.println("Case #"+t+": "+result);
        }

        out.close();
        fw.close();
    }
}
