import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class B {
    static int parents[];
    public static void main(String args[]) throws Exception {
        Scanner in=new Scanner(new File("B.in"));
        FileWriter fw=new FileWriter("B.out");
        PrintWriter out=new PrintWriter(fw);
        int test=in.nextInt();
        for (int t=1;t<=test;t++) {
            long A=in.nextLong();
            long B=in.nextLong();
            long P=in.nextLong();
            parents=new int[(int)(B-A+1)];
            for (int i=0;i<parents.length;i++) {
                parents[i]=i;
            }
            int group=parents.length;
            for (long i=P;i<=B-A;i++) {
                if (isPrime(i)==true) {
                    long number=A/i*i;
                    if (number<A) {
                        number+=i;
                    }
                    int root1=getRoot((int)(number-A));
                    for (long j=number+i;j<=B;j+=i) {
                        int root2=getRoot((int)(j-A));
                        if (root1!=root2) {
                            parents[root2]=root1;
                            group--;
                        }
                    }
                }
            }
            out.println("Case #"+t+": "+group);
        }

        out.close();
        fw.close();
    }

    static boolean isPrime(long number) {
        for (long i=2;i*i<=number;i++) {
            if (number%i==0) {
                return false;
            }
        }
        return true;
    }

    static int getRoot(int node) {
        int root=node;
        while (parents[root]!=root) {
            root=parents[root];
        }
        while (node!=root) {
            int temp=parents[node];
            parents[node]=root;
            node=temp;
        }
        return root;
    }
}
