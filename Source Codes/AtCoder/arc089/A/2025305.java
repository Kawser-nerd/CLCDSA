import java.io.*;
    import java.util.*;
    import java.math.BigInteger;
    public class Main {
        private static StringBuilder sb = new StringBuilder();
        private static void s(String s){
            System.out.print(s);
        }
        private static void s(Double s){
            System.out.print(s);
        }
        private static void s(char s){
            System.out.print(s);
        }
        private static void sn(String s){
            System.out.println(s);
        }
        private static void sn(Boolean s){
            System.out.println(s);
        }
        private static void sn(long s){
            System.out.println(s);
        }
        private static void sn(Double s){
            System.out.println(s);
        }
        private static void sn(String s, Object o){
            sb.append(s+"\n");
        }
        private static void sn(long s, Object o){
            sb.append(s+"\n");
        }
        private static void sn(boolean s, Object o){
            sb.append(s+"\n");
        }
        private static void pr() throws Exception{
            BufferedWriter bw =new BufferedWriter(new OutputStreamWriter(System.out));
            bw.write(sb.toString());
            bw.flush();
        }
        static class Reader{
            final private int BUFFER_SIZE = 1 << 16;
            private DataInputStream din;
            private byte[] buffer;
            private int bufferPointer, bytesRead;
     
            public Reader()
            {
                din = new DataInputStream(System.in);
                buffer = new byte[BUFFER_SIZE];
                bufferPointer = bytesRead = 0;
            }
     
            public Reader(String file_name) throws IOException
            {
                din = new DataInputStream(new FileInputStream(file_name));
                buffer = new byte[BUFFER_SIZE];
                bufferPointer = bytesRead = 0;
            }
     
            public String readLine() throws IOException
            {
                byte[] buf = new byte[128]; // line length
                int cnt = 0, c;
                while ((c = read()) != -1)
                {
                    if (c == '\n')
                        break;
                    buf[cnt++] = (byte) c;
                }
                return new String(buf, 0, cnt);
            }
     
            public int nextInt() throws IOException
            {
                int ret = 0;
                byte c = read();
                while (c <= ' ')
                    c = read();
                boolean neg = (c == '-');
                if (neg)
                    c = read();
                do
                {
                    ret = ret * 10 + c - '0';
                }  while ((c = read()) >= '0' && c <= '9');
     
                if (neg)
                    return -ret;
                return ret;
            }
     
            public long nextLong() throws IOException
            {
                long ret = 0;
                byte c = read();
                while (c <= ' ')
                    c = read();
                boolean neg = (c == '-');
                if (neg)
                    c = read();
                do {
                    ret = ret * 10 + c - '0';
                }
                while ((c = read()) >= '0' && c <= '9');
                if (neg)
                    return -ret;
                return ret;
            }
     
            public double nextDouble() throws IOException
            {
                double ret = 0, div = 1;
                byte c = read();
                while (c <= ' ')
                    c = read();
                boolean neg = (c == '-');
                if (neg)
                    c = read();
     
                do {
                    ret = ret * 10 + c - '0';
                }
                while ((c = read()) >= '0' && c <= '9');
     
                if (c == '.')
                {
                    while ((c = read()) >= '0' && c <= '9')
                    {
                        ret += (c - '0') / (div *= 10);
                    }
                }
     
                if (neg)
                    return -ret;
                return ret;
            }
     
            private void fillBuffer() throws IOException
            {
                bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
                if (bytesRead == -1)
                    buffer[0] = -1;
            }
     
            private byte read() throws IOException
            {
                if (bufferPointer == bytesRead)
                    fillBuffer();
                return buffer[bufferPointer++];
            }
     
            public void close() throws IOException
            {
                if (din == null)
                    return;
                din.close();
            }
        }
        private static boolean isPrime(Integer ii){
            return new BigInteger(ii+"").isProbablePrime(1);
        }
        private static boolean isDigit(int ii){
            return Character.isDigit((char)ii);
        }
        private static long fact(int f){
            if(f==0){
                return 1;
            }
            return (long)f * (long)fact(f-1);
        }
        /*static int ar[] = new int[1000000];
        static {
            Arrays.fill(ar, 1000070);
            ar[0]=0;
            int arrr[] = new int[]{2,3,5,7};
            for(int i=0;i<4;i++){
                for(int ii=0;ii<1000000;ii++){
                    if(ii>=arrr[i]){
                        ar[ii] = Math.min(ar[ii], 1+ar[ii-arrr[i]]);
                    }
                }
            }
        }*/
        /*static{
            Arrays.fill(prime, true);
            for(int p = 2; p*p <=1000070; p++)
            {
                // If prime[p] is not changed, then it is a prime
                if(prime[p] == true)
                {
                    // Update all multiples of p
                    for(int i = p*2; i <= 1000070; i += p)
                        prime[i] = false;
                }
            }
            int nc = 0;
            for(int p = 2; p <=1000070; p++)
            {
                if(prime[p] == true && prime[(p+1)/2] == true)
                {
                    prr[p]+=nc+1;
                    nc = prr[p];
                }
            }
        }*/
        private static Reader r = new Reader();
        private static int ni() throws Exception{
            return r.nextInt();
        }
        private static long nl() throws Exception{
            return r.nextLong();
        }
        private static int[] na(int a) throws Exception{
            int arr[] = new int[a];
            for(int i=0;i<a;i++){
                arr[i] = r.nextInt();
            }
            return arr;
        }
        private static boolean isSquare(int a){
            double sqt = Math.sqrt(a);
            return (int)sqt == sqt;
        }
        private static int lSquare(int a){
            double sqt = Math.sqrt(a);
            return (int)sqt * (int) sqt;
        }
        private static int rSquare(int a){
            double sqt = Math.sqrt(a);
            return (int)Math.ceil(sqt) * (int)Math.ceil(sqt);
        }
        private static int parent[] = new int[200005];
        private static boolean visit[] = new boolean[200005];
        private static void init(){
        	for(int i=0;i<200005;i++){
        		parent[i] = 0;
        	}
        	for(int i=0;i<200005;i++){
        		visit[i] = false;
        	}
        }
    	private static void bfs(int size[], int ans, List[] list, int start, int end, Queue<Integer> q){
        	while(!q.isEmpty()){
        		int temp = q.remove();
        		visit[temp] = true;
        		for(int i=0;i<list[temp].size();i++){
        			if(!visit[(int)list[temp].get(i)] && end == (int)list[temp].get(i)){
        				parent[end] = temp;
        				visit[(int)list[temp].get(i)] = true;
        				return;
        			}
        			if(!visit[(int)list[temp].get(i)]){
        				q.add((int)list[temp].get(i));
        				parent[(int)list[temp].get(i)] = temp;
        			}
        		}
        	}
        }
        public static int dfs(List []list, int arr[], int k, int i, int ii){
            if(i==1 && arr[i]!=arr[ii]){
                return -1;
            }
            if(arr[i] == arr[ii]){
                k--;
                if(k==0){
                    return i;
                }
            }
            for(int j=0;j<list[i].size();j++){
                return dfs(list, arr, k, (int)list[i].get(j), ii);
            }
            return -1;
            }
            private static boolean isPerfectSquare(int n){
                if((int)Math.sqrt(n) * (int)Math.sqrt(n) == n){
                    return true;
                }
                return false;
            }
            private static Map<String, Boolean> map =  new HashMap<>();
            static{
                map.put("0 0 0", true);
            }
            private static boolean cany(int n, int nn, int t){
                if(map.containsKey((n)+" "+nn+" "+(t))){
                     return map.get((n)+" "+nn+" "+(t));
                }
                if(n>t || t<0 || n<0 || nn>t || nn<0 || nn+n>t || (nn == n && nn == t)){
                    map.put((n)+" "+nn+" "+(t), false);
                    return map.get((n)+" "+nn+" "+(t));
                }
                if(!map.containsKey((n-1)+" "+nn+" "+(t-1))){
                    map.put((n-1)+" "+nn+" "+(t-1), cany(n-1,nn, t-1));
                }
                if(!map.containsKey((n+1)+" "+nn+" "+(t-1))){
                    map.put((n+1)+" "+nn+" "+(t-1), cany(n+1,nn, t-1));
                }
                if(!map.containsKey(n+" "+(nn-1)+" "+(t-1))){
                    map.put(n+" "+(nn-1)+" "+(t-1), cany(n,nn-1, t-1));
                }
                if(!map.containsKey(n+" "+(nn+1)+" "+(t-1))){
                    map.put(n+" "+(nn+1)+" "+(t-1), cany(n,nn+1, t-1));
                }
                map.put(n+" "+nn+" "+t, map.get((n+1)+" "+nn+" "+(t-1)) || map.get((n-1)+" "+nn+" "+(t-1)) || map.get(n+" "+(nn-1)+" "+(t-1)) || map.get(n+" "+(nn+1)+" "+(t-1)));
                return map.get(n+" "+nn+" "+t);
            }
            
        private static int dp(int i, int k, int cnt, int arr[]){
            int start = arr[i];
            int ncnt = 0;
    	    for(int ii=i+1;ii<arr.length;ii++){
    	        if(Math.abs(start - arr[ii])<=k){
    	            sn("entered eith "+arr[ii]+" "+start+" "+k+" "+(k - Math.abs(start - arr[i])));
    	            ncnt = Math.max(cnt, dp(ii, k - Math.abs(start - arr[ii]), cnt +  1, arr));
    	        }
    	    }
    	    sn(cnt);
    	    return Math.max(ncnt, cnt);
        }
        private static int ans(int arr[] , int n, int len, int k){
            if(n==len-1 || k<0){
                return 1;
            }
            return Math.max(ans(arr, n+1, len, k), 1+ans(arr, n+1, len, k-arr[n]));
        }
        //change the length of string!!!!!!!!!!! in readLine()!!!!!!!!!!!!!!!
    	public static void main (String[] args) throws Exception{
    	    int t = 0;
    	    int x= 0;
    	    int y = 0;
    	    int n = ni();
    	    boolean flag;
    	    while(n-->0){
    	        int t1 = ni();
    	        int x1= ni();
    	        int y1=ni();
    	        if(t1-t >= Math.abs(x1-x)+Math.abs(y1 - y) && (Math.abs(x1-x)+Math.abs(y1 - y))%2 == (t1-t)%2){
    	            flag = true;
    	            t = t1;
    	            x=x1;
    	            y=y1;
    	        } else {
    	            flag = false;
    	            sn("No");
    	            return;
    	        }
    	        
    	    }
    	    sn("Yes");
    	}
    }