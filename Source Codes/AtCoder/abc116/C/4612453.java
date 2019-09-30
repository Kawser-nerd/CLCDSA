public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n=scanner.nextInt(),last=0,ans=0;
        for(int i=0,j;i<n;i++,last=j)if(last>=(j=scanner.nextInt()))ans+=last-j;
        System.out.println(last+ans);
    }
}