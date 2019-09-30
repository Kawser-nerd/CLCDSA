import java.util.OptionalInt;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[]$) {
        java.util.Scanner s=new java.util.Scanner(System.in);
        int n=s.nextInt(),m=s.nextInt(),d[][]=IntStream.range(0,n).mapToObj(i->IntStream.range(0,n).map(j->i==j?0:0x1fffffff).toArray()).toArray(int[][]::new),a,b;
        while(m-->0)d[a=s.nextInt()-1][b=s.nextInt()-1]=d[b][a]=Math.min(d[a][b],s.nextInt());
        IntStream.range(1,n).forEach(i->IntStream.range(1,n).forEach(j->IntStream.range(1,n).forEach(k->d[j][k]=Math.min(d[j][k],d[j][i]+d[i][k]))));
        System.out.println(IntStream.range(1,n).mapToObj(i->IntStream.range(i+1,n).map(j->d[0][i]+d[i][j]+d[j][0]).min()).filter(OptionalInt::isPresent).min(java.util.Comparator.comparing(OptionalInt::getAsInt)).filter(o->o.getAsInt()<0x1fffffff).orElse(OptionalInt.of(-1)).getAsInt());
    }
}