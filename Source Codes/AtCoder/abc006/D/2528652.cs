using System;
using System.Collections.Generic;
using System.Linq;

namespace atcoder{
    class prob{
        public static int Main(){
            var n = int.Parse(Console.ReadLine());
            var b = new bit(n);

            for(int i=0;i<n;i++){
                var c = int.Parse(Console.ReadLine());
                b.update(c, b.max(c-1)+1);
            }

            Console.WriteLine(n - b.max(n));

            return 0;
        }
    }

    class bit{
        public int[] data;
        public bit(int n){
            data = new int[n+1];
        }
        public int max(int x){
            int m = 0;
            while(x>0){
                m = Math.Max(m, data[x]);
                x -= x&-x;
            }
            return m;
        }
        public void update(int x, int m){
            while(x<data.Length){
                if(data[x]>=m)
                    break;
                data[x] = m;
                x += x&-x;
            }
        }
    }
}