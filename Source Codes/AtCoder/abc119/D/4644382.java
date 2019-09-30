import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        long[] shrine = new long[a];
        int b =sc.nextInt();
        long[] temple = new long[b];
        int q = sc.nextInt();
        for (int i = 0; i < a; i++){
            shrine[i] = sc.nextLong();
        }
        for (int i = 0; i < b; i++){
            temple[i] = sc.nextLong();
        }
        for (int k = 0; k < q; k++){
            long val = sc.nextLong();
            int ind1 = binSearch(val,shrine);
            int ind2 = binSearch(val,temple);
            long min = Long.MAX_VALUE;
            min = Math.min(min,Math.abs(shrine[ind1]-val)+Math.abs(shrine[ind1]-temple[ind2]));
            if(ind2 < temple.length-1)
                min = Math.min(min,Math.abs(shrine[ind1]-val)+Math.abs(shrine[ind1]-temple[ind2+1]));
            if (ind1 < shrine.length-1)
                min = Math.min(min,Math.abs(shrine[ind1+1]-val)+Math.abs(shrine[ind1+1]-temple[ind2]));
            if (ind1 < shrine.length-1 && ind2 < temple.length-1)
                min = Math.min(min,Math.abs(shrine[ind1+1]-val)+Math.abs(shrine[ind1+1]-temple[ind2+1]));
            min = Math.min(min,Math.abs(temple[ind2]-val)+Math.abs(temple[ind2]-shrine[ind1]));
            if (ind1 < shrine.length-1)
                min = Math.min(min,Math.abs(temple[ind2]-val)+Math.abs(temple[ind2]-shrine[ind1+1]));
            if(ind2 < temple.length-1)
                min = Math.min(min,Math.abs(temple[ind2+1]-val)+Math.abs(temple[ind2+1]-shrine[ind1]));
            if (ind1 < shrine.length-1 && ind2 < temple.length-1)
                min = Math.min(min,Math.abs(temple[ind2+1]-val)+Math.abs(temple[ind2+1]-shrine[ind1+1]));
            System.out.println(min);
        }
    }
    public static int binSearch(long find, long[] arr){
        int low = 0;
        int high = arr.length-1;
        while (low < high){
            int middle = (low+high)/2;
            if(arr[middle] == find){
                return middle;
            }else if (middle < arr.length-1 && arr[middle] < find && arr[middle+1] > find){
                return middle;
            }else if (middle > 0 && arr[middle] > find && arr[middle-1] < find){
                return middle-1;
            }
            else if (arr[middle] < find){
                low = middle+1;
            }else{
                high = middle-1;
            }
        }
        return low;
    }
}