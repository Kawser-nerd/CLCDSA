public class Main {
    public static void main(String[] args) {
        java.util.Scanner s=new java.util.Scanner(System.in);
        int n=s.nextInt(),a[]=new int[n];
        java.util.List<Integer> list=new java.util.ArrayList<>(java.util.stream.IntStream.range(0,n).map(i->a[i]=s.nextInt()).boxed().collect(java.util.stream.Collectors.toCollection(java.util.TreeSet::new)));
        for(int i:a)System.out.println(java.util.Collections.binarySearch(list, i));
    }
}