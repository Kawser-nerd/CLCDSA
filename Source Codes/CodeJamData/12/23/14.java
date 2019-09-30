
import java.io.*;
import java.util.*;

public class Equal {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    long[] nums;
    long max;
    
    Map<Long,Subset> all = new HashMap<Long, Equal.Subset>();
    List<Subset> working = new ArrayList<Equal.Subset>();
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        
        int n = scan.nextInt();
        nums = new long[n];
        long sum = 0;
        for(int i = 0; i < n; i++) {
            nums[i] = scan.nextLong();
            sum += nums[i];
        }
        max = sum / 2;
        Arrays.sort(nums);
        
        all.clear();
        working.clear();
        
        for(int i = 0; i < n; i++) {
            Subset singleton = new Subset(i);
            all.put(singleton.sum,singleton);
            working.add(singleton);
        }
        
        while(!working.isEmpty()) {
            List<Subset> lastWorking = new ArrayList<Subset>(working);
            working.clear();
            for(Subset subset : lastWorking) {
                for(Subset newSubset : subset.getNexts()) {
                    Subset alreadyFound = all.get(newSubset.sum);
                    if(alreadyFound==null) {
                        all.put(newSubset.sum,newSubset);
                        working.add(newSubset);
                    }
                    else {
                        alreadyFound.print();
                        out.println();
                        newSubset.print();
                        out.println();
                        return;
                    }
                }
            }
        }
        
        out.println("Impossible");
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.println("Case #" + i + ":");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Equal().run();
    }

    class Subset {
        final long sum;
        final int lastIndex;
        final Subset prior;
        
        Subset(int index) {
            this.sum = nums[index];
            this.lastIndex = index;
            this.prior = null;
        }
        
        Subset(int index, Subset prior) {
            this.sum = prior.sum + nums[index];
            this.lastIndex = index;
            this.prior = prior;
        }
        
        void print() {
            if(this.prior==null) {
                out.print(nums[lastIndex]);
            }
            else {
                this.prior.print();
                out.print(" ");
                out.print(nums[lastIndex]);
            }
        }
        
        List<Subset> getNexts() {
            List<Subset> nexts = new ArrayList<Equal.Subset>();
            for(int i = lastIndex + 1; i < nums.length; i++) {
                Subset next = new Subset(i,this);
                if(next.sum > max) break;
                nexts.add(next);
            }
            return nexts;
        }
    }
}
